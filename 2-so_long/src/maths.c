/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:16:53 by liguyon           #+#    #+#             */
/*   Updated: 2023/10/25 10:17:24 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
 * (int) Absolute value
*/
int	absi(int x)
{
	if (x >= 0)
		return (x);
	else
		return (-x);
}