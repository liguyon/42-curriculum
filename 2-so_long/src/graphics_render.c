/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_render.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:12:42 by liguyon           #+#    #+#             */
/*   Updated: 2023/10/07 12:47:18 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	graphics_clear(t_graphics *grph, t_color color)
{
	int	i;
	int	size;

	i = 0;
	size = CONF_WINDOW_HEIGHT * CONF_WINDOW_WIDTH;
	while (++i < size)
		grph->back_buffer->raster[i] = color;
}

static void	graphics_swap_framebuffers(t_graphics *grph)
{
	void	*tmp;

	tmp = grph->front_buffer;
	grph->front_buffer = grph->back_buffer;
	grph->back_buffer = tmp;
}

void	graphics_present(t_graphics *grph)
{
	graphics_swap_framebuffers(grph);
	mlx_put_image_to_window(
		grph->mlx_ptr,
		grph->win_ptr,
		grph->front_buffer->ptr,
		0,
		0);
}
