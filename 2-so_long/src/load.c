/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:50:15 by liguyon           #+#    #+#             */
/*   Updated: 2023/10/27 17:34:39 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include "libft.h"

static void	load_player(t_data *data)
{
	t_player	*player;
	int			i;
	int			j;

	player = arena_alloc(data->arena, sizeof(*player));
	j = -1;
	while (++j < data->map->height)
	{
		i = -1;
		while (++i < data->map->width)
		{
			if (data->map->map[j][i] == MAP_PLAYER)
			{
				player->pos_x = i;
				player->pos_y = j;
				break ;
			}
		}
	}
	data->player = player;
}

bool	load(t_data *data, const char *map_filename)
{
	if (parse(data->map, map_filename) == false)
		return (false);
	data->map->x_offset = CONF_GAME_WIDTH / 2
		- data->map->width * CONF_TILE_SIZE / 2;
	data->map->y_offset = CONF_WINDOW_HEIGHT / 2
		- data->map->height * CONF_TILE_SIZE / 2;
	while (data->map->y_offset % CONF_TILE_SIZE != 0)
		data->map->y_offset--;
	while (data->map->x_offset % CONF_TILE_SIZE != 0)
		data->map->x_offset--;
	load_player(data);
	return (true);
}
