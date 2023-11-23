/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:34:02 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/23 16:21:03 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// draw_pixel(data, 0, 0, 0xFFFFFF);		- origin
// draw_pixel(data, -800, 450, 0xFFFFFF);	- top left
// draw_pixel(data, 799, 450, 0xFFFFFF);	- top right
// draw_pixel(data, -800, -449, 0xFFFFFF);	- bottom left
// draw_pixel(data, 799, -449, 0xFFFFFF);	- bottom right

void	render(t_data *data)
{
	int	i;
	int	j;
	t_vec4	tv;

	j = -1;
	while (++j < data->mesh->height)
	{
		i = -1;
		while (++i < data->mesh->width)
		{
			tv = vec4_create_from_vec3(data->mesh->vertices[j][i]);
			tv = mat4_mul_vec4(data->transform, tv);
			// if (tv.z > 0)
				draw_pixel(data, tv.x, tv.y, COLOR_WHITE);
		}
	}
}
