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

void	mutex_fault(t_philo *monitoring, int idx)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&monitoring->forks[i]);
	while (i < idx)
	{
		pthread_mutex_destroy(&monitoring->forks[i]);
		i++;
	}
	ft_clean_exit(monitoring, MUTEX);
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
