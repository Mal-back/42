/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:57:11 by purmerinos        #+#    #+#             */
/*   Updated: 2024/01/19 13:57:12 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

# include <pthread.h>
# include <bits/pthreadtypes.h>
# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

// for easy mangement of the philo_info array;

# define NUMBER 0
# define TIME_TO_DIE 1
# define TIME_TO_EAT 2
# define TIME_TO_SLEEP 3
# define SIM_LIMIT 4

typedef struct timeval	t_timeval;

// error_codes

typedef enum e_error
{
	MALLOC = 1,
	MUTEX = 2,
	THREAD = 3,
}						t_error;

// philo struct

typedef struct s_local_info
{
	int					*sim_is_running;
	int					*philo_info;
	int					number_of_meals;
	int					who_am_i;
	size_t				*start;
	size_t				deadline;	
	pthread_mutex_t		*my_fork;
	pthread_mutex_t		*other_fork;
	pthread_mutex_t		*writing;
	pthread_mutex_t		*deadline_mut;
	pthread_mutex_t		*meals_mut;
	pthread_mutex_t		*sim_state;
}							t_local_info;

// Main monitoring struct

typedef struct s_philo
{
	t_local_info		*philo;
	pthread_t			*threads;
	pthread_mutex_t		*forks;
	pthread_mutex_t		writing;
	pthread_mutex_t		sim_state;
	pthread_mutex_t		deadline_mut;
	pthread_mutex_t		meals_mut;
	size_t				start;
	int					philo_info[5];
	int					sim_is_running;
}								t_philo;

// help and exit fonctions in help_n_errors.c

void	display_help(t_philo *philo, int code);
void	mutex_fault(t_philo *monitoring, int idx, int code);
void	clean_threads(t_philo *monitoring, int idx, int error);
void	ft_clean_exit(t_philo *philo, int code);
void	solo(t_philo *monitoring);

// parsing

void	parse_av(char **av, t_philo *philo); // parse_av.c

// Routines

void	launch_simulation(t_philo *monitoring); // philo.c
void	*philo_routine(void *philo); // philo.c
void	*monitoring_routine(void *arg); // monitoring.c

// utils

size_t	get_time(void); // utils.c
size_t	get_relative_time(size_t start); // utils.c
void	ft_usleep(size_t time, t_local_info *monitoring); // utils.c
void	safe_write(t_local_info *philo, char *str); // utils.c
int		save_mutex_init(pthread_mutex_t *mutex); // utils.c
int		sim_is_running(t_local_info *philo); // utils2.c
void	lock_fork(t_local_info *philo); // utils2.c

#endif
