/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:27:30 by liguyon           #+#    #+#             */
/*   Updated: 2023/10/28 16:37:45 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_get_map_position(t_data *data, int *x, int *y)
{
	*x = (data->player->pos_x - data->map->x_offset) / CONF_TILE_SIZE;
	*y = (data->player->pos_y - data->map->y_offset) / CONF_TILE_SIZE;
}