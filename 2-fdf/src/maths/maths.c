/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:55:27 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/29 14:40:02 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

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
