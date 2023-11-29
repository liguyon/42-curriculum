/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:22:11 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/29 08:24:59 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

static void	update_inputs(t_data *data)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(
		data->grph->mlx_ptr, data->grph->win_ptr, &x, &y);
	if (data->inputs->toggle_l == true)
	{
		data->mesh->t = vec3_add(data->mesh->t,
				(t_vec3){.x = x - data->inputs->last_x_l,
				.y = -(y - data->inputs->last_y_l), .z = 0});
		data->inputs->last_x_l = x;
		data->inputs->last_y_l = y;
	}
	else if (data->inputs->toggle_r == true)
	{
		data->mesh->r = vec3_add(data->mesh->r,
				(t_vec3){.x = -(y - data->inputs->last_y_r),
				.y = -(x - data->inputs->last_x_r), .z = 0.0f});
		data->inputs->last_x_r = x;
		data->inputs->last_y_r = y;
	}
}

// clamping s.z is necessary
// because we allow it to get below 0 in the inputs
void	update(t_data *data)
{
	t_mat4	scale;
	t_mat4	rotation_x;
	t_mat4	rotation_y;
	t_mat4	rotation_z;
	t_mat4	translation;

	update_inputs(data);
	if (data->mesh->s.z < 0.0f)
		data->mesh->s.z = 0.0f;
	scale = mat4_create_scale(data->mesh->s);
	rotation_x = mat4_create_rotation_x(radf(data->mesh->r.x));
	rotation_y = mat4_create_rotation_y(radf(data->mesh->r.y));
	rotation_z = mat4_create_rotation_z(radf(data->mesh->r.z));
	translation = mat4_create_translation(data->mesh->t);
	data->transform = scale;
	data->transform = mat4_mul(rotation_x, data->transform);
	data->transform = mat4_mul(rotation_y, data->transform);
	data->transform = mat4_mul(rotation_z, data->transform);
	data->transform = mat4_mul(translation, data->transform);
}
