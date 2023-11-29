/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:24:18 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/29 13:53:43 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
