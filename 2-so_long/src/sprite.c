/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:27:25 by liguyon           #+#    #+#             */
/*   Updated: 2023/10/21 13:10:38 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "mlx.h"

t_atlas	*atlas_load(t_data *data, char *filename)
{
	t_atlas	*atlas;
	t_mlx_image	img;

	img.ptr = mlx_xpm_file_to_image(
			data->grph->mlx_ptr, filename, &img.width, &img.height);
	if (img.ptr == NULL)
	{
		logger(LOGGER_CRIT, "failed to load '%s'", filename);
		return (NULL);
	}
	img.raster = (t_color *)mlx_get_data_addr(
			img.ptr, &img.bpp, &img.size_line, &img.endian);
	atlas = arena_alloc(data->arena, sizeof(*atlas));
	atlas->width = img.width;
	atlas->height = img.height;
	atlas->raster = arena_alloc(data->arena,
			atlas->width * atlas->height * sizeof(*atlas->raster));
	ft_memcpy(atlas->raster, img.raster,
		atlas->width * atlas->height * sizeof(*atlas->raster));
	mlx_destroy_image(data->grph->mlx_ptr, img.ptr);
	logger(LOGGER_INFO, "loaded atlas [file:'%s', dimensions:%dx%d]", filename, atlas->width, atlas->height);
	return (atlas);
}

// void	sprite_render(t_data *data, t_sprite *sprite, int x, int y)
// {
// 	int		i;
// 	int		j;
// 	t_rect	rect;
// 	t_color	color;

// 	j = -1;
// 	while (++j < sprite->atlas_h)
// 	{
// 		i = -1;
// 		while (++i < sprite->atlas_w)
// 		{
// 			color = sprite->atlas->raster[
// 				(j + sprite->atlas_y) * sprite->atlas->width + i + sprite->atlas_x];
// 			if (color == 0xFF00FF)
// 				continue ;
// 			rect.width = sprite->scale;
// 			rect.height = sprite->scale;
// 			rect.x = x + i * sprite->scale;
// 			rect.y = y + j * sprite->scale;
// 			graphics_draw_rect(data->grph, rect, color);
// 		}
// 	}
// }//
