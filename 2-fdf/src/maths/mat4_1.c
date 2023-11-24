/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:42:06 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/24 16:20:14 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

t_mat4	mat4_create_rotation_x(float angle)
{
	float	c;
	float	s;
	t_mat4	ret;

	c = cosf(angle);
	s = sinf(angle);
	ret = mat4_create_identity();
	ret.m[1][1] = c;
	ret.m[1][2] = s;
	ret.m[2][1] = -s;
	ret.m[2][2] = c;
	return (ret);
}

t_mat4	mat4_create_rotation_y(float angle)
{
	float	c;
	float	s;
	t_mat4	ret;

	c = cosf(angle);
	s = sinf(angle);
	ret = mat4_create_identity();
	ret.m[0][0] = c;
	ret.m[0][2] = -s;
	ret.m[2][0] = s;
	ret.m[2][2] = c;
	return (ret);
}

t_mat4	mat4_create_rotation_z(float angle)
{
	float	c;
	float	s;
	t_mat4	ret;

	c = cosf(angle);
	s = sinf(angle);
	ret = mat4_create_identity();
	ret.m[0][0] = c;
	ret.m[0][1] = s;
	ret.m[1][0] = -s;
	ret.m[1][1] = c;
	return (ret);
}
