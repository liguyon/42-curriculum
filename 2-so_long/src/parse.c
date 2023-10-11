/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:02:32 by liguyon           #+#    #+#             */
/*   Updated: 2023/10/11 08:57:11 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include <fcntl.h>

static bool	parse_file(const char *filename, char *buffer)
{
	t_stream	stream;

	stream = (t_stream){.fd = 0, .rd = 1, .ptr = buffer, .read_success = false};
	stream.fd = open(filename, O_RDONLY);
	if (stream.fd < 3)
		logger(LOGGER_CRIT, "could not open file '%s'", filename);
	else
	{
		while (stream.rd > 0)
		{
			stream.rd = read(stream.fd, stream.buf, PARSE_READ_SIZE);
			if (stream.rd == -1)
			{
				logger(LOGGER_CRIT, "error occured during call to read()");
				break ;
			}
			ft_memcpy(stream.ptr, stream.buf, stream.rd);
			stream.ptr += stream.rd;
		}
		if (stream.rd == 0)
			stream.read_success = true;
		close(stream.fd);
	}
	return (stream.read_success);
}

static bool	parse_map_dimensions(t_map *map)
{
	int	i;

	map->width = ft_strlen(map->map[0]);
	if (map->width * CONF_TILE_SIZE > CONF_WINDOW_WIDTH - 2 * CONF_TILE_SIZE
		|| map->height * CONF_TILE_SIZE > CONF_WINDOW_HEIGHT)
	{
		ft_printf("Error\nMap is too big\n");
		return (false);
	}
	i = -1;
	while (map->map[++i] != NULL)
	{
		map->height++;
		if ((int)ft_strlen(map->map[i]) != map->width)
		{
			ft_printf("Error\nInvalid map dimensions\n");
			return (false);
		}
	}
	return (true);
}

static bool	parse_map_walls(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->width)
	{
		if (map->map[0][i] != '1' || map->map[map->height - 1][i] != '1')
		{
			ft_printf("Error\nMap is not enclosed by walls\n");
			return (false);
		}
	}
	i = 0;
	while (++i < map->height - 1)
	{
		if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
		{
			ft_printf("Error\nMap is not enclosed by walls\n");
			return (false);
		}
	}
	return (true);
}

static bool	parse_map_components(t_map *map)
{
	int			i;
	int			j;
	t_map_comp	c;

	j = -1;
	c = (t_map_comp){0};
	while (map->map[++j] != NULL)
	{
		i = -1;
		while (map->map[j][++i] != '\0')
		{
			if (!in_charset(map->map[j][i], "01CEP"))
			{
				ft_printf("Error\nMap contains an invalid character\n");
				return (false);
			}
			else if (map->map[j][i] == '1')
				c.wall++;
			else if (map->map[j][i] == 'P')
				c.player++;
			else if (map->map[j][i] == 'C')
				c.collectible++;
			else if (map->map[j][i] == 'E')
				c.exit++;
		}
	}
	if (c.exit != 1 || c.player != 1 || c.wall < 1 || c.collectible < 1)
	{
		ft_printf("Error\nMap is not properly constructed\n");
		return (false);
	}
	return (true);
}

static bool	parse_map(t_map *map, char *buffer, const char *filename)
{
	if (ft_strlen(buffer) < 1)
	{
		ft_printf("Error\nMap is empty\n");
		return (false);
	}
	map->map = ft_split(buffer, '\n');
	if (map->map == NULL)
	{
		logger(LOGGER_CRIT, "error occured during call to ft_split()");
		return (false);
	}
	if (parse_map_dimensions(map) == false)
		return (false);
	if (parse_map_components(map) == false)
		return (false);
	if (parse_map_walls(map) == false)
		return (false);
	logger(LOGGER_INFO, "loaded map [file:'%s', dimensions:%dx%d]",
		filename, map->width, map->height);
	return (true);
}

bool	parse(t_map *map, const char *filename)
{
	char	*buffer;
	bool	ret;

	if (ft_strlen(filename) < 5
		|| ft_strncmp(".ber", &filename[ft_strlen(filename) - 4], 4) != 0)
	{
		ft_printf("Error\nInvalid file format\n");
		return (false);
	}
	buffer = calloc_log(1, (int)1e3 * PARSE_FILE_SIZE, __FILE__, __LINE__);
	if (!buffer)
		return (false);
	if (parse_file(filename, buffer) == false)
	{
		free(buffer);
		return (false);
	}
	ret = parse_map(map, buffer, filename);
	free(buffer);
	return (ret);
}
