/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:34:02 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/24 00:01:56 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include "mlx.h"
// draw_pixel(data, 0, 0, 0xFFFFFF);		- origin
// draw_pixel(data, -800, 450, 0xFFFFFF);	- top left
// draw_pixel(data, 799, 450, 0xFFFFFF);	- top right
// draw_pixel(data, -800, -449, 0xFFFFFF);	- bottom left
// draw_pixel(data, 799, -449, 0xFFFFFF);	- bottom right

static void	render_prop(t_data *data)
{
	int		padding;

	padding = 5;
	draw_rect(data, (t_rect){
		.x = data->conf->window_width / 2 - data->conf->prop_width,
		.y = -data->conf->window_height / 2 + padding + 1,
		.width = data->conf->prop_width - padding,
		.height = data->conf->window_height - padding * 2}, COLOR_PROP_BG);
}

void	render(t_data *data)
{
	int	i;
	int	j;
	t_vec4	n;

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
			n = mat4_mul_vec4(data->transform, n);
			s = mat4_mul_vec4(data->transform, s);
			e = mat4_mul_vec4(data->transform, e);
			o = mat4_mul_vec4(data->transform, o);
			t_line l = {.c0=COLOR_WHITE, .c1=COLOR_WHITE, .x0=n.x, .y0=n.y, .x1=e.x, .y1=e.y};
			draw_line(data, l);
			l = (t_line){.c0=COLOR_WHITE, .c1=COLOR_WHITE, .x0=n.x, .y0=n.y, .x1=o.x, .y1=o.y};
			draw_line(data, l);
			l = (t_line){.c0=COLOR_WHITE, .c1=COLOR_WHITE, .x0=s.x, .y0=s.y, .x1=e.x, .y1=e.y};
			draw_line(data, l);
			l = (t_line){.c0=COLOR_WHITE, .c1=COLOR_WHITE, .x0=s.x, .y0=s.y, .x1=o.x, .y1=o.y};
			draw_line(data, l);
		}
	}
	render_prop(data);
}
