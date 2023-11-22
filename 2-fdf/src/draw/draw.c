/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:52:06 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/21 15:03:39 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	draw_pixel(t_data *data, int x, int y, t_color c)
{
	int	sx;
	int	sy;

	sy = data->conf->window_height / 2 - y;
	sx = data->conf->window_width / 2 + x;
	if (sx >= 0 && sx < data->conf->window_width
		&& sy >= 0 && sy < data->conf->window_height)
		data->grph->back_buffer->raster[sy * data->conf->window_width + sx] = c;
}

// void	draw_rect(Data *data, Rect rect, Color c, int mode)
// {
// 	if (mode == DRAW_FILLED)
// 	{
// 		for (int j = 0 ; j < rect.height ; ++j)
// 		{
// 			for (int i = 0 ; i < rect.width ; ++i)
// 				draw_pixel(data, i + rect.x, j + rect.y, c);
// 		}
// 	}
// 	else if (mode == DRAW_BORDER)
// 	{
// 		for (int j = 0 ; j < rect.height ; ++j) 
// 		{
// 			draw_pixel(data, rect.x, j + rect.y, c);
// 			draw_pixel(data, rect.x + rect.width, j + rect.y, c);
// 		}
// 		for (int i = 0 ; i < rect.width ; ++i)
// 		{
// 			draw_pixel(data, i + rect.x, rect.y, c);
// 			draw_pixel(data, i + rect.x, rect.y + rect.height, c);
// 		}
// 	}
// }

static void	draw_line_alt(t_data *data, t_line line, t_bla b)
{
	float	e2;

	while (1)
	{
		draw_pixel(data, line.x0, line.y0, line.c0);
		if (line.x0 == line.x1 && line.y0 == line.y1)
			break ;
		e2 = 2 * b.error;
		if (e2 >= b.dy)
		{
			if (line.x0 == line.x1)
				break ;
			b.error += b.dy;
			line.x0 += b.sx;
		}
		if (e2 <= b.dx)
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

	b.dx = absf(line.x1 - line.x0);
	if (line.x0 < line.x1)
		b.sx = 1.0f;
	else
		b.sx = -2.0f;
	b.dy = -absf(line.y1 - line.y0);
	if (line.y0 < line.y1)
		b.sy = 1;
	else
		b.sy = -1;
	b.error = b.dx + b.dy;
	draw_line_alt(data, line, b);
}
