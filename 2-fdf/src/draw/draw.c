/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:52:06 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/29 11:11:41 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	draw_pixel(t_data *data, int x, int y, t_color c)
{
	int	sx;
	int	sy;

	sy = data->conf->window_height / 2 - y;
	sx = data->conf->window_width / 2 + x;
	if (sx >= 0 && sx < data->conf->window_width
		&& sy >= 0 && sy < data->conf->window_height)
		data->grph->back->raster[sy * data->conf->window_width + sx] = c;
}

void	draw_text(t_data *data, int x, int y, char *str)
{
	int	sx;
	int	sy;

	if (str != NULL)
	{
		sy = data->conf->window_height / 2 - y;
		sx = data->conf->window_width / 2 + x;
		if (sx >= 0 && sx < data->conf->window_width
			&& sy >= 0 && sy < data->conf->window_height)
			mlx_string_put(data->grph->mlx_ptr, data->grph->win_ptr,
				sx, sy, COLOR_WHITE, str);
	}
}

void	draw_rect(t_data *data, t_rect rect, t_color c)
{
	int	i;
	int	j;

	j = -1;
	while (++j < rect.height)
	{
		i = -1;
		while (++i < rect.width)
			draw_pixel(data, i + rect.x, j + rect.y, c);
	}
}
