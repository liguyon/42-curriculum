/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:52:06 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/28 18:54:39 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <math.h>

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

static void	draw_line_alt(t_data *data, t_line line, t_bla b)
{
	while (1)
	{
		draw_pixel(data, line.x0, line.y0, color_lerp(line.c0, line.c1,
				(float)absi(line.x0 - b.x0_cpy) / (float)b.dx));
		if (line.x0 == line.x1 && line.y0 == line.y1)
			break ;
		b.e2 = 2 * b.error;
		if (b.e2 >= b.dy)
		{
			if (line.x0 == line.x1)
				break ;
			b.error += b.dy;
			line.x0 += b.sx;
		}
		if (b.e2 <= b.dx)
		{
			if (line.y0 == line.y1)
				break ;
			b.error += b.dx;
			line.y0 += b.sy;
		}
	}
}

// Bresenham's line algorithm
void	draw_line(t_data *data, t_line line)
{
	t_bla	b;

	b.dx = absi(line.x1 - line.x0);
	if (line.x0 < line.x1)
		b.sx = 1;
	else
		b.sx = -1;
	b.dy = -absi(line.y1 - line.y0);
	if (line.y0 < line.y1)
		b.sy = 1;
	else
		b.sy = -1;
	b.error = b.dx + b.dy;
	b.x0_cpy = line.x0;
	draw_line_alt(data, line, b);
}
