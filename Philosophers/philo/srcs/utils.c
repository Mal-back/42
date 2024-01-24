/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:07:40 by purmerinos        #+#    #+#             */
/*   Updated: 2024/01/23 12:07:42 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>

size_t	get_time(void)
{
	t_timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

size_t	get_relative_time(size_t start)
{
	size_t	relative_time;

	relative_time = get_time();
	return (relative_time - start);
}

void	ft_usleep(size_t time, t_local_info *philo)
{
	size_t	start;

	start = get_time();
	while (get_time() - start < time && sim_is_running(philo))
		usleep(500);
	return ;
}

void	safe_write(t_local_info *philo, char *str)
{
	pthread_mutex_lock(philo->writing);
	if (sim_is_running(philo))
		printf("[%ldms] %d %s\n", get_relative_time(*(philo->start)),
			philo->who_am_i + 1, str);
	pthread_mutex_unlock(philo->writing);
}

int	save_mutex_init(pthread_mutex_t *mutex)
{
	if (pthread_mutex_init(mutex, NULL))
	{
		perror("mutex_init");
		return (1);
	}
	return (0);
}
