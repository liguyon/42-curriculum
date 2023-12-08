/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:55:21 by liguyon           #+#    #+#             */
/*   Updated: 2023/12/08 23:41:21 by liguyon          ###   ########.fr       */
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

enum
{
	state_eat,
	state_sleep,
	state_think,
	state_dead
};

typedef struct s_philo
{
	int			id;
	pthread_t	tid;
	int			state;
}	t_philo;

typedef struct s_fork
{
	pthread_mutex_t	mutex;
	bool			taken;
}	t_fork;

typedef struct s_data
{
	pthread_mutex_t	mutex_run;
	t_philo			**philos;
	t_fork			**forks;
	int				n_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				n_must_eat;
	bool			is_running;
}	t_data;

/*
================================================================================
	functions
================================================================================
*/

/* utils */
int		ft_isdigit(int c);
int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
void	*calloc_log(size_t nmemb, size_t size);

/* parse */
int		parse_args(t_data *data, int ac, char *av[]);

/* philo */
t_philo	*philo_create(t_data *data, int id);
void	philo_destroy(t_philo *philo);

/* fork */
t_fork	*fork_create(void);
void	fork_destroy(t_fork *fork);

/*
================================================================================
	log messages
================================================================================
*/

# define LOG_N_PHILO "there must be at least 1 philosopher\n"

#endif