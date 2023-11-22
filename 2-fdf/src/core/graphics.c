/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:22:05 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/21 15:33:19 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "libft.h"

static int	graphics_init_mlx(t_data *data)
{
	t_graphics	*grph;

	grph = data->grph;
	grph->mlx_ptr = mlx_init();
	if (grph->mlx_ptr == NULL)
	{
		logger(LOGGER_CRIT, "failed to initialize mlx instance");
		return (EXIT_FAILURE);
	}
	grph->win_ptr = mlx_new_window(
			grph->mlx_ptr,
			data->conf->window_width,
			data->conf->window_height,
			data->conf->window_title);
	if (grph->win_ptr == NULL)
	{
		logger(LOGGER_CRIT, "failed to create mlx window");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static t_mlx_image	*graphics_create_mlx_image(t_data *data)
{
	t_mlx_image	*img;

	img = calloc_log(1, sizeof(*img));
	if (img == NULL)
		return (NULL);
	img->ptr = mlx_new_image(
			data->grph->mlx_ptr,
			data->conf->window_width,
			data->conf->window_height);
	if (img->ptr == NULL)
	{
		logger(LOGGER_CRIT, "failed to create mlx image");
		return (NULL);
	}
	img->raster = (t_color *)mlx_get_data_addr(
			img->ptr, &img->bpp, &img->size_line, &img->endian);
	return (img);
}

// double buffering
// drawing is done on the back buffer
// front buffer is the raster that appears on screen
static int	graphics_init_framebuffers(t_data *data)
{
	t_graphics	*grph;

	grph = data->grph;
	grph->front_buffer = graphics_create_mlx_image(data);
	if (grph->front_buffer == NULL)
		return (EXIT_FAILURE);
	grph->back_buffer = graphics_create_mlx_image(data);
	if (grph->back_buffer == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	graphics_init(t_data *data)
{
	t_graphics	*grph;

	grph = calloc_log(1, sizeof(*grph));
	if (grph == NULL)
		return (EXIT_FAILURE);
	data->grph = grph;
	if (graphics_init_mlx(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (graphics_init_framebuffers(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	logger(LOGGER_INFO, "initialized graphics");
	return (EXIT_SUCCESS);
}

void	graphics_destroy(t_data *data)
{
	if (data->grph->front_buffer != NULL)
	{
		mlx_destroy_image(data->grph->mlx_ptr, data->grph->front_buffer->ptr);
		free(data->grph->front_buffer);
	}
	if (data->grph->back_buffer != NULL)
	{
		mlx_destroy_image(data->grph->mlx_ptr, data->grph->back_buffer->ptr);
		free(data->grph->back_buffer);
	}
	if (data->grph->win_ptr != NULL)
		mlx_destroy_window(data->grph->mlx_ptr, data->grph->win_ptr);
	if (data->grph->mlx_ptr != NULL)
	{
		mlx_destroy_display(data->grph->mlx_ptr);
		free(data->grph->mlx_ptr);
	}
	if (data->grph != NULL)
	{
		free(data->grph);
		data->grph = NULL;
		logger(LOGGER_INFO, "destroyed graphics");
	}
}
