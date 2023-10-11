/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:44:36 by liguyon           #+#    #+#             */
/*   Updated: 2023/09/30 15:49:18 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <time.h>
#include "libft.h"

typedef struct timespec	t_timespec;

// Sleep for the specified number of milliseconds
void	timer_delay(int ms)
{
	struct timespec	ts;

	if (ms > 0)
	{
		ts.tv_sec = ms / 1e3;
		ts.tv_nsec = (ms % (int)1e3) * 1e6;
	}
	nanosleep(&ts, &ts);
}

void	timer_init(t_timer *timer)
{
	t_timespec	now;

	clock_gettime(CLOCK_MONOTONIC, &now);
	timer->time_start = now.tv_sec * 1e3 + now.tv_nsec / 1e6;
}

int	timer_get_ticks(t_timer *timer)
{
	t_timespec	now;
	int			now_ms;

	clock_gettime(CLOCK_MONOTONIC, &now);
	now_ms = now.tv_sec * 1e3 + now.tv_nsec / 1e6;
	return (now_ms - timer->time_start);
}
