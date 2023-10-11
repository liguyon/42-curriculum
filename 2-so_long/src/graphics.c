/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:15:21 by liguyon           #+#    #+#             */
/*   Updated: 2023/09/30 15:43:30 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "mlx.h"
#include <stdlib.h>

static bool	graphics_init_mlx(t_graphics *grph)
{
	grph->mlx_ptr = mlx_init();
	if (!grph->mlx_ptr)
	{
		logger(LOGGER_CRIT, "failed to initialize mlx instance");
		return (false);
	}
	grph->win_ptr = mlx_new_window(
			grph->mlx_ptr,
			CONF_WINDOW_WIDTH, CONF_WINDOW_HEIGHT, CONF_WINDOW_TITLE);
	if (!grph->win_ptr)
	{
		logger(LOGGER_CRIT, "failed to create mlx window");
		return (false);
	}
	return (true);
}

static t_mlx_image	*graphics_create_mlx_image(t_graphics *grph, void *arena)
{
	t_mlx_image	*img;

	img = arena_alloc(arena, sizeof(*img));
	img->ptr = mlx_new_image(
			grph->mlx_ptr, CONF_WINDOW_WIDTH, CONF_WINDOW_HEIGHT);
	if (!img->ptr)
	{
		logger(LOGGER_CRIT, "failed to create mlx image");
		return (NULL);
	}
	img->raster = (t_color *)mlx_get_data_addr(
			img->ptr, &img->bpp, &img->size_line, &img->endian);
	return (img);
}

static bool	graphics_init_framebuffers(t_graphics *grph, void *arena)
{
	grph->front_buffer = graphics_create_mlx_image(grph, arena);
	if (!grph->front_buffer)
		return (false);
	grph->back_buffer = graphics_create_mlx_image(grph, arena);
	if (!grph->back_buffer)
		return (false);
	return (true);
}

bool	graphics_init(t_data *data)
{
	t_graphics	*grph;

	grph = data->grph;
	if (graphics_init_mlx(grph) == false)
	{
		graphics_terminate(grph);
		return (false);
	}
	if (graphics_init_framebuffers(grph, data->arena) == false)
	{
		graphics_terminate(grph);
		return (false);
	}
	logger(LOGGER_INFO, "initialized graphics");
	return (true);
}

void	graphics_terminate(t_graphics *grph)
{
	if (grph->front_buffer)
		mlx_destroy_image(grph->mlx_ptr, grph->front_buffer->ptr);
	if (grph->back_buffer)
		mlx_destroy_image(grph->mlx_ptr, grph->back_buffer->ptr);
	if (grph->win_ptr)
		mlx_destroy_window(grph->mlx_ptr, grph->win_ptr);
	if (grph->mlx_ptr)
	{
		mlx_destroy_display(grph->mlx_ptr);
		free(grph->mlx_ptr);
	}
	logger(LOGGER_INFO, "terminated graphics");
}
