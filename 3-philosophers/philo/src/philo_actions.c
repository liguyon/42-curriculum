/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 06:43:33 by liguyon           #+#    #+#             */
/*   Updated: 2023/12/09 08:49:27 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

static void	philo_eat(t_data *data, t_philo *philo, long long time_now)
{
	pthread_mutex_lock(&philo->right->mutex);
	philo->right->taken = true;
	pthread_mutex_unlock(&philo->right->mutex);
	pthread_mutex_lock(&philo->left->mutex);
	philo->left->taken = true;
	pthread_mutex_unlock(&philo->left->mutex);
	philo->state = STATE_EAT;
	philo->time_last_eat = time_now;
	philo->count_eat++;
	if (philo->count_eat == data->n_must_eat)
	{
		pthread_mutex_lock(&data->mutex_ate);
		data->finished_eating++;
		pthread_mutex_unlock(&data->mutex_ate);
	}
	printf("%lld %d is eating\n",
		time_now - data->time_start, philo->id);
}

void	philo_try_to_eat(t_data *data, t_philo *philo, long long time_now)
{
	bool	left_taken;
	bool	right_taken;

	if (data->n_philo > 1)
	{
		pthread_mutex_lock(&philo->right->mutex);
		right_taken = philo->right->taken;
		pthread_mutex_unlock(&philo->right->mutex);
		pthread_mutex_lock(&philo->left->mutex);
		left_taken = philo->left->taken;
		pthread_mutex_unlock(&philo->left->mutex);
		if (!left_taken && !right_taken)
			philo_eat(data, philo, time_now);
	}
}

t_philo	*philo_get_from_tid(t_data *data, pthread_t tid)
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
