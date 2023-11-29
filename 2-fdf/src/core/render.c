/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:34:02 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/29 08:26:40 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	render_alt(t_data *data, int i, int j, t_vec4 vn)
{
	t_color	cn;
	t_vec4	ve;
	t_vec4	vo;
	t_color	ce;
	t_color	co;

	cn = color_distribute_z(data, vn.z);
	vn = mat4_mul_vec4(data->transform, vn);
	if (i < data->mesh->width - 1)
	{
		ve = vec4_create_from_vec3(data->mesh->vertices[j][i + 1]);
		ce = color_distribute_z(data, ve.z);
		ve = mat4_mul_vec4(data->transform, ve);
		draw_line(data, (t_line){(int)roundf(vn.x), (int)roundf(vn.y), cn,
			(int)roundf(ve.x), (int)roundf(ve.y), ce});
	}
	if (j < data->mesh->height - 1)
	{
		vo = vec4_create_from_vec3(data->mesh->vertices[j + 1][i]);
		co = color_distribute_z(data, vo.z);
		vo = mat4_mul_vec4(data->transform, vo);
		draw_line(data, (t_line){(int)roundf(vn.x), (int)roundf(vn.y), cn,
			(int)roundf(vo.x), (int)roundf(vo.y), co});
	}
}

// render pipeline
void	render(t_data *data)
{
	int		i;
	int		j;
	t_vec4	vn;

	j = -1;
	while (++j < data->mesh->height)
	{
		i = -1;
		while (++i < data->mesh->width)
		{
			vn = vec4_create_from_vec3(data->mesh->vertices[j][i]);
			render_alt(data, i, j, vn);
		}
	}
	render_ui(data);
}
