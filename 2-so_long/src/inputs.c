/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:34:18 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/07 05:43:37 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>

static void	inputs_process_player(int keycode, t_data *data)
{
	int	x;
	int	y;

	player_get_map_position(data, &x, &y);
	if (keycode == XK_a && data->map->map[y][x - 1] != MAP_WALL)
	{
		data->player->pos_x--;
		data->player->mvts++;
	}
	else if (keycode == XK_d && data->map->map[y][x + 1] != MAP_WALL)
	{
		data->player->pos_x++;
		data->player->mvts++;
	}
	else if (keycode == XK_w && data->map->map[y - 1][x] != MAP_WALL)
	{
		data->player->pos_y--;
		data->player->mvts++;
	}
	else if (keycode == XK_s & data->map->map[y + 1][x] != MAP_WALL)
	{
		data->player->pos_y++;
		data->player->mvts++;
	}
}

static int	inputs_process_keypress(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		mlx_loop_end(data->grph->mlx_ptr);
	else
		inputs_process_player(keycode, data);
	return (0);
}

static int	inputs_process_cross(t_graphics *grph)
{
	mlx_loop_end(grph->mlx_ptr);
	return (0);
}

void	inputs_bind(t_data *data)
{
	mlx_hook(data->grph->win_ptr, DestroyNotify, StructureNotifyMask,
		inputs_process_cross, data->grph);
	mlx_hook(data->grph->win_ptr, KeyPress, KeyPressMask,
		inputs_process_keypress, data);
	// mlx_hook(data->grph->win_ptr, KeyRelease, KeyReleaseMask,
	// 	inputs_process_keyrelease, data);
}
