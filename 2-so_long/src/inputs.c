/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:34:18 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/10 11:27:33 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>

static void	inputs_process_player(int keycode, t_data *data)
{
	if (keycode == XK_a)
		data->player->dir.x--;
	else if (keycode == XK_d)
		data->player->dir.x++;
	else if (keycode == XK_w)
		data->player->dir.y--;
	else if (keycode == XK_s)
		data->player->dir.y++;
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
