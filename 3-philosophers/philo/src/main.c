/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:55:07 by liguyon           #+#    #+#             */
/*   Updated: 2023/12/09 08:45:14 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>

long long	get_time(void)
{
	struct timeval	now;
	long long		ret;

	gettimeofday(&now, NULL);
	ret = now.tv_sec * 1e3 + now.tv_usec / 1e3;
	return (ret);
}

int	load(t_data *data)
{
	int	i;

	data->philos = calloc_log(data->n_philo, sizeof(*data->philos));
	data->forks = calloc_log(data->n_philo, sizeof(*data->forks));
	if (data->philos == NULL || data->forks == NULL)
		return (EXIT_FAILURE);
	if (pthread_mutex_init(&data->mutex_run, NULL) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (pthread_mutex_init(&data->mutex_ate, NULL) != EXIT_SUCCESS)
	{
		pthread_mutex_destroy(&data->mutex_run);
		return (EXIT_FAILURE);
	}
	i = -1;
	while (++i < data->n_philo)
	{
		data->philos[i] = philo_create(data, i + 1);
		if (data->philos[i] == NULL)
			return (EXIT_FAILURE);
		data->forks[i] = fork_create();
		if (data->forks[i] == NULL)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	run(t_data *data)
{
	int	i;

	if (load(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	i = -1;
	while (++i < data->n_philo)
	{
		data->philos[i]->left = data->forks[i];
		if (i < data->n_philo - 1)
			data->philos[i]->right = data->forks[i + 1];
		else
			data->philos[i]->right = data->forks[0];
	}
	data->finished_eating = 0;
	data->time_start = get_time();
	pthread_mutex_lock(&data->mutex_run);
	data->is_running = true;
	pthread_mutex_unlock(&data->mutex_run);
	i = -1;
	while (++i < data->n_philo)
		pthread_join(data->philos[i]->tid, NULL);
	pthread_mutex_destroy(&data->mutex_run);
	pthread_mutex_destroy(&data->mutex_ate);
	return (EXIT_SUCCESS);
}

void	terminate(t_data *data)
{
	int	i;

	if (data->philos != NULL)
	{
		i = -1;
		while (++i < data->n_philo)
			philo_destroy(data->philos[i]);
		free(data->philos);
	}
	if (data->forks != NULL)
	{
		i = -1;
		while (++i < data->n_philo)
			fork_destroy(data->forks[i]);
		free(data->forks);
	}
	free(data);
}

int	main(int argc, char *argv[])
{
	t_data	*data;
	int		ret;

	if (argc != 5 && argc != 6)
	{
		printf("\nusage:\n\t./philo  number_of_philosophers  time_to_die " \
		" time_to_eat  time_to_sleep  " \
		"[number_of_times_each_philosopher_must_eat]\n\n");
		return (EXIT_FAILURE);
	}
	data = calloc_log(1, sizeof(*data));
	if (data == NULL)
		return (EXIT_FAILURE);
	if (parse_args(data, argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ret = run(data);
	terminate(data);
	return (ret);
}
