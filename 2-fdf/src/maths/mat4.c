/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:44:00 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/24 16:41:53 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mat4	mat4_create_identity(void)
{
	t_mat4	ret;

	ret = (t_mat4){.m = {
	{1, 0, 0, 0},
	{0, 1, 0, 0},
	{0, 0, 1, 0},
	{0, 0, 0, 1}}};
	return (ret);
}

t_mat4	mat4_mul(t_mat4 a, t_mat4 b)
{
	t_mat4	ret;
	int		row;
	int		col;

	row = -1;
	while (++row < 4)
	{
		col = -1;
		while (++col < 4)
		{
			ret.m[row][col] = a.m[row][0] * b.m[0][col]
				+ a.m[row][1] * b.m[1][col]
				+ a.m[row][2] * b.m[2][col]
				+ a.m[row][3] * b.m[3][col];
		}
	}
	return (ret);
}

t_vec4	mat4_mul_vec4(t_mat4 m, t_vec4 v)
{
	t_vec4	ret;

	ret.x = m.m[0][0] * v.x + m.m[0][1]
		* v.y + m.m[0][2] * v.z + m.m[0][3] * v.w;
	ret.y = m.m[1][0] * v.x + m.m[1][1]
		* v.y + m.m[1][2] * v.z + m.m[1][3] * v.w;
	ret.z = m.m[2][0] * v.x + m.m[2][1]
		* v.y + m.m[2][2] * v.z + m.m[2][3] * v.w;
	ret.w = m.m[3][0] * v.x + m.m[3][1]
		* v.y + m.m[3][2] * v.z + m.m[3][3] * v.w;
	return (ret);
}

t_mat4	mat4_create_scale(t_vec3 scale)
{
	t_mat4	ret;

	ret = mat4_create_identity();
	ret.m[0][0] *= scale.x;
	ret.m[1][1] *= scale.y;
	ret.m[2][2] *= scale.z;
	return (ret);
}

t_mat4	mat4_create_translation(t_vec3 translation)
{
	t_mat4	ret;

	ret = mat4_create_identity();
	ret.m[0][3] = translation.x;
	ret.m[1][3] = translation.y;
	ret.m[2][3] = translation.z;
	return (ret);
}
