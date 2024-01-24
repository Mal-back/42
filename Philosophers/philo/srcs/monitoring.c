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

static int	get_sim_state(t_philo *monitoring)
{
	int	res;

	res = 0;
	pthread_mutex_lock(&monitoring->sim_state);
	if (monitoring->sim_is_running == 1)
		res = 1;
	pthread_mutex_unlock(&monitoring->sim_state);
	return (res);
}

static void	monitore_death(t_philo *monitoring)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&monitoring->deadline_mut);
	while (i < monitoring->philo_info[NUMBER])
	{
		if ((get_relative_time(monitoring->start))
			>= (monitoring->philo[i].deadline))
		{
			pthread_mutex_lock(&monitoring->sim_state);
			monitoring->sim_is_running = 0;
			pthread_mutex_unlock(&monitoring->sim_state);
			pthread_mutex_lock(&monitoring->writing);
			printf("[%ldms] %d died\n", get_relative_time(monitoring->start),
				i + 1);
			pthread_mutex_unlock(&monitoring->writing);
			pthread_mutex_unlock(&monitoring->deadline_mut);
			return ;
		}
		i++;
	}
	pthread_mutex_unlock(&monitoring->deadline_mut);
	return ;
}

static void	monitore_meals(t_philo *monitoring)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&monitoring->meals_mut);
	while (i < monitoring->philo_info[NUMBER])
	{
		if (monitoring->philo[i].number_of_meals
			< monitoring->philo_info[SIM_LIMIT])
		{
			pthread_mutex_unlock(&monitoring->meals_mut);
			return ;
		}
		i++;
	}
	pthread_mutex_unlock(&monitoring->meals_mut);
	pthread_mutex_lock(&monitoring->sim_state);
	monitoring->sim_is_running = 0;
	pthread_mutex_unlock(&monitoring->sim_state);
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
	pthread_mutex_lock(&monitoring->sim_state);
	monitoring->sim_is_running = 1;
	pthread_mutex_unlock(&monitoring->sim_state);
	while (1)
	{
		monitore_death(monitoring);
		if (get_sim_state(monitoring) == 0)
			break ;
		if (monitoring->philo_info[SIM_LIMIT] != -1)
		{
			monitore_meals(monitoring);
			if (get_sim_state(monitoring) == 0)
				break ;
		}
		usleep(3000);
	}
	return (NULL);
}
