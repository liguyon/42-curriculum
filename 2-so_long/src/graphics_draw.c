/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_draw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:22:30 by liguyon           #+#    #+#             */
/*   Updated: 2023/10/27 19:32:13 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include "libft.h"
#include <math.h>

void	graphics_draw_pixel(t_graphics *grph, int x, int y, t_color color)
{
	if (x >= 0 && x < CONF_WINDOW_WIDTH && y >= 0 && y < CONF_WINDOW_HEIGHT)
		grph->back_buffer->raster[y * CONF_WINDOW_WIDTH + x] = color;
}

void	graphics_draw_rect(t_graphics *grph, t_rect rect, \
			t_color color, int border_size)
{
	int	i;
	int	j;

	j = -1;
	while (++j < rect.height)
	{
		i = -1;
		while (++i < rect.width)
		{
			if (j < border_size || j > rect.height - border_size - 1
				|| i < border_size || i > rect.width - border_size - 1)
				graphics_draw_pixel(grph, rect.x + i, rect.y + j, color);
		}
	}
}

void	graphics_draw_line(t_graphics *grph, t_pixel p0, t_pixel p1)
{
	t_dda	dda;

	dda = (t_dda){.delta_x = p1.x - p0.x, .delta_y = p1.y - p0.y, .i = -1};
	if (dda.delta_x == 0)
	{
		dda.side_length = absi(dda.delta_y);
		dda.y_inc = dda.delta_y / (float)dda.side_length;
	}
	else
	{
		if (dda.delta_x >= 0)
			dda.side_length = dda.delta_x;
		else
			dda.side_length = -dda.delta_x;
		dda.x_inc = dda.delta_x / (float)dda.side_length;
		dda.y_inc = dda.delta_y / (float)dda.side_length;
	}
	dda.current_x = p0.x;
	dda.current_y = p0.y;
	while (++dda.i <= dda.side_length)
	{
		graphics_draw_pixel(grph,
			(int)dda.current_x, (int)dda.current_y, p0.color);
		dda.current_x += dda.x_inc;
		dda.current_y += dda.y_inc;
	}
}

void	graphics_draw_triangle(t_graphics *grph, t_triangle t)
{
	graphics_draw_line(grph, t.p1, t.p2);
	graphics_draw_line(grph, t.p1, t.p3);
	graphics_draw_line(grph, t.p2, t.p3);
}

void	graphics_draw_circle(t_graphics *grph, t_circle c, t_color color)
{
	int	theta;

	theta = -1;
	while (++theta < 360)
	{
		graphics_draw_pixel(grph, c.x + c.radius * cosf(theta * M_PI / 180.0f),
			c.y + c.radius * sinf(theta * M_PI / 180.0f), color);
	}
}
