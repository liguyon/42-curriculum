/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:22:11 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/28 17:25:55 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

static void	update_inputs(t_data *data)
{
	int	x;
	int	y;

	if (data->inputs->toggle_l == true)
	{
		mlx_mouse_get_pos(
			data->grph->mlx_ptr, data->grph->win_ptr,
			&x, &y);
		data->mesh->t = vec3_add(
				data->mesh->t,
				(t_vec3){
				.x = x - data->inputs->last_x_l,
				.y = -(y - data->inputs->last_y_l), .z = 0});
		data->inputs->last_x_l = x;
		data->inputs->last_y_l = y;
	}
}

void	update(t_data *data)
{
	t_mat4	scale;
	t_mat4	rotation_x;
	t_mat4	rotation_y;
	t_mat4	rotation_z;
	t_mat4	translation;

	update_inputs(data);
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
