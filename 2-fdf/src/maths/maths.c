/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:55:27 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/28 14:08:30 by liguyon          ###   ########.fr       */
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

int	absi(int x)
{
	if (x > 0)
		return (x);
	else
		return (-x);
}

float	radf(float angle)
{
	return ((float)M_PI * angle / 180.0f);
}
