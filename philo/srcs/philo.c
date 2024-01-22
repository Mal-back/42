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

void	*philo_routine(void *philo)
{
	t_local_info info;

	info = *(t_local_info *)philo;
	if (info.who_am_i % 2)
	{
		pthread_mutex_lock(info.writing);	
		// timestamp
		pthread_mutex_unlock(info.writing);	
		usleep(300);
	}
}

void	launch_simulation(t_philo *monitoring)
{
	int	i;

	i = 0;
	while (i < monitoring->philo_info[NUMBER])
	{
		pthread_create(&monitoring->threads[i], NULL, &philo_routine, &monitoring->philo[i]);
	}

}
