/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:55:27 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/23 16:13:36 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

float	absf(float x)
{
	if (x > 0)
		return (x);
	else
		return (-x);
}

#ifndef M_PI
# define M_PI 3.14f
#endif
float	radf(float angle)
{
	return ((float)M_PI * angle / 180.0f);
}
