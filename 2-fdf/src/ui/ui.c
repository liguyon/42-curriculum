/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:59:07 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/28 20:03:22 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "libft.h"
#include <math.h>

static void	render_sidebar(t_data *data)
{
	int		padding;

	padding = 5;
	draw_rect(data, (t_rect){
		.x = data->conf->window_width / 2 - data->conf->prop_width,
		.y = -data->conf->window_height / 2 + padding + 1,
		.width = data->conf->prop_width - padding,
		.height = data->conf->window_height - padding * 2}, COLOR_PROP_BG);
}

static void	render_color_chart(t_data *data)
{
	t_conf	*c;

	c = data->conf;
	draw_rect(data, (t_rect){.x=620, .y=-420, .width=20, .height=20}, c->c_h0);
	draw_rect(data, (t_rect){.x=620, .y=-398, .width=20, .height=20}, c->c_h1);
	draw_rect(data, (t_rect){.x=620, .y=-376, .width=20, .height=20}, c->c_h2);
	draw_rect(data, (t_rect){.x=620, .y=-354, .width=20, .height=20}, c->c_h3);
	draw_rect(data, (t_rect){.x=620, .y=-332, .width=20, .height=20}, c->c_h4);
	draw_rect(data, (t_rect){.x=620, .y=-310, .width=20, .height=20}, c->c_h5);
	draw_rect(data, (t_rect){.x=620, .y=-288, .width=20, .height=20}, c->c_h6);
	draw_rect(data, (t_rect){.x=620, .y=-266, .width=20, .height=20}, c->c_h7);
	draw_rect(data, (t_rect){.x=620, .y=-244, .width=20, .height=20}, c->c_h8);
}

void	render_ui_text(t_data *data)
{
	int	i;

	draw_text(data, 670, 410, "Controls");
	draw_text(data, 664, 407, "__________");
	draw_text(data, 620, 380, "Mouse Left : Translate");
	draw_text(data, 620, 360, "Mouse Scroll : Zoom +/-");
	draw_text(data, 620, 340, "1, 2 : Change Color Palette");
	draw_text(data, 620, 320, "r : Reset Transformations");
	draw_text(data, 620, 300, "p : Change Projection");
	draw_text(data, 670, -210, "Elevation");
	draw_text(data, 664, -213, "___________");
	i = -1;
	while (++i < 9)
	{
		draw_text(data, 655, -415 + i * 22, data->strs[i]);
		draw_text(data, 680, -415 + i * 22, "-");
		draw_text(data, 700, -415 + i * 22, data->strs[i + 1]);
	}
}

void	render_ui(t_data *data)
{
	render_sidebar(data);
	render_color_chart(data);
}