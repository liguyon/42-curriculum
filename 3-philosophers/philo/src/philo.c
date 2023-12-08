/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:10:52 by liguyon           #+#    #+#             */
/*   Updated: 2023/12/08 23:37:29 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	*philo_routine(void *vargp)
{
	t_data	*data;
	t_philo	*philo;

	data = (t_data *)vargp;
	pthread_mutex_lock(&data->mutex_run);
	while (!data->is_running)
	{
		pthread_mutex_unlock(&data->mutex_run);
		usleep(1e3);
		pthread_mutex_lock(&data->mutex_run);
	}
	pthread_mutex_unlock(&data->mutex_run);
	philo = philo_get_from_tid(data, pthread_self());
	printf("hello from %d\n", philo->id);
	return (NULL);
}

t_philo	*philo_create(t_data *data, int id)
{
	t_philo	*ret;

	ret = calloc_log(1, sizeof(*ret));
	if (ret == NULL)
		return (NULL);
	ret->id = id;
	ret->state = state_think;
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
