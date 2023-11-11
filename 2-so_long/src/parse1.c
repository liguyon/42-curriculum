/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:32:48 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/11 14:54:28 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

bool	parse_map_dimensions(t_map *map)
{
	int	i;

	map->width = ft_strlen(map->map[0]);
	if (map->width * CONF_TILE_SIZE > CONF_GAME_WIDTH
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

bool	parse_map_walls(t_map *map)
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

bool	parse_map_components_aux(t_map *map, t_map_comp *c, int j)
{
	int	i;

	i = -1;
	while (map->map[j][++i] != '\0')
	{
		if (!in_charset(map->map[j][i], "01CEP"))
		{
			ft_printf("Error\nMap contains an invalid character\n");
			return (false);
		}
		else if (map->map[j][i] == '1')
			c->wall++;
		else if (map->map[j][i] == 'P')
			c->player++;
		else if (map->map[j][i] == 'C')
			c->collectible++;
		else if (map->map[j][i] == 'E')
			c->exit++;
	}
	return (true);
}

bool	parse_map_components(t_map *map)
{
	int			j;
	t_map_comp	c;

	j = -1;
	c = (t_map_comp){0};
	while (map->map[++j] != NULL)
	{
		if (parse_map_components_aux(map, &c, j) == false)
			return (false);
	}
	if (c.exit != 1 || c.player != 1 || c.wall < 1 || c.collectible < 1)
	{
		ft_printf("Error\nMap is not properly constructed\n");
		return (false);
	}
	map->collectibles = c.collectible;
	return (true);
}

bool	parse_map_path(t_map *map)
{
	int	i;
	int	j;

	j = -1;
	while (++j < map->height)
	{
		i = -1;
		while (++i < map->width)
		{
			if ()
		}
	}
}
