/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:44:00 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/24 01:37:11 by liguyon          ###   ########.fr       */
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
		data->mesh->r = vec3_add(data->mesh->r, (t_vec3){0, 1, 0});
	else if (keycode == XK_Left)
		data->mesh->r = vec3_sub(data->mesh->r, (t_vec3){0, 1, 0});
	else if (keycode == XK_Up)
		data->mesh->r = vec3_add(data->mesh->r, (t_vec3){0, 0, 1});
	else if (keycode == XK_Down)
		data->mesh->r = vec3_sub(data->mesh->r, (t_vec3){0, 0, 1});
	else if (keycode == XK_Page_Up)
		data->mesh->r = vec3_add(data->mesh->r, (t_vec3){1, 0, 0});
	else if (keycode == XK_Page_Down)
		data->mesh->r = vec3_sub(data->mesh->r, (t_vec3){1, 0, 0});
	else if (keycode == XK_w)
		data->mesh->t = vec3_sub(data->mesh->t, (t_vec3){0, 5, 0});
	else if (keycode == XK_s)
		data->mesh->t = vec3_add(data->mesh->t, (t_vec3){0, 5, 0});
	else if (keycode == XK_a)
		data->mesh->t = vec3_add(data->mesh->t, (t_vec3){5, 0, 0});
	else if (keycode == XK_d)
		data->mesh->t = vec3_sub(data->mesh->t, (t_vec3){5, 0, 0});
	return (EXIT_SUCCESS);
}

static int	inputs_process_structure(t_data *data)
{
	mlx_loop_end(data->grph->mlx_ptr);
	return (EXIT_SUCCESS);
}

static int	inputs_process_mouse(int keycode, int x, int y, t_data *data)
{
	if (keycode == 4)
		data->mesh->s = vec3_add(data->mesh->s, (t_vec3){0.5f, 0.5f, 0.5});
	else if (keycode == 5 && data->mesh->s.x > 0.5f)
		data->mesh->s = vec3_sub(data->mesh->s, (t_vec3){0.5f, 0.5f, 0.5});
	return (EXIT_SUCCESS);
}

void	inputs_bind(t_data *data)
{
	mlx_hook(data->grph->win_ptr, DestroyNotify, StructureNotifyMask,
		inputs_process_structure, data);
	mlx_hook(data->grph->win_ptr, KeyPress, KeyPressMask,
		inputs_process_keypress, data);
	mlx_hook(data->grph->win_ptr, ButtonPress, ButtonPressMask,
		inputs_process_mouse, data);
}
