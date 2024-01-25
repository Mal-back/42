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
	pthread_mutex_destroy(&monitoring->writing);
	pthread_mutex_destroy(&monitoring->deadline_mut);
	pthread_mutex_destroy(&monitoring->sim_state);
	pthread_mutex_destroy(&monitoring->meals_mut);
	while (i < idx)
	{
		pthread_mutex_destroy(&monitoring->forks[i]);
		i++;
	}
	ft_clean_exit(monitoring, error);
}

void	clean_threads(t_philo *monitoring, int idx, int error)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&monitoring->sim_state);
	monitoring->sim_is_running = -1;
	pthread_mutex_unlock(&monitoring->sim_state);
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
