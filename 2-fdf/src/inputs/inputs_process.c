/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:04:28 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/29 14:05:32 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <X11/keysym.h>

static void	inputs_process_keypress_alt(int keycode, t_data *data)
{
	if (keycode == XK_Page_Up)
		data->mesh->s = vec3_add(data->mesh->s,
				(t_vec3){0.0f, 0.0f, data->conf->sf});
	else if (keycode == XK_Page_Down && data->mesh->s.z > 0.0f)
		data->mesh->s = vec3_sub(data->mesh->s,
				(t_vec3){0.0f, 0.0f, data->conf->sf});
	else if (keycode == XK_l)
	{
		if (data->inputs->lock_sz == false)
			data->inputs->lock_sz = true;
		else
			data->inputs->lock_sz = false;
	}
}

int	inputs_process_keypress(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		mlx_loop_end(data->grph->mlx_ptr);
	else if (keycode == XK_r)
		mesh_reset_transforms(data);
	else if (keycode == XK_p)
	{
		if (data->conf->proj == proj_iso)
			data->conf->proj = proj_ortho;
		else
			data->conf->proj = proj_iso;
		mesh_reset_transforms(data);
	}
	else if (keycode == XK_1)
		conf_load_palette(data, palette_1);
	else if (keycode == XK_2)
		conf_load_palette(data, palette_2);
	else if (keycode == XK_3)
		conf_load_palette(data, palette_3);
	else
		inputs_process_keypress_alt(keycode, data);
	return (EXIT_SUCCESS);
}

static void	inputs_process_mpress_alt(int keycode, t_data *data)
{
	float	sf;

	sf = data->conf->sf;
	if (keycode == MOUSE_SCROLL_UP)
	{
		if (data->inputs->lock_sz == false)
			data->mesh->s = vec3_add(data->mesh->s, (t_vec3){sf, sf, sf});
		else
			data->mesh->s = vec3_add(data->mesh->s, (t_vec3){sf, sf, 0.0f});
	}
	else if (keycode == MOUSE_SCROLL_DOWN && data->mesh->s.x > sf)
	{
		if (data->inputs->lock_sz == false)
			data->mesh->s = vec3_sub(data->mesh->s, (t_vec3){sf, sf, sf});
		else
			data->mesh->s = vec3_sub(data->mesh->s, (t_vec3){sf, sf, 0.0f});
	}
}

int	inputs_process_mpress(int keycode, int x, int y, t_data *data)
{
	if (keycode == MOUSE_LEFT && x < data->conf->vp_width)
	{
		data->inputs->toggle_r = false;
		data->inputs->toggle_l = true;
		data->inputs->last_x_l = x;
		data->inputs->last_y_l = y;
	}
	else if (keycode == MOUSE_RIGHT && x < data->conf->vp_width)
	{
		data->inputs->toggle_l = false;
		data->inputs->toggle_r = true;
		data->inputs->last_x_r = x;
		data->inputs->last_y_r = y;
	}
	else
		inputs_process_mpress_alt(keycode, data);
	return (EXIT_SUCCESS);
}

int	inputs_process_mrelease(int keycode, int x, int y, t_data *data)
{
	if (keycode == MOUSE_LEFT)
		data->inputs->toggle_l = false;
	else if (keycode == MOUSE_RIGHT)
		data->inputs->toggle_r = false;
	(void)x;
	(void)y;
	return (EXIT_SUCCESS);
}
