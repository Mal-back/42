/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:04:40 by purmerinos        #+#    #+#             */
/*   Updated: 2024/01/23 12:04:44 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

static void	monitore_death(t_philo *monitoring)
{
	int	i;

	i = 0;
	while (i < monitoring->philo_info[NUMBER])
	{
		if ((get_relative_time(monitoring->start))
			>= (monitoring->philo[i].deadline))
		{
			monitoring->sim_is_running = 0;
			pthread_mutex_lock(&monitoring->writing);
			printf("[%ldms] %d died\n", get_relative_time(monitoring->start),
				i + 1);
			pthread_mutex_unlock(&monitoring->writing);
			return ;
		}
		i++;
	}
	return ;
}

static void	monitore_meals(t_philo *monitoring)
{
	int	i;

	i = 0;
	while (i < monitoring->philo_info[NUMBER])
	{
		if (monitoring->philo[i].number_of_meals
			< monitoring->philo_info[SIM_LIMIT])
			return ;
		i++;
	}
	monitoring->sim_is_running = 0;
	pthread_mutex_lock(&monitoring->writing);
	printf("[%ldms] All philosophers ate %d time. Ending simulation now.\n",
		get_relative_time(monitoring->start),
		monitoring->philo_info[SIM_LIMIT]);
	pthread_mutex_unlock(&monitoring->writing);
	return ;
}

void	*monitoring_routine(void *arg)
{
	t_philo	*monitoring;

	monitoring = (t_philo *)arg;
	usleep(monitoring->philo_info[NUMBER] * 10000);
	pthread_mutex_lock(&monitoring->writing);
	printf("Starting simulation\n");
	pthread_mutex_unlock(&monitoring->writing);
	monitoring->start = get_time();
	monitoring->sim_is_running = 1;
	while (monitoring->sim_is_running == 1)
	{
		monitore_death(monitoring);
		if (monitoring->philo_info[SIM_LIMIT] != -1
			&& monitoring->sim_is_running == 1)
			monitore_meals(monitoring);
		usleep(3000);
	}
	return (NULL);
}
