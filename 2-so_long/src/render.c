/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:50:52 by liguyon           #+#    #+#             */
/*   Updated: 2023/10/20 14:07:42 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

void	render_tile(t_data *data, char type, int x, int y)
{
	t_sprite	s;

	if (type == MAP_FLOOR)
	{
		s = (t_sprite){.atlas = data->atlases[ATLAS_TILES], .atlas_x = 48, .atlas_y = 48, .atlas_w = 16, .atlas_h = 16, .scale = 4};
		sprite_render(data, &s, x * CONF_TILE_SIZE, y * CONF_TILE_SIZE);
	}
	else if (type == MAP_WALL)
	{
		s = (t_sprite){.atlas = data->atlases[ATLAS_TILES], .atlas_x = 32, .atlas_y = 32, .atlas_w = 16, .atlas_h = 16, .scale = 4};
		sprite_render(data, &s, x * CONF_TILE_SIZE, y * CONF_TILE_SIZE);
	}
}

void	render_set(t_data *data)
{
	int	i;
	int	j;

	j = -1;
	while (++j < data->map->height)
	{
		i = -1;
		while (++i < data->map->width)
		{
			render_tile(data, data->map->map[j][i], i, j);
		}
	}
}

void	render(t_data *data)
{
	render_set(data);
}
