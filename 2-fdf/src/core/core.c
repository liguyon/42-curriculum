/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:42:40 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/23 17:00:21 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	update(t_data *data)
{
	t_mat4	scale;
	t_mat4	rotation_x;
	t_mat4	rotation_y;
	t_mat4	rotation_z;
	t_mat4	proj;

	data->mesh->scale = (t_vec3){20, 20, 20};
	data->mesh->rotation = (t_vec3){35.264f, 45.0f, -60.0f};
	scale = mat4_create_scale(data->mesh->scale);
	rotation_x = mat4_create_rotation_x(radf(data->mesh->rotation.x));
	rotation_y = mat4_create_rotation_y(radf(data->mesh->rotation.y));
	rotation_z = mat4_create_rotation_z(radf(data->mesh->rotation.z));
	data->transform = scale;
	data->transform = mat4_mul(rotation_y, data->transform);
	data->transform = mat4_mul(rotation_x, data->transform);
	data->transform = mat4_mul(rotation_z, data->transform);
	proj = (t_mat4){.m = {
		{1, 0, 0, 0},
		{0, 1, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 1}
	}};
	data->transform = mat4_mul(proj, data->transform);	
}

int	main_loop(t_data *data)
{
	static int	last_time = 0;
	int			time_to_wait;

	time_to_wait = 1e3 / data->conf->fps
		- (timer_get_ticks(data->timer) - last_time);
	if (time_to_wait > 0 && time_to_wait <= 1e3 / data->conf->fps)
		timer_delay(time_to_wait);
	last_time = timer_get_ticks(data->timer);
	update(data);
	graphics_clear(data, COLOR_BG);
	render(data);
	graphics_present(data);
	return (EXIT_SUCCESS);
}

int	run(t_data *data)
{
	if (conf_init(data) == EXIT_FAILURE
		|| graphics_init(data) == EXIT_FAILURE
		|| timer_init(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	inputs_bind(data);
	mlx_loop_hook(data->grph->mlx_ptr, main_loop, data);
	mlx_loop(data->grph->mlx_ptr);
	return (EXIT_SUCCESS);
}

void	terminate(t_data *data)
{
	mesh_destroy(data);
	conf_destroy(data);
	graphics_destroy(data);
	timer_destroy(data);
}
