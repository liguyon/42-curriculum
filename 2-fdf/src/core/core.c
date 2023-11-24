/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:42:40 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/24 00:29:52 by liguyon          ###   ########.fr       */
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
	mlx_string_put(data->grph->mlx_ptr, data->grph->win_ptr, 1420, 20, 0xffffff, "rotation");
	char *rot_x = ft_itoa((int)data->mesh->r.x % 360);
	char *rot_y = ft_itoa((int)data->mesh->r.y % 360);
	char *rot_z = ft_itoa((int)data->mesh->r.z % 360);
	mlx_string_put(data->grph->mlx_ptr, data->grph->win_ptr, 1420, 35, 0xffffff, rot_x);
	mlx_string_put(data->grph->mlx_ptr, data->grph->win_ptr, 1420, 50, 0xffffff, rot_y);
	mlx_string_put(data->grph->mlx_ptr, data->grph->win_ptr, 1420, 65, 0xffffff, rot_z);
	free(rot_x);
	free(rot_y);
	free(rot_z);
	return (EXIT_SUCCESS);
}

int	run(t_data *data, const char *filename)
{
	if (conf_init(data) == EXIT_FAILURE
		|| mesh_init(data, filename) == EXIT_FAILURE
		|| graphics_init(data) == EXIT_FAILURE
		|| timer_init(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	inputs_bind(data);
	mlx_loop_hook(data->grph->mlx_ptr, main_loop, data);
	logger(LOGGER_INFO, "fdf running...");
	mlx_loop(data->grph->mlx_ptr);
	return (EXIT_SUCCESS);
}

void	terminate(t_data *data)
{
	conf_destroy(data);
	mesh_destroy(data);
	graphics_destroy(data);
	timer_destroy(data);
}
