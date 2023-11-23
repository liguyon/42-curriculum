/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:42:40 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/23 21:53:01 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "libft.h"

void	update(t_data *data)
{
	t_mat4	scale;
	t_mat4	rotation_x;
	t_mat4	rotation_y;
	t_mat4	rotation_z;
	t_mat4	translation;

	scale = mat4_create_scale(data->mesh->scale);
	rotation_x = mat4_create_rotation_x(radf(data->mesh->rotation.x));
	rotation_y = mat4_create_rotation_y(radf(data->mesh->rotation.y));
	rotation_z = mat4_create_rotation_z(radf(data->mesh->rotation.z));
	translation = mat4_create_translation(data->mesh->translation);
	data->transform = scale;
	data->transform = mat4_mul(rotation_x, data->transform);
	data->transform = mat4_mul(rotation_y, data->transform);
	data->transform = mat4_mul(rotation_z, data->transform);
	data->transform = mat4_mul(translation, data->transform);
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
	mlx_clear_window(data->grph->mlx_ptr, data->grph->win_ptr);
	render(data);
	graphics_present(data);
	mlx_string_put(data->grph->mlx_ptr, data->grph->win_ptr, 20, 20, 0xffffff, "rotation");
	char *rot_x = ft_itoa((int)data->mesh->rotation.x);
	char *rot_y = ft_itoa((int)data->mesh->rotation.y);
	char *rot_z = ft_itoa((int)data->mesh->rotation.z);
	mlx_string_put(data->grph->mlx_ptr, data->grph->win_ptr, 20, 35, 0xffffff, rot_x);
	mlx_string_put(data->grph->mlx_ptr, data->grph->win_ptr, 20, 50, 0xffffff, rot_y);
	mlx_string_put(data->grph->mlx_ptr, data->grph->win_ptr, 20, 65, 0xffffff, rot_z);
	free(rot_x);
	free(rot_y);
	free(rot_z);
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
