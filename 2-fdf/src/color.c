/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:45:50 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/28 19:58:48 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

t_color	color_interpolate_z(t_data *data, float z)
{
	float	frac;

	frac = (z - data->mesh->z_min) / (data->mesh->z_max - data->mesh->z_min);
	if (frac < 1.0f / 9.0f)
		return (data->conf->c_h0);
	else if (frac < 2.0f / 9.0f)
		return (data->conf->c_h1);
	else if (frac < 3.0f / 9.0f)
		return (data->conf->c_h2);
	else if (frac < 4.0f / 9.0f)
		return (data->conf->c_h3);
	else if (frac < 5.0f / 9.0f)
		return (data->conf->c_h4);
	else if (frac < 6.0f / 9.0f)
		return (data->conf->c_h5);
	else if (frac < 7.0f / 9.0f)
		return (data->conf->c_h6);
	else if (frac < 8.0f / 9.0f)
		return (data->conf->c_h7);
	else
		return (data->conf->c_h8);
}

t_color	color_lerp(t_color c0, t_color c1, float param)
{
	t_color	r;
	t_color	g;
	t_color	b;
	t_color	ret;

	if (param < 0.0f)
		param = 0.0f;
	else if (param > 1.0f)
		param = 1.0f;
	r = (1.0f - param) * (c0 & 0xff0000) + param * (c1 & 0xff0000);
	g = (1.0f - param) * (c0 & 0x00ff00) + param * (c1 & 0x00ff00);
	b = (1.0f - param) * (c0 & 0x0000ff) + param * (c1 & 0x0000ff);
	ret = (r & 0xff0000) | (g & 0x00ff00) | (b & 0x0000ff);
	return (ret);
}
