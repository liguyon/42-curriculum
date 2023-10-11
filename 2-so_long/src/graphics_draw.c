/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_draw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:22:30 by liguyon           #+#    #+#             */
/*   Updated: 2023/09/29 18:12:51 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include "libft.h"

void	graphics_draw_pixel(t_graphics *grph, int x, int y, t_color color)
{
	if (x >= 0 && x < CONF_WINDOW_WIDTH && y >= 0 && y < CONF_WINDOW_HEIGHT)
		grph->back_buffer->raster[y * CONF_WINDOW_WIDTH + x] = color;
}

void	graphics_draw_rect(t_graphics *grph, t_rect rect, t_color color)
{
	int	i;
	int	j;

	j = -1;
	while (++j < rect.height)
	{
		i = -1;
		while (++i < rect.width)
			graphics_draw_pixel(grph, rect.x + i, rect.y + j, color);
	}
}