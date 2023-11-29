/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:45:50 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/29 11:16:00 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

t_color	color_distribute_z(t_data *data, float z)
{
	float	frac;

	if (data->mesh->z_max == data->mesh->z_min)
		return (data->conf->col[8]);
	frac = (z - data->mesh->z_min) / (data->mesh->z_max - data->mesh->z_min);
	if (frac < 1.0f / 9.0f)
		return (data->conf->col[0]);
	else if (frac < 2.0f / 9.0f)
		return (data->conf->col[1]);
	else if (frac < 3.0f / 9.0f)
		return (data->conf->col[2]);
	else if (frac < 4.0f / 9.0f)
		return (data->conf->col[3]);
	else if (frac < 5.0f / 9.0f)
		return (data->conf->col[4]);
	else if (frac < 6.0f / 9.0f)
		return (data->conf->col[5]);
	else if (frac < 7.0f / 9.0f)
		return (data->conf->col[6]);
	else if (frac < 8.0f / 9.0f)
		return (data->conf->col[7]);
	else
		return (data->conf->col[8]);
}

t_color	color_lerp(t_color c0, t_color c1, float param)
{
	t_color	r;
	t_color	g;
	t_color	b;

	r = (1.0f - param) * (c0 & 0xff0000) + param * (c1 & 0xff0000);
	g = (1.0f - param) * (c0 & 0x00ff00) + param * (c1 & 0x00ff00);
	b = (1.0f - param) * (c0 & 0x0000ff) + param * (c1 & 0x0000ff);
	return ((r & 0xff0000) | (g & 0x00ff00) | (b & 0x0000ff));
}
