/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:42:40 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/29 08:12:48 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "libft.h"

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
	render_ui_text(data);
	return (EXIT_SUCCESS);
}

// sf (scale factor) adjustment is super duper weird
// but works more or less on the maps we have
// basically, the higher z range is, the lesser sf will be
// meaning scaling z is more precise on maps with z range
int	load(t_data *data)
{
	int		i;
	float	range;

	data->strs = calloc_log(10, sizeof(*data->strs));
	if (data->strs == NULL)
		return (EXIT_FAILURE);
	range = data->mesh->z_max - data->mesh->z_min;
	i = -1;
	while (++i < 10)
	{
		data->strs[i] = ft_itoa(data->mesh->z_min + ((float)i / 9.0f) * range);
		if (data->strs[i] == NULL)
			return (EXIT_FAILURE);
	}
	data->conf->sf -= (data->mesh->z_max - data->mesh->z_min) * 0.00014f;
	if (data->conf->sf < 0.0f)
		data->conf->sf = 0.005f;
	return (EXIT_SUCCESS);
}

int	run(t_data *data, const char *filename)
{
	if (conf_init(data) == EXIT_FAILURE
		|| mesh_init(data, filename) == EXIT_FAILURE
		|| graphics_init(data) == EXIT_FAILURE
		|| timer_init(data) == EXIT_FAILURE
		|| inputs_init(data) == EXIT_FAILURE
		|| load(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	mlx_loop_hook(data->grph->mlx_ptr, main_loop, data);
	logger(LOGGER_INFO, "fdf running...");
	mlx_loop(data->grph->mlx_ptr);
	return (EXIT_SUCCESS);
}

void	terminate(t_data *data)
{
	int	i;

	conf_destroy(data);
	mesh_destroy(data);
	graphics_destroy(data);
	timer_destroy(data);
	inputs_destroy(data);
	if (data->strs != NULL)
	{
		i = -1;
		while (++i < 10)
		{
			if (data->strs[i] != NULL)
				free(data->strs[i]);
		}
		free(data->strs);
		data->strs = NULL;
	}
}
