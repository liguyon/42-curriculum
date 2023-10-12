/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:12:07 by liguyon           #+#    #+#             */
/*   Updated: 2023/10/12 07:22:13 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "mlx.h"
#include <stdlib.h>

// void	update(t_data *data, double dt)
// {
// 	data->sprite->pos_x += 0 * dt;
// }

int	main_loop(t_data *data)
{
	static int	last_time = 0;
	int			time_to_wait;
	double		dt;

	time_to_wait = 1e3 / CONF_FPS - (timer_get_ticks(data->timer) - last_time);
	if (time_to_wait > 0 && time_to_wait <= 1e3 / CONF_FPS)
		timer_delay(time_to_wait);
	last_time = timer_get_ticks(data->timer);
	dt = 1e3 / CONF_FPS;
	// update(data, dt);
	graphics_clear(data->grph, CONF_COLOR_BG);
	render(data);
	graphics_present(data->grph);
	return (0);
}

void	run(t_data *data, const char *map_filename)
{
	t_graphics	*grph;
	t_timer		timer;
	t_map		map;

	grph = arena_alloc(data->arena, sizeof(*grph));
	data->grph = grph;
	if (graphics_init(data) == false)
		return ;
	timer = (t_timer){0};
	data->timer = &timer;
	timer_init(data->timer);
	map = (t_map){0};
	data->map = &map;
	data->atlases = arena_alloc(data->arena, 1 * sizeof(*data->atlases));
	if (load(data, map_filename) == true)
	{
		inputs_bind(data);
		mlx_loop_hook(data->grph->mlx_ptr, main_loop, data);
		mlx_loop(data->grph->mlx_ptr);
	}
	graphics_terminate(data->grph);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_printf("\nusage: ./so_long path/to/file.ber\n\n");
		return (0);
	}
	(void)argv;
	data = (t_data){0};
	data.arena = arena_init(CONF_ARENA_SIZE);
	if (data.arena == NULL)
	{
		logger(LOGGER_CRIT, "failed to allocate memory");
		return (EXIT_FAILURE);
	}
	run(&data, argv[1]);
	arena_destroy(data.arena);
	return (0);
}
