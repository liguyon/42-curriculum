/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:38:25 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/23 23:33:50 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <time.h>

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

// get time (in ms) elapsed since start of the program
int	timer_get_ticks(t_timer *timer)
{
	t_timespec	now;
	int			now_ms;

	clock_gettime(CLOCK_MONOTONIC, &now);
	now_ms = now.tv_sec * 1e3 + now.tv_nsec / 1e6;
	return (now_ms - timer->time_start);
}

int	timer_init(t_data *data)
{
	t_timer		*timer;
	t_timespec	now;

	timer = calloc_log(1, sizeof(*timer));
	if (timer == NULL)
		return (EXIT_FAILURE);
	data->timer = timer;
	clock_gettime(CLOCK_MONOTONIC, &now);
	timer->time_start = now.tv_sec * 1e3 + now.tv_nsec / 1e6;
	logger(LOGGER_INFO, "initialized timer");
	return (EXIT_SUCCESS);
}

void	timer_destroy(t_data *data)
{
	if (data->timer != NULL)
	{
		free(data->timer);
		data->timer = NULL;
		logger(LOGGER_INFO, "destroyed timer");
	}
}
