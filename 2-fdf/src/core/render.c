/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:34:02 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/28 16:00:01 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "mlx.h"
#include <math.h>

// draw_pixel(data, 0, 0, 0xFFFFFF);		- origin
// draw_pixel(data, -800, 450, 0xFFFFFF);	- top left
// draw_pixel(data, 799, 450, 0xFFFFFF);	- top right
// draw_pixel(data, -800, -449, 0xFFFFFF);	- bottom left
// draw_pixel(data, 799, -449, 0xFFFFFF);	- bottom right

void	render_text(t_data *data)
{
	char *rot_x = ft_itoa((int)data->mesh->r.x % 360);
	char *rot_y = ft_itoa((int)data->mesh->r.y % 360);
	char *rot_z = ft_itoa((int)data->mesh->r.z % 360);

	mlx_string_put(data->grph->mlx_ptr, data->grph->win_ptr,
		1420, 20, 0xffffff, "rotation");
	mlx_string_put(data->grph->mlx_ptr, data->grph->win_ptr,
		1420, 35, 0xffffff, rot_x);
	mlx_string_put(data->grph->mlx_ptr, data->grph->win_ptr,
		1420, 50, 0xffffff, rot_y);
	mlx_string_put(data->grph->mlx_ptr, data->grph->win_ptr,
		1420, 65, 0xffffff, rot_z);
	free(rot_x);
	free(rot_y);
	free(rot_z);
}

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
			t_color cn = color_interpolate_z(data->mesh->z_min, data->mesh->z_max, n.z);
			t_color cs = color_interpolate_z(data->mesh->z_min, data->mesh->z_max, s.z);
			t_color ce = color_interpolate_z(data->mesh->z_min, data->mesh->z_max, e.z);
			t_color co = color_interpolate_z(data->mesh->z_min, data->mesh->z_max, o.z);
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
	render_prop(data);

	draw_rect(data, (t_rect){.x=610, .y=-400, .width=20, .height=20}, COLOR_H0);
	draw_rect(data, (t_rect){.x=630, .y=-400, .width=20, .height=20}, COLOR_H1);
	draw_rect(data, (t_rect){.x=650, .y=-400, .width=20, .height=20}, COLOR_H2);
	draw_rect(data, (t_rect){.x=670, .y=-400, .width=20, .height=20}, COLOR_H3);
	draw_rect(data, (t_rect){.x=690, .y=-400, .width=20, .height=20}, COLOR_H4);
	draw_rect(data, (t_rect){.x=710, .y=-400, .width=20, .height=20}, COLOR_H5);
	draw_rect(data, (t_rect){.x=730, .y=-400, .width=20, .height=20}, COLOR_H6);
	draw_rect(data, (t_rect){.x=750, .y=-400, .width=20, .height=20}, COLOR_H7);
	draw_rect(data, (t_rect){.x=770, .y=-400, .width=20, .height=20}, COLOR_H8);

	// t_color c0 = 0xff0000;
	// t_color c1 = 0x0000ff;
	// t_color lerp_test;
	// lerp_test = color_lerp(c0, c1, 0.0f);
	// draw_rect(data, (t_rect){.x=0, .y=400, .width=20, .height=20}, lerp_test);
	// lerp_test = color_lerp(c0, c1, 0.1f);
	// draw_rect(data, (t_rect){.x=20, .y=400, .width=20, .height=20}, lerp_test);
	// lerp_test = color_lerp(c0, c1, 0.2f);
	// draw_rect(data, (t_rect){.x=40, .y=400, .width=20, .height=20}, lerp_test);
	// lerp_test = color_lerp(c0, c1, 0.3f);
	// draw_rect(data, (t_rect){.x=60, .y=400, .width=20, .height=20}, lerp_test);
	// lerp_test = color_lerp(c0, c1, 0.4f);
	// draw_rect(data, (t_rect){.x=80, .y=400, .width=20, .height=20}, lerp_test);
	// lerp_test = color_lerp(c0, c1, 0.5f);
	// draw_rect(data, (t_rect){.x=100, .y=400, .width=20, .height=20}, lerp_test);
	// lerp_test = color_lerp(c0, c1, 0.6f);
	// draw_rect(data, (t_rect){.x=120, .y=400, .width=20, .height=20}, lerp_test);
	// lerp_test = color_lerp(c0, c1, 0.7f);
	// draw_rect(data, (t_rect){.x=140, .y=400, .width=20, .height=20}, lerp_test);
	// lerp_test = color_lerp(c0, c1, 0.8f);
	// draw_rect(data, (t_rect){.x=160, .y=400, .width=20, .height=20}, lerp_test);
	// lerp_test = color_lerp(c0, c1, 0.9f);
	// draw_rect(data, (t_rect){.x=180, .y=400, .width=20, .height=20}, lerp_test);
	// lerp_test = color_lerp(c0, c1, 1.0f);
	// draw_rect(data, (t_rect){.x=200, .y=400, .width=20, .height=20}, lerp_test);

	// t_line line_test = {.x0=200, .y0=-200, .x1=100, .y1=200, .c0=COLOR_RED, .c1=COLOR_BLUE};
	// draw_line(data, line_test);
}
