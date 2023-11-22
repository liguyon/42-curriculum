/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:45:50 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/21 14:47:28 by liguyon          ###   ########.fr       */
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
