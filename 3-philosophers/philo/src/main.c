/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:55:07 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/30 17:41:13 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	run(t_data *data)
{
	int	i;

	data->philos = calloc_log(data->n_philo, sizeof(*data->philos));
	if (data->philos == NULL)
		return (EXIT_FAILURE);
	i = -1;
	while (++i < data->n_philo)
	{
		data->philos[i] = philo_create(data, i + 1);
		if (data->philos[i] == NULL)
			return (EXIT_FAILURE);
		pthread_join(data->philos[i]->tid, NULL);
	}
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
	free(data);
}

int	main(int argc, char *argv[])
{
	t_data	*data;
	int		ret;

	if (argc != 5 && argc != 6)
	{
		printf(LOG_USAGE);
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
