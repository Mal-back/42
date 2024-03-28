/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:36:38 by purmerinos        #+#    #+#             */
/*   Updated: 2024/01/24 13:36:38 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	sim_is_running(t_local_info *philo)
{
	int	res;

	res = 0;
	pthread_mutex_lock(philo->sim_state);
	res = *philo->sim_is_running;
	pthread_mutex_unlock(philo->sim_state);
	return (res);
}

void	lock_fork(t_local_info *philo)
{	
	if (!philo->who_am_i % 2 && philo->philo_info[NUMBER] - 1
		!= philo->who_am_i)
		pthread_mutex_lock(philo->my_fork);
	else
		pthread_mutex_lock(philo->other_fork);
	if (sim_is_running(philo) == 1)
		safe_write(philo, "has taken a fork");
	if (!philo->who_am_i % 2 && philo->philo_info[NUMBER] - 1
		!= philo->who_am_i)
		pthread_mutex_lock(philo->other_fork);
	else
		pthread_mutex_lock(philo->my_fork);
	if (sim_is_running(philo) == 1)
		safe_write(philo, "has taken a fork");
	return ;
}

int	save_fork_init(pthread_mutex_t *mutex, size_t *fork_counter)
{
	if (pthread_mutex_init(mutex, NULL))
	{
		perror("mutex_init");
		return (1);
	}
	else
	{
		*fork_counter += 1;
	}
	return (0);
}
