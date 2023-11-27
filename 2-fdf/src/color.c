/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:45:50 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/27 18:48:13 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

// Returns the new color after applying intensity k
// e.g. k=2 means the new color is 2 times brighter
t_color	color_apply_intensity(t_color col, float k)
{
	t_color	a;
	t_color	r;
	t_color	g;
	t_color	b;
	t_color	ret;

	if (k < 0.0f)
	{
		logger(LOGGER_WARN, "color intensity factor must be positive");
		return (col);
	}
	a = col & 0xFF000000;
	r = (col & 0x00FF0000) * k;
	if (r > 0x00FF0000)
		r = 0x00FF0000;
	g = (col & 0x0000FF00) * k;
	if (g > 0x0000FF00)
		g = 0x0000FF00;
	b = (col & 0x000000FF) * k;
	if (b > 0x000000FF)
		b = 0x000000FF;
	ret = a | (r & 0x00FF0000) | (g & 0x0000FF00) | (b & 0x000000FF);
	return (ret);
}

t_color	color_lerp_z(float z_min, float z_max, float z)
{
	float	frac;

	frac = (z - z_min) / (z_max - z_min);
	if (frac < 1.0f / 9.0f)
		return (COLOR_H0);
	else if (frac < 2.0f / 9.0f)
		return (COLOR_H1);
	else if (frac < 3.0f / 9.0f)
		return (COLOR_H2);
	else if (frac < 4.0f / 9.0f)
		return (COLOR_H3);
	else if (frac < 5.0f / 9.0f)
		return (COLOR_H4);
	else if (frac < 6.0f / 9.0f)
		return (COLOR_H5);
	else if (frac < 7.0f / 9.0f)
		return (COLOR_H6);
	else if (frac < 8.0f / 9.0f)
		return (COLOR_H7);
	else
		return (COLOR_H8);
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
	r = (c0 & 0xff0000) + ((c1 & 0xff0000) - (c0 & 0xff0000)) * param;
	g = (c0 & 0x00ff00) + ((c1 & 0x00ff00) - (c0 & 0x00ff00)) * param;
	b = (c0 & 0x0000ff) + ((c1 & 0x0000ff) - (c0 & 0x0000ff)) * param;
	ret = (r & 0xff0000) | (g & 0x00ff00) | (b & 0x0000ff);
	return (ret);
}
