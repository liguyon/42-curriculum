/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:42:40 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/21 16:21:43 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

int	main_loop(t_data *data)
{
	static int	last_time = 0;
	int			time_to_wait;

	time_to_wait = 1e3 / data->conf->fps
		- (timer_get_ticks(data->timer) - last_time);
	if (time_to_wait > 0 && time_to_wait <= 1e3 / data->conf->fps)
		timer_delay(time_to_wait);
	last_time = timer_get_ticks(data->timer);
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
