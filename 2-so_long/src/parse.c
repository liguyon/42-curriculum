/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:02:32 by liguyon           #+#    #+#             */
/*   Updated: 2023/10/21 11:17:14 by liguyon          ###   ########.fr       */
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

bool	cell_is_walkable(t_map *map, int x, int y)
{
	return (map->map[y][x] == '0'
		|| map->map[y][x] == 'C'
		|| map->map[y][x] == 'P');
}

// bool	parse_map_path(t_map *map)
// {
// 	int		i;
// 	int		j;
// 	int		reachable;
// 	char	**map_tmp;

// 	map_tmp = 
// 	reachable = 0;
// 	j = 0;
// 	while (++j < map->height)
// 	{
// 		i = 0;
// 		while (++i < map->width)
// 		{
// 			 if (map->map[j][i] == 'C' || map->map[j][i] == 'P' || map->map[j][i] == 'E')
// 			 {
// 				if ()
// 			 }
// 		}
// 	}
// 	return (true);
// }

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
	// if (parse_map_path(map) == false)
	// 	return (false);
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
