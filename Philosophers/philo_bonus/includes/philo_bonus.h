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

#ifndef PHILO_BONUS_H

# define PHILO_BONUS_H

# include <pthread.h>
# include <bits/pthreadtypes.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <semaphore.h>
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

// boolean

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}						t_bool;

// error_codes

typedef enum e_error
{
	MALLOC = 1,
	SEMAPHORE = 2,
	PID = 3,
}						t_error;

// philo struct

typedef struct s_philo
{
	int		philo_info[5];
	pid_t	*pid;
	size_t	t_zero;
	size_t	deadline;
	int		who_am_i;
	int		meals;
	sem_t	*forks;
	sem_t	*start;
}								t_philo;

// help_n_error

void	display_help(t_philo *philo, int code);
void	ft_clean_exit(t_philo *philo, int code);
void	exit_routine(t_philo *philo, int idx);
void	kill_childrens(t_philo *philo, int idx);
void	solo(t_philo *monitoring);

// parsing

void	parse_av(char **av, t_philo *philo); // parse_av.c
void	launch_sim(t_philo *philo);

// utils

void	ft_usleep(size_t time, t_philo *philo); // utils.c
size_t	get_time(void); // utils.c
size_t	get_relative_time(size_t start); // utils.c
int		is_alive(t_philo *philo); // utils.c
void	write_template(t_philo *philo, char *str); // utils.c

#endif
