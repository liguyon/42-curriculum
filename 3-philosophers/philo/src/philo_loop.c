/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 08:24:19 by liguyon           #+#    #+#             */
/*   Updated: 2023/12/09 12:30:07 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	philo_loop_end(t_data *data, t_philo *philo, long long time_now)
{
	bool	end;

	end = false;
	if (time_now > philo->time_last_eat + data->time_die)
	{
		philo->state = STATE_DEAD;
		return (true);
	}
	pthread_mutex_lock(&data->mutex_ate);
	if (data->finished_eating == data->n_philo)
		end = true;
	pthread_mutex_unlock(&data->mutex_ate);
	return (end);
}

void	philo_loop(t_data *data, t_philo *philo, long long *time_now)
{
	pthread_mutex_lock(&data->mutex_run);
	while (data->is_running)
	{
		*time_now = get_time();
		if (philo_loop_end(data, philo, *time_now))
			return ;
		pthread_mutex_unlock(&data->mutex_run);
		if (philo->state == STATE_THINK)
			philo_try_to_eat(data, philo, *time_now);
		else if (philo->state == STATE_EAT)
		{
			if (*time_now >= philo->time_last_eat + data->time_eat)
				philo_sleep(data, philo, *time_now);
		}
		else if (philo->state == STATE_SLEEP)
		{
			if (*time_now >= philo->time_start_sleep + data->time_sleep)
				philo_think(data, philo, *time_now);
		}
		usleep(TIMESTEP);
		pthread_mutex_lock(&data->mutex_run);
	}
}
