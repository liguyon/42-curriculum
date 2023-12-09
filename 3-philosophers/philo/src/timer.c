/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 00:13:34 by liguyon           #+#    #+#             */
/*   Updated: 2023/12/09 02:28:11 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>

long long	timer_get_time(void)
{
	struct timeval	now;
	long long		ret;

	gettimeofday(&now, NULL);
	ret = now.tv_sec * 1e3 + now.tv_usec / 1e3;
	return (ret);
}