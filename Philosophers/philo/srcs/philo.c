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
	size_t	time;

	if (philo->deadline <= get_relative_time(*(philo->start)))
		return ;
	lock_fork(philo);
	if (philo->deadline <= get_relative_time(*(philo->start)))
	{
		pthread_mutex_unlock(philo->my_fork);
		pthread_mutex_unlock(philo->other_fork);
		return ;
	}
	time = get_relative_time(*(philo->start));
	pthread_mutex_lock(philo->deadline_mut);
	philo->deadline = time + philo->philo_info[TIME_TO_DIE];
	pthread_mutex_unlock(philo->deadline_mut);
	if (sim_is_running(philo))
		safe_write(philo, "is eating");
	pthread_mutex_lock(philo->meals_mut);
	philo->number_of_meals += 1;
	pthread_mutex_unlock(philo->meals_mut);
	ft_usleep(philo->philo_info[TIME_TO_EAT], philo);
	pthread_mutex_unlock(philo->my_fork);
	pthread_mutex_unlock(philo->other_fork);
	return ;
}

static void	sleep_n_think(t_local_info *philo)
{
	if (philo->deadline <= get_relative_time(*(philo->start))
		+ philo->philo_info[TIME_TO_SLEEP] || !sim_is_running(philo))
		return ;
	safe_write(philo, "is sleeping");
	ft_usleep(philo->philo_info[TIME_TO_SLEEP], philo);
	if (!sim_is_running(philo))
		return ;
	safe_write(philo, "is thinking");
	ft_usleep((philo->deadline
			- get_relative_time(*(philo->start))) / 2, philo);
	return ;
}

static void	living_loop(t_local_info *philo)
{
	while (sim_is_running(philo))
	{
		lock_forks_n_eat(philo);
		if (sim_is_running(philo))
			sleep_n_think(philo);
	}
	return ;
}

void	*philo_routine(void *arg)
{
	t_local_info	*philo;
	size_t			time;

	philo = (t_local_info *)arg;
	while (!sim_is_running(philo))
		usleep(1000);
	if (!sim_is_running(philo))
		return (NULL);
	time = get_relative_time(*(philo->start));
	pthread_mutex_lock(philo->deadline_mut);
	philo->deadline = time + philo->philo_info[TIME_TO_DIE];
	pthread_mutex_unlock(philo->deadline_mut);
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
