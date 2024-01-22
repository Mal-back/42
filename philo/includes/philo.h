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
}						t_error;

// philo struct

typedef struct s_local_info
{
	int					*sim_is_running;
	int					*philo_info;
	int					number_of_meals;
	int					who_am_i;
	t_timeval			deadline;	
	pthread_mutex_t		*my_fork;
	pthread_mutex_t		*other_fork;
	pthread_mutex_t		*writing;
}							t_local_info;

typedef struct s_philo
{
	t_local_info		*philo;
	pthread_t			*threads;
	pthread_mutex_t		*forks;
	pthread_mutex_t		writing;
	int					philo_info[5];
	int					sim_is_running;
}								t_philo;

// help and exit fonctions

void	display_help(t_philo *philo, int code);
void	mutex_fault(t_philo *monitoring, int idx);
void	ft_clean_exit(t_philo *philo, int code);

// parsing

void	parse_av(char **av, t_philo *philo);

#endif
