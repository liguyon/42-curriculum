/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:10:52 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/30 17:36:30 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thread_routine(void *vargp)
{
	printf("hello\n");
	(void)vargp;
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
	pthread_create(&ret->tid, NULL, thread_routine, data);
	return (ret);
}

void	philo_destroy(t_philo *philo)
{
	if (philo != NULL)
		free(philo);
}
