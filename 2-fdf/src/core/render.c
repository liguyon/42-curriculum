/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:34:02 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/28 19:59:23 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "mlx.h"
#include <math.h>

void	render(t_data *data)
{
	int	i;
	int	j;

	j = -1;
	while (++j < data->mesh->height - 1)
	{
		i = -1;
		while (++i < data->mesh->width - 1)
		{
			t_vec4 n = vec4_create_from_vec3(data->mesh->vertices[j][i]);
			t_vec4 s = vec4_create_from_vec3(data->mesh->vertices[j + 1][i + 1]);
			t_vec4 e = vec4_create_from_vec3(data->mesh->vertices[j][i + 1]);
			t_vec4 o = vec4_create_from_vec3(data->mesh->vertices[j + 1][i]);
			t_color cn = color_interpolate_z(data, n.z);
			t_color cs = color_interpolate_z(data, s.z);
			t_color ce = color_interpolate_z(data, e.z);
			t_color co = color_interpolate_z(data, o.z);
			n = mat4_mul_vec4(data->transform, n);
			s = mat4_mul_vec4(data->transform, s);
			e = mat4_mul_vec4(data->transform, e);
			o = mat4_mul_vec4(data->transform, o);
			t_line l;
			l = (t_line){
				.c0=cn,
				.c1=ce,
				.x0 = (int)roundf(n.x), .y0 = (int)roundf(n.y),
				.x1 = (int)roundf(e.x), .y1 = (int)roundf(e.y)};
			draw_line(data, l);
			l = (t_line){
				.c0=cn,
				.c1=co,
				.x0 = (int)roundf(n.x), .y0 = (int)roundf(n.y),
				.x1 = (int)roundf(o.x), .y1 = (int)roundf(o.y)};
			draw_line(data, l);
			l = (t_line){
				.c0=cs,
				.c1=ce,
				.x0 = (int)roundf(s.x), .y0 = (int)roundf(s.y),
				.x1 = (int)roundf(e.x), .y1 = (int)roundf(e.y)};
			draw_line(data, l);
			l = (t_line){
				.c0=cs,
				.c1=co,
				.x0 = (int)roundf(s.x), .y0 = (int)roundf(s.y),
				.x1 = (int)roundf(o.x), .y1 = (int)roundf(o.y)};
			draw_line(data, l);
		}
	}
	render_ui(data);
}
