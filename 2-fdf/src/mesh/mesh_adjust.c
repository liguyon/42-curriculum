/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh_adjust.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:31:55 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/29 14:32:21 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	adjust_get_max(t_data *data, t_adj *adj)
{
	t_vec4	v;
	int		i;
	int		j;

	j = -1;
	while (++j < data->mesh->height)
	{
		i = -1;
		while (++i < data->mesh->width)
		{
			v = vec4_create_from_vec3(data->mesh->vertices[j][i]);
			v = mat4_mul_vec4(data->transform, v);
			if ((int)v.y > adj->max_y)
			{
				adj->max_i = i;
				adj->max_j = j;
				adj->max_y = (int)v.y;
			}
		}
	}
}

void	mesh_adjust_sz(t_data *data)
{
	t_vec4	v;
	t_adj	adj;

	adj = (t_adj){0};
	adjust_get_max(data, &adj);
	v = vec4_create_from_vec3(data->mesh->vertices[adj.max_j][adj.max_i]);
	v = mat4_mul_vec4(data->transform, v);
	while (v.y > data->conf->window_height / 2)
	{
		data->mesh->s = vec3_sub(data->mesh->s, (t_vec3){0, 0, data->conf->sf});
		update(data);
		v = vec4_create_from_vec3(data->mesh->vertices[adj.max_j][adj.max_i]);
		v = mat4_mul_vec4(data->transform, v);
	}
	data->mesh->adjust_sz = false;
}
