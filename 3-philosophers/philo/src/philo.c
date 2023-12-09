/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:10:52 by liguyon           #+#    #+#             */
/*   Updated: 2023/12/09 06:31:25 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// find a philo from its thread id
void	*philo_get_from_tid(t_data *data, pthread_t tid)
{
	int	i;

	i = -1;
	while (++i < data->n_philo)
	{
		if (data->philos[i]->tid == tid)
			return (data->philos[i]);
	}
	return (NULL);
}

void	philo_think(t_data *data, t_philo *philo, long long time_now)
{
	philo->state = STATE_THINK;
	printf("%lld %d is thinking\n",
		time_now - data->time_start, philo->id);
}

void	philo_sleep(t_data *data, t_philo *philo, long long time_now)
{
	pthread_mutex_lock(&philo->right->mutex);
	philo->right->taken = false;
	pthread_mutex_unlock(&philo->right->mutex);
	pthread_mutex_lock(&philo->left->mutex);
	philo->left->taken = false;
	pthread_mutex_unlock(&philo->left->mutex);
	philo->state = STATE_SLEEP;
	printf("%lld %d is sleeping\n",
		time_now - data->time_start, philo->id);
	philo->time_start_sleep = time_now;
}

void	philo_eat(t_data *data, t_philo *philo, long long time_now)
{
	if (data->n_philo > 1)
	{
		pthread_mutex_lock(&philo->right->mutex);
		if (!philo->right->taken)
		{
			pthread_mutex_lock(&philo->left->mutex);
			if (!philo->left->taken)
			{
				philo->right->taken = true;
				philo->left->taken = true;
				philo->state = STATE_EAT;
				philo->time_last_eat = time_now;
				philo->count_eat++;
				printf("%lld %d is eating\n",
					time_now - data->time_start, philo->id);
			}
			pthread_mutex_unlock(&philo->left->mutex);	
		}
		pthread_mutex_unlock(&philo->right->mutex);
	}
}

// thread routine
void	*philo_routine(void *vargp)
{
	t_data		*data;
	t_philo		*philo;
	long long	time_now;

	data = (t_data *)vargp;
	pthread_mutex_lock(&data->mutex_run);
	while (!data->is_running)
	{
		pthread_mutex_unlock(&data->mutex_run);
		usleep(1);
		pthread_mutex_lock(&data->mutex_run);
	}
	pthread_mutex_unlock(&data->mutex_run);
	philo = philo_get_from_tid(data, pthread_self());
	philo->time_last_eat = data->time_start;
	pthread_mutex_lock(&data->mutex_run);
	while (data->is_running)
	{
		time_now = timer_get_time();
		if (time_now > philo->time_last_eat + data->time_die)
			break ;
		pthread_mutex_unlock(&data->mutex_run);

		// update philo state
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
