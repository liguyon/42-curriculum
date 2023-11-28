/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:04:28 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/28 17:32:01 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <X11/keysym.h>

int	inputs_process_keypress(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		mlx_loop_end(data->grph->mlx_ptr);
	else if (keycode == XK_r)
		mesh_reset_transforms(data);
	else if (keycode == XK_p)
	{
		if (data->inputs->proj == proj_iso)
			data->inputs->proj = proj_ortho;
		else
			data->inputs->proj = proj_iso;
		mesh_reset_transforms(data);
	}
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
	return (EXIT_SUCCESS);
}

int	inputs_process_structure(t_data *data)
{
	mlx_loop_end(data->grph->mlx_ptr);
	return (EXIT_SUCCESS);
}

int	inputs_process_mpress(int keycode, int x, int y, t_data *data)
{
	float	sf;

	sf = data->conf->scale_factor;
	if (keycode == MOUSE_SCROLL_UP)
		data->mesh->s = vec3_add(data->mesh->s, (t_vec3){sf, sf, sf});
	else if (keycode == MOUSE_SCROLL_DOWN && data->mesh->s.x > sf)
		data->mesh->s = vec3_sub(data->mesh->s, (t_vec3){sf, sf, sf});
	else if (keycode == MOUSE_LEFT)
	{
		data->inputs->toggle_l = true;
		data->inputs->last_x_l = x;
		data->inputs->last_y_l = y;
	}
	return (EXIT_SUCCESS);
}

int	inputs_process_mrelease(int keycode, int x, int y, t_data *data)
{
	if (keycode == MOUSE_LEFT)
		data->inputs->toggle_l = false;
	(void)x;
	(void)y;
}
