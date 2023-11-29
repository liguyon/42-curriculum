/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:09:43 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/29 11:11:29 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_line_alt2(t_data *data, t_line *line, t_bla *b)
{
	if (b->dx != 0)
		draw_pixel(data, line->x0, line->y0, color_lerp(line->c0, line->c1,
				absi(line->x0 - b->x0_cpy) / (float)b->dx));
	else
		draw_pixel(data, line->x0, line->y0, color_lerp(line->c0, line->c1,
				absi(line->y0 - b->y0_cpy) / (float)(-b->dy)));
}

static void	draw_line_alt(t_data *data, t_line *line, t_bla *b)
{
	while (1)
	{
		draw_line_alt2(data, line, b);
		if (line->x0 == line->x1 && line->y0 == line->y1)
			break ;
		b->e2 = 2 * b->error;
		if (b->e2 >= b->dy)
		{
			if (line->x0 == line->x1)
				break ;
			b->error += b->dy;
			line->x0 += b->sx;
		}
		if (b->e2 <= b->dx)
		{
			if (line->y0 == line->y1)
				break ;
			b->error += b->dx;
			line->y0 += b->sy;
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
	b.y0_cpy = line.y0;
	draw_line_alt(data, &line, &b);
}
