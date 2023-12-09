/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:55:21 by liguyon           #+#    #+#             */
/*   Updated: 2023/12/09 06:21:32 by liguyon          ###   ########.fr       */
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
# define ANSI_RESET "\e[0m"

# define TIMESTEP 1e2

enum
{
	STATE_EAT,
	STATE_SLEEP,
	STATE_THINK
};

typedef struct s_fork
{
	pthread_mutex_t	mutex;
	bool			taken;
}	t_fork;

typedef struct s_philo
{
	int			id;
	int			state;
	long long	time_last_eat;
	int			count_eat;
	long long	time_start_sleep;
	t_fork		*left;
	t_fork		*right;
	pthread_t	tid;
}	t_philo;


typedef struct s_data
{
	pthread_mutex_t	mutex_run;
	t_philo			**philos;
	t_fork			**forks;
	long long		time_start;
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

/* timer */
// get current time (since Unix Epoch) in milliseconds
long long	timer_get_time(void);

/*
================================================================================
	log messages
================================================================================
*/

# define LOG_N_PHILO "there must be at least 1 philosopher\n"

#endif