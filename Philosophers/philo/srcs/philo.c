/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:38:05 by purmerinos        #+#    #+#             */
/*   Updated: 2024/01/19 17:38:05 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdlib.h>

static void	lock_forks_n_eat(t_local_info *philo)
{
	if (philo->deadline <= get_relative_time(*(philo->start)))
		return ;
	pthread_mutex_lock(philo->my_fork);
	if (*(philo->sim_is_running) == 1)
		safe_write(philo, "has taken a fork");
	pthread_mutex_lock(philo->other_fork);
	if (*(philo->sim_is_running) == 1)
		safe_write(philo, "has taken a fork");
	if (philo->deadline <= get_relative_time(*(philo->start)))
	{
		pthread_mutex_unlock(philo->my_fork);
		pthread_mutex_unlock(philo->other_fork);
		return ;
	}
	philo->deadline = get_relative_time(*(philo->start))
		+ philo->philo_info[TIME_TO_DIE];
	safe_write(philo, "is eating");
	philo->number_of_meals += 1;
	ft_usleep(philo->philo_info[TIME_TO_EAT], philo);
	pthread_mutex_unlock(philo->my_fork);
	pthread_mutex_unlock(philo->other_fork);
	return ;
}

static void	sleep_n_think(t_local_info *philo)
{
	if (philo->deadline <= get_relative_time(*(philo->start))
		+ philo->philo_info[TIME_TO_SLEEP])
		return ;
	safe_write(philo, "is sleeping");
	ft_usleep(philo->philo_info[TIME_TO_SLEEP], philo);
	if (*(philo->sim_is_running) != 1)
		return ;
	safe_write(philo, "is thinking");
	ft_usleep((philo->deadline
			- get_relative_time(*(philo->start))) / 2, philo);
	return ;
}

static void	living_loop(t_local_info *philo)
{
	while (*(philo->sim_is_running) == 1)
	{
		lock_forks_n_eat(philo);
		if (*(philo->sim_is_running) == 1)
			sleep_n_think(philo);
		usleep(1000);
	}
	return ;
}

void	*philo_routine(void *arg)
{
	t_local_info	*philo;

	philo = (t_local_info *)arg;
	while (*(philo->sim_is_running) == 0)
	{
	}
	if (*(philo->sim_is_running) != 1)
		return (NULL);
	philo->deadline = get_relative_time(*(philo->start)
			+ philo->philo_info[TIME_TO_DIE]);
	if (philo->who_am_i % 2)
		ft_usleep(((philo->philo_info[TIME_TO_EAT] / 2) + 1), philo);
	living_loop(philo);
	return (NULL);
}

void	launch_simulation(t_philo *monitoring)
{
	int	i;

	i = 0;
	while (i < monitoring->philo_info[NUMBER])
	{
		if (pthread_create(&monitoring->threads[i], NULL,
				&philo_routine, &monitoring->philo[i]))
		{
			perror("Thread creation error");
			clean_threads(monitoring, i, THREAD);
		}
		i++;
	}
	if (pthread_create(&monitoring->threads[i],
			NULL, &monitoring_routine, monitoring))
	{
		perror("Thread creation error");
		clean_threads(monitoring, i, THREAD);
	}
	if (pthread_join(monitoring->threads[i], NULL))
	{
		perror("Thread join error");
		clean_threads(monitoring, i, THREAD);
	}
	clean_threads(monitoring, i, EXIT_SUCCESS);
}
