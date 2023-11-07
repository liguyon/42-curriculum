/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:50:52 by liguyon           #+#    #+#             */
/*   Updated: 2023/10/31 11:36:29 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

static void	render_exit(t_data *data, int x, int y)
{
	t_triangle	t;
	t_color		col;

	if (data->unlocked == false)
		col = COLOR_EXIT_OFF;
	else
		col = COLOR_EXIT_ON;
	t = (t_triangle){
		.p1 = (t_pixel){.color = col, .x = x + CONF_TILE_SIZE / 2, .y = y + 3},
		.p2 = (t_pixel){.color = col, .x = x + 4, .y = y + CONF_TILE_SIZE - 4},
		.p3 = (t_pixel){.color = col, .x = x + CONF_TILE_SIZE - 4,
		.y = y + CONF_TILE_SIZE - 4}
	};
	graphics_draw_triangle(data->grph, t);
	t = (t_triangle){
		.p1 = (t_pixel){.color = col, .x = x + CONF_TILE_SIZE / 2, .y = y + 4},
		.p2 = (t_pixel){.color = col, .x = x + 4, .y = y + CONF_TILE_SIZE - 4},
		.p3 = (t_pixel){.color = col, .x = x + CONF_TILE_SIZE - 4,
		.y = y + CONF_TILE_SIZE - 4}
	};
	graphics_draw_triangle(data->grph, t);
}

static void	render_set(t_data *data)
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
				graphics_draw_rect(data->grph,
					(t_rect){.width = CONF_TILE_SIZE - 1, .height = CONF_TILE_SIZE - 1, .x = i * CONF_TILE_SIZE + data->map->x_offset + 1, .y = j * CONF_TILE_SIZE + data->map->y_offset + 1},
					COLOR_WALL, 2);
			else if (data->map->map[j][i] == MAP_EXIT)
				render_exit(data, i * CONF_TILE_SIZE + data->map->x_offset, j
					* CONF_TILE_SIZE + data->map->y_offset);
			else if (data->map->map[j][i] == MAP_LOOT)
			{
				graphics_draw_rect(
					data->grph, (t_rect){.width = CONF_TILE_SIZE / 3, .height = CONF_TILE_SIZE / 3, .x = i * CONF_TILE_SIZE + data->map->x_offset + CONF_TILE_SIZE / 2 - CONF_TILE_SIZE / 6, .y = j * CONF_TILE_SIZE + data->map->y_offset + CONF_TILE_SIZE / 2 - CONF_TILE_SIZE / 6},
					COLOR_LOOT, 2);
			}
		}
	}
}

static void	render_grid(t_data *data)
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

static void	render_player(t_data *data)
{
	t_circle	c;

	c = (t_circle){.radius = CONF_TILE_SIZE / 2 - 2,
		.x = data->player->pos_x, .y = data->player->pos_y};
	graphics_draw_circle(data->grph, c, COLOR_PLAYER);
	c = (t_circle){.radius = CONF_TILE_SIZE / 2 - 1,
		.x = data->player->pos_x, .y = data->player->pos_y};
	graphics_draw_circle(data->grph, c, COLOR_PLAYER);
}

void	render(t_data *data)
{
	render_set(data);
	render_grid(data);
	render_player(data);
}
