/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:34:18 by liguyon           #+#    #+#             */
/*   Updated: 2023/10/03 17:01:58 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>

static void	inputs_process_player(int keycode, t_data *data)
{
	if (keycode == XK_a || keycode == XK_A)
		data->player->pos_x++;
	else if (keycode == XK_d || keycode == XK_D)
		data->player->pos_x--;
	else if (keycode == XK_w || keycode == XK_W)
		data->player->pos_y++;
	else if (keycode == XK_s || keycode == XK_S)
		data->player->pos_y--;
}

static int	inputs_process_keyboard(int keycode, t_data *data)
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
		inputs_process_keyboard, data);
}
