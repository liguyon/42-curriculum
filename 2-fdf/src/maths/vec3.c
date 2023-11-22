/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:24:18 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/21 19:26:32 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

t_vec3	vec3_add(t_vec3 v, t_vec3 w)
{
	t_vec3	ret;

	ret = (t_vec3){
		.x = v.x + w.x,
		.y = v.y + w.y,
		.z = v.z + w.z
	};
	return (ret);
}

t_vec3	vec3_sub(t_vec3 v, t_vec3 w)
{
	t_vec3	ret;

	ret = (t_vec3){
		.x = v.x - w.x,
		.y = v.y - w.y,
		.z = v.z - w.z
	};
	return (ret);
}

t_vec3	vec3_scale(t_vec3 v, float scalar)
{
	t_vec3	ret;

	ret = (t_vec3){
		.x = v.x * scalar,
		.y = v.y * scalar,
		.z = v.z * scalar
	};
	return (ret);
}

float	vec3_magnitude(t_vec3 v)
{
	return (sqrtf(v.x * v.x + v.y * v.y + v.z * v.z));
}

t_vec3	vec3_normalize(t_vec3 v)
{
	float	m;
	t_vec3	ret;

	if (v.x == 0 && v.y == 0 && v.z == 0)
		return (v);
	m = vec3_magnitude(v);
	ret = (t_vec3){
		.x = v.x / m,
		.y = v.y / m,
		.z = v.z / m
	};
	return (ret);
}
