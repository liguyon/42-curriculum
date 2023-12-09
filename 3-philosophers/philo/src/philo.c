/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:10:52 by liguyon           #+#    #+#             */
/*   Updated: 2023/12/09 08:52:50 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_wait_simulation_start(t_data *data)
{
	pthread_mutex_lock(&data->mutex_run);
	while (!data->is_running)
	{
		pthread_mutex_unlock(&data->mutex_run);
		usleep(TIMESTEP);
		pthread_mutex_lock(&data->mutex_run);
	}
	pthread_mutex_unlock(&data->mutex_run);
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
	philo_loop(data, philo, &time_now);
	if (data->is_running && philo->state == STATE_DEAD)
		printf("%lld %d died\n", time_now - data->time_start, philo->id);
	data->is_running = false;
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
	ret->count_eat = 0;
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
