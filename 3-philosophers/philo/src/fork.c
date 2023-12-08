/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 23:11:30 by liguyon           #+#    #+#             */
/*   Updated: 2023/12/08 23:11:50 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_fork	*fork_create(void)
{
	t_fork	*fork;

	fork = calloc_log(1, sizeof(*fork));
	if (fork == NULL)
		return (NULL);
	fork->taken = false;
	if (pthread_mutex_init(&fork->mutex, NULL) != EXIT_SUCCESS)
	{
		free(fork);
		return (NULL);
	}
	return (fork);
}

void	fork_destroy(t_fork *fork)
{
	if (fork != NULL)
	{
		pthread_mutex_destroy(&fork->mutex);
		free(fork);
	}
}
