/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:10:52 by liguyon           #+#    #+#             */
/*   Updated: 2023/12/09 06:59:34 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_wait_simulation_start(t_data *data)
{
	pthread_mutex_lock(&data->mutex_run);
	while (!data->is_running)
	{
		pthread_mutex_unlock(&data->mutex_run);
		usleep(1);
		pthread_mutex_lock(&data->mutex_run);
	}
	pthread_mutex_unlock(&data->mutex_run);
}

static long long	philo_simulate(t_data *data, t_philo *philo)
{
	long long	time_now;

	pthread_mutex_lock(&data->mutex_run);
	while (data->is_running)
	{
		time_now = get_time();
		if (time_now > philo->time_last_eat + data->time_die)
			return (time_now);
		pthread_mutex_unlock(&data->mutex_run);
		if (philo->state == STATE_THINK)
			philo_eat(data, philo, time_now);
		else if (philo->state == STATE_EAT)
		{
			if (time_now >= philo->time_last_eat + data->time_eat)
				philo_sleep(data, philo, time_now);
		}
		else if (philo->state == STATE_SLEEP)
		{
			if (time_now >= philo->time_start_sleep + data->time_sleep)
				philo_think(data, philo, time_now);
		}
		usleep(TIMESTEP);
		pthread_mutex_lock(&data->mutex_run);
	}
	return (time_now);
}

// thread routine
void	*philo_routine(void *vargp)
{
	t_data		*data;
	t_philo		*philo;
	long long	time_now;

	data = (t_data *)vargp;
	philo_wait_simulation_start(data);
	philo = philo_get_from_tid(data, pthread_self());
	philo->time_last_eat = data->time_start;
	time_now = philo_simulate(data, philo);
	if (data->is_running)
	{
		data->is_running = false;
		printf("%lld %d died\n", time_now - data->time_start, philo->id);
	}
	pthread_mutex_unlock(&data->mutex_run);
	return (NULL);
}

t_philo	*philo_create(t_data *data, int id)
{
	t_philo	*ret;

	ret = calloc_log(1, sizeof(*ret));
	if (ret == NULL)
		return (NULL);
	ret->id = id;
	ret->state = STATE_THINK;
	if (pthread_create(&ret->tid, NULL, philo_routine, data) != EXIT_SUCCESS)
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}

void	philo_destroy(t_philo *philo)
{
	if (philo != NULL)
		free(philo);
}
