/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:55:21 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/30 17:34:13 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <pthread.h>
# include <unistd.h>

# define ANSI_BRED "\e[1;31m"
# define ANSI_BGRN "\e[1;32m"
# define ANSI_BYEL "\e[1;33m"
# define ANSI_BBLU "\e[1;34m"
# define ANSI_BWHT "\e[1;37m"
# define ANSI_BMAG "\e[1;35m"
# define ANSI_RESET "\e[0m"

enum {state_eat, state_sleep, state_think, state_dead};

typedef struct s_philo {
	int			id;
	pthread_t	tid;
	int			state;
}	t_philo;

typedef struct s_data {
	int		n_philo;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int		n_must_eat;
	t_philo	**philos;
	bool	is_running;
}	t_data;

/*
================================================================================
	functions
================================================================================
*/

/* Utils */
int		ft_isdigit(int c);
int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
void	*calloc_log(size_t nmemb, size_t size);

/* Parse */
int		parse_args(t_data *data, int ac, char *av[]);

/* Philo */
t_philo	*philo_create(t_data *data, int id);
void	philo_destroy(t_philo *philo);

/*
================================================================================
	log messages
================================================================================
*/

# define LOG_USAGE "\nusage:\n\t./philo  number_of_philosophers  time_to_die " \
		" time_to_eat  time_to_sleep  " \
		"[number_of_times_each_philosopher_must_eat]\n\n"

# define LOG_N_PHILO "there must be at least 1 philosopher\n"

#endif