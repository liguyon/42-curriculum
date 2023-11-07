/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:12:07 by liguyon           #+#    #+#             */
/*   Updated: 2023/10/28 16:33:16 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "mlx.h"
#include <stdlib.h>

void	update(t_data *data, double dt)
{
	int	x;
	int	y;

	player_get_map_position(data, &x, &y);
	if (data->map->map[y][x] == MAP_LOOT)
	{
		data->player->collected++;
		data->map->map[y][x] = MAP_FLOOR;
	}
	if (data->unlocked == false)
	{
		if (data->player->collected == data->map->collectibles)
			data->unlocked = true;
	}
	(void)dt;
}

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
	update(data, dt);
	graphics_clear(data->grph, COLOR_BG);
	render(data);
	graphics_present(data->grph);
	mlx_string_put(data->grph->mlx_ptr, data->grph->win_ptr, CONF_GAME_WIDTH + CONF_TILE_SIZE, 800, 0xFFFFFF, "Controls");
	return (0);
}

void	run(t_data *data, const char *map_filename)
{
	int	j;

	data->grph = arena_alloc(data->arena, sizeof(*data->grph));
	if (graphics_init(data) == false)
		return ;
	data->timer = arena_alloc(data->arena, sizeof(*data->timer));
	timer_init(data->timer);
	data->map = arena_alloc(data->arena, sizeof(*data->map));
	if (load(data, map_filename) == true)
	{
		inputs_bind(data);
		mlx_loop_hook(data->grph->mlx_ptr, main_loop, data);
		mlx_loop(data->grph->mlx_ptr);
		j = -1;
		while (++j < data->map->height)
			free(data->map->map[j]);
		free(data->map->map);
	}
	graphics_terminate(data->grph);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	void	*arena;

	if (argc != 2)
	{
		ft_printf("\nusage: ./so_long path/to/file.ber\n\n");
		return (0);
	}
	arena = arena_init(CONF_ARENA_SIZE);
	if (arena == NULL)
	{
		logger(LOGGER_CRIT, "failed to allocate memory");
		return (EXIT_FAILURE);
	}
	data = arena_alloc(arena, sizeof(*data));
	data->arena = arena;
	run(data, argv[1]);
	arena_destroy(arena);
	return (0);
}
