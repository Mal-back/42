/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_n_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:55:13 by purmerinos        #+#    #+#             */
/*   Updated: 2024/01/19 14:55:14 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

void	mutex_fault(t_philo *monitoring, int idx, int error)
{
	int	i;

	i = 0;
	if (pthread_mutex_destroy(&monitoring->writing))
		perror("Mutex destroy error");
	if (idx >= -2)
	{
		if (pthread_mutex_destroy(&monitoring->deadline_update))
			perror("Mutex destroy error");
	}
	if (idx >= -1)
	{
		if (pthread_mutex_destroy(&monitoring->meal_update))
			perror("Mutex destroy error");
	}
	while (i < idx)
	{
		if (pthread_mutex_destroy(&monitoring->forks[i]))
			perror("Mutex destroy error");
		i++;
	}
	ft_clean_exit(monitoring, error);
}

void	clean_threads(t_philo *monitoring, int idx, int error)
{
	int	i;

	i = 0;
	monitoring->sim_is_running = -1;
	while (i < idx)
	{
		if (pthread_join(monitoring->threads[i], NULL))
			perror("Thread join error");
		i++;
	}
	mutex_fault(monitoring, monitoring->philo_info[NUMBER], error);
}

void	ft_clean_exit(t_philo *monitoring, int code)
{
	if (monitoring->philo)
		free(monitoring->philo);
	if (monitoring->threads)
		free(monitoring->threads);
	if (monitoring->forks)
		free(monitoring->forks);
	exit(code);
}

void	display_help(t_philo *monitoring, int code)
{
	printf("Usage : ./philo [Numbers_of_philo] [time_to_die] [time_to_eat] \
[time_to_sleep]\n All values should be positive integers.\n");
	ft_clean_exit(monitoring, code);
}

void	solo(t_philo *monitoring)
{
	printf("[0ms] 1 has taken a fork\n");
	usleep(monitoring->philo_info[TIME_TO_DIE] * 1000);
	printf("[%dms] 1 died\n", monitoring->philo_info[TIME_TO_DIE] + 1);
}
