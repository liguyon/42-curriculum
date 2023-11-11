/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:50:15 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/10 11:25:48 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include "libft.h"

static void	load_player(t_data *data)
{
	int			i;
	int			j;

	data->player = arena_alloc(data->arena, sizeof(*data->player));
	j = -1;
	while (++j < data->map->height)
	{
		i = -1;
		while (++i < data->map->width)
		{
			if (data->map->map[j][i] == MAP_PLAYER)
			{
				data->player->pos.x = i * CONF_TILE_SIZE
					+ data->map->offset.x + CONF_TILE_SIZE / 2;
				data->player->pos.y = j * CONF_TILE_SIZE
					+ data->map->offset.y + CONF_TILE_SIZE / 2;
				break ;
			}
		}
	}
}

bool	load(t_data *data, const char *map_filename)
{
	if (parse(data->map, map_filename) == false)
		return (false);
	data->map->offset.x = CONF_GAME_WIDTH / 2
		- data->map->width * CONF_TILE_SIZE / 2;
	data->map->offset.y = CONF_WINDOW_HEIGHT / 2
		- data->map->height * CONF_TILE_SIZE / 2;
	while ((int)data->map->offset.y % CONF_TILE_SIZE != 0)
		data->map->offset.y--;
	while ((int)data->map->offset.x % CONF_TILE_SIZE != 0)
		data->map->offset.x--;
	load_player(data);
	return (true);
}
