/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:50:52 by liguyon           #+#    #+#             */
/*   Updated: 2023/10/24 19:44:07 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

void	render_set(t_data *data)
{
	int	i;
	int	j;

	j = -1;
	while (++j < data->map->height)
	{
		i = -1;
		while (++i < data->map->width)
		{
			if (data->map->map[j][i] == MAP_WALL)
				graphics_draw_rect(
					data->grph,
					(t_rect){.width = CONF_TILE_SIZE - 1, .height = CONF_TILE_SIZE - 1, .x = i * CONF_TILE_SIZE + data->map->x_offset + 1, .y = j * CONF_TILE_SIZE + data->map->y_offset + 1},
					COLOR_WALL, 2);
			else if (data->map->map[j][i] == MAP_EXIT)
			{
				graphics_draw_rect(
					data->grph,
					(t_rect){.width = CONF_TILE_SIZE / 2, .height = 3 * CONF_TILE_SIZE / 4, .x = i * CONF_TILE_SIZE + data->map->x_offset + CONF_TILE_SIZE / 4, .y = j * CONF_TILE_SIZE + data->map->y_offset + CONF_TILE_SIZE / 8},
					COLOR_EXIT_OFF, 2);
			}
			else if (data->map->map[j][i] == MAP_LOOT)
			{
				graphics_draw_rect(
					data->grph,
					(t_rect){.width = CONF_TILE_SIZE / 3, .height = CONF_TILE_SIZE / 3, .x = i * CONF_TILE_SIZE + data->map->x_offset + CONF_TILE_SIZE / 2 - CONF_TILE_SIZE / 6, .y = j * CONF_TILE_SIZE + data->map->y_offset + CONF_TILE_SIZE / 2 - CONF_TILE_SIZE / 6},
					COLOR_LOOT, 2);
			}
		}
	}
}

void	render_grid(t_data *data)
{
	int	i;
	int	j;

	j = -1;
	while (++j < CONF_WINDOW_HEIGHT)
	{
		i = -1;
		while (++i < CONF_WINDOW_WIDTH)
		{
			if ((i % CONF_TILE_SIZE == 0 || j % CONF_TILE_SIZE == 0)
				&& i <= CONF_GAME_WIDTH)
				graphics_draw_pixel(data->grph, i, j, COLOR_GRID);
		}
	}
}

void	render_player(t_data *data)
{
	graphics_draw_rect(
		data->grph,
			(t_rect){.width = CONF_TILE_SIZE - 1, .height = CONF_TILE_SIZE - 1, .x = data->player->pos_x, .y = data->player->pos_y + 1},
			COLOR_PLAYER, 2);
}

void	render(t_data *data)
{
	render_set(data);
	render_grid(data);
	render_player(data);
}
