/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:44:00 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/23 20:27:37 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>

static int	inputs_process_keypress(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		mlx_loop_end(data->grph->mlx_ptr);
	else if (keycode == XK_Right)
		data->mesh->rotation = vec3_add(data->mesh->rotation, (t_vec3){0, 1, 0});
	else if (keycode == XK_Left)
		data->mesh->rotation = vec3_sub(data->mesh->rotation, (t_vec3){0, 1, 0});
	else if (keycode == XK_Up)
		data->mesh->rotation = vec3_add(data->mesh->rotation, (t_vec3){0, 0, 1});
	else if (keycode == XK_Down)
		data->mesh->rotation = vec3_sub(data->mesh->rotation, (t_vec3){0, 0, 1});
	return (EXIT_SUCCESS);
}

static int	inputs_process_structure(t_graphics *grph)
{
	mlx_loop_end(grph->mlx_ptr);
	return (EXIT_SUCCESS);
}

void	inputs_bind(t_data *data)
{
	mlx_hook(data->grph->win_ptr, DestroyNotify, StructureNotifyMask,
		inputs_process_structure, data->grph);
	mlx_hook(data->grph->win_ptr, KeyPress, KeyPressMask,
		inputs_process_keypress, data);
}
