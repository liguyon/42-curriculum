/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:27:25 by liguyon           #+#    #+#             */
/*   Updated: 2023/10/11 06:54:35 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "mlx.h"

t_sprite	*sprite_load(t_data *data, char *filename)
{
	t_sprite	*sprite;
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
	sprite = arena_alloc(data->arena, sizeof(*sprite));
	sprite->width = img.width;
	sprite->height = img.height;
	sprite->scale = 1;
	sprite->raster = arena_alloc(data->arena,
			sprite->width * sprite->height * sizeof(*sprite->raster));
	ft_memcpy(sprite->raster, img.raster,
		sprite->width * sprite->height * sizeof(*sprite->raster));
	mlx_destroy_image(data->grph->mlx_ptr, img.ptr);
	logger(LOGGER_INFO, "loaded '%s'", filename);
	return (sprite);
}

void	sprite_render(t_data *data, t_sprite *sprite, int x, int y)
{
	int		i;
	int		j;
	t_rect	rect;
	t_color	color;

	j = -1;
	while (++j < sprite->height)
	{
		i = -1;
		while (++i < sprite->width)
		{
			color = sprite->raster[j * sprite->width + i];
			if (color == 0xFF00FF)
				continue ;
			rect.width = sprite->scale;
			rect.height = sprite->scale;
			rect.x = x + i * sprite->scale;
			rect.y = y + j * sprite->scale;
			graphics_draw_rect(data->grph, rect, color);
		}
	}
}
