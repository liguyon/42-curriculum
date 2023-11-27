/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:34:02 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/27 18:39:13 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "mlx.h"

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
			t_color cn = color_lerp_z(data->mesh->z_min, data->mesh->z_max, n.z);
			t_color cs = color_lerp_z(data->mesh->z_min, data->mesh->z_max, s.z);
			t_color ce = color_lerp_z(data->mesh->z_min, data->mesh->z_max, e.z);
			t_color co = color_lerp_z(data->mesh->z_min, data->mesh->z_max, o.z);
			n = mat4_mul_vec4(data->transform, n);
			s = mat4_mul_vec4(data->transform, s);
			e = mat4_mul_vec4(data->transform, e);
			o = mat4_mul_vec4(data->transform, o);
			t_line l = {
				.c0=cn,
				.c1=ce,
				.x0=n.x, .y0=n.y, .x1=e.x, .y1=e.y};
			draw_line(data, l);
			l = (t_line){
				.c0=cn,
				.c1=co,
				.x0=n.x, .y0=n.y, .x1=o.x, .y1=o.y};
			draw_line(data, l);
			l = (t_line){
				.c0=cs,
				.c1=ce,
				.x0=s.x, .y0=s.y, .x1=e.x, .y1=e.y};
			draw_line(data, l);
			l = (t_line){
				.c0=cs,
				.c1=co,
				.x0=s.x, .y0=s.y, .x1=o.x, .y1=o.y};
			draw_line(data, l);
		}
	}
	render_prop(data);

	draw_rect(data, (t_rect){.x=0, .y=300, .width=20, .height=20}, COLOR_H0);
	draw_rect(data, (t_rect){.x=20, .y=300, .width=20, .height=20}, COLOR_H1);
	draw_rect(data, (t_rect){.x=40, .y=300, .width=20, .height=20}, COLOR_H2);
	draw_rect(data, (t_rect){.x=60, .y=300, .width=20, .height=20}, COLOR_H3);
	draw_rect(data, (t_rect){.x=80, .y=300, .width=20, .height=20}, COLOR_H4);
	draw_rect(data, (t_rect){.x=100, .y=300, .width=20, .height=20}, COLOR_H5);
	draw_rect(data, (t_rect){.x=120, .y=300, .width=20, .height=20}, COLOR_H6);
	draw_rect(data, (t_rect){.x=140, .y=300, .width=20, .height=20}, COLOR_H7);
	draw_rect(data, (t_rect){.x=160, .y=300, .width=20, .height=20}, COLOR_H8);

	t_color lerp_test = color_lerp(0xff0000, 0x00ff00, 0.5f);
	draw_rect(data, (t_rect){.x=160, .y=400, .width=20, .height=20}, lerp_test);

}
