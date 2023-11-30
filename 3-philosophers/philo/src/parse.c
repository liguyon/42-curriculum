/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:01:23 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/30 16:49:59 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <limits.h>

static int	check_int(char *str)
{
	int		i;
	int		j;
	long	nbr;

	if (!(ft_isdigit(str[0]) || str[0] == '+'))
		return (EXIT_FAILURE);
	i = 0;
	if (str[i] == '+')
		i++;
	while (str[i] == '0')
		i++;
	j = 0;
	while (str[j + i])
	{
		if (!ft_isdigit(str[j + i]))
			return (EXIT_FAILURE);
		j++;
	}
	if (j > 11)
		return (EXIT_FAILURE);
	nbr = ft_atol(str);
	if (!(nbr >= INT_MIN && nbr <= INT_MAX))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	parse_args(t_data *data, int ac, char *av[])
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (check_int(av[i]) == EXIT_FAILURE)
		{
			printf(ANSI_BRED "[ERROR] " ANSI_RESET "invalid arguments\n");
			return (EXIT_FAILURE);
		}
	}
	data->n_philo = ft_atoi(av[1]);
	if (data->n_philo == 0)
	{
		printf(ANSI_BRED "[ERROR] " ANSI_RESET LOG_N_PHILO);
		return (EXIT_FAILURE);
	}
	data->time_die = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->n_must_eat = ft_atoi(av[5]);
	else
		data->n_must_eat = -1;
	return (EXIT_SUCCESS);
}
