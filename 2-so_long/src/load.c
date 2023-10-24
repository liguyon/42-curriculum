/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:50:15 by liguyon           #+#    #+#             */
/*   Updated: 2023/10/24 19:45:36 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include "libft.h"

bool	load(t_data *data, const char *map_filename)
{
	t_player	*player;

	if (parse(data->map, map_filename) == false)
		return (false);
	data->map->x_offset = CONF_GAME_WIDTH/ 2 - data->map->width * CONF_TILE_SIZE / 2;
	data->map->y_offset = CONF_WINDOW_HEIGHT / 2 - data->map->height * CONF_TILE_SIZE / 2;
	while (data->map->y_offset % CONF_TILE_SIZE != 0)
		data->map->y_offset--;
	while (data->map->x_offset % CONF_TILE_SIZE != 0)
		data->map->x_offset--;
	player = arena_alloc(data->arena, sizeof(*player));
	for (int j = 0; j < data->map->height; j++)
	{
		for (int i = 0; i < data->map->width; i++)
		{
			if (data->map->map[j][i] == MAP_PLAYER)
			{
				player->pos_x = i * CONF_TILE_SIZE + data->map->x_offset;
				player->pos_y = j * CONF_TILE_SIZE + data->map->y_offset;
			}
		}
	}
	data->player = player;
	return (true);
}
