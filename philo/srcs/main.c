/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:53:45 by purmerinos        #+#    #+#             */
/*   Updated: 2024/01/19 13:53:46 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_struct(t_philo *monitoring)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		monitoring->philo_info[i] = -1;
		monitoring->sim_is_running = 0;
		monitoring->philo = NULL;
		monitoring->threads = NULL;
		monitoring->forks = NULL;
		i++;
	}
}

void	init_philo(t_philo *monitoring)
{
	monitoring->threads = malloc((monitoring->philo_info[NUMBER] + 1)
			* sizeof(pthread_t));
	if (monitoring->threads == NULL)
		ft_clean_exit(monitoring, MALLOC);
	monitoring->forks = malloc((monitoring->philo_info[NUMBER])
			* sizeof(pthread_mutex_t));
	if (monitoring->forks == NULL)
		ft_clean_exit(monitoring, MALLOC);
	monitoring->philo = malloc((monitoring->philo_info[NUMBER])
			* sizeof(t_local_info));
	if (monitoring->philo == NULL)
		ft_clean_exit(monitoring, MALLOC);
}

void	init_local_info(t_philo *monitoring)
{
	int	i;

	i = 0;
	while (i < monitoring->philo_info[NUMBER])
	{
		monitoring->philo[i].who_am_i = i;
		monitoring->philo[i].sim_is_running = &monitoring->sim_is_running;
		monitoring->philo[i].number_of_meals = 0;
		monitoring->philo[i].philo_info = monitoring->philo_info;
		monitoring->philo[i].writing = &monitoring->writing;
		monitoring->philo[i].my_fork = &monitoring->forks[i];
		if (i != monitoring->philo_info[NUMBER] - 1)
			monitoring->philo[i].other_fork = &monitoring->forks[i + 1];
		else
			monitoring->philo[i].other_fork = &monitoring->forks[0];
		monitoring->philo[i].deadline.tv_sec = 0;
		monitoring->philo[i].deadline.tv_usec = 0;
		i++;
	}
}

void	init_mutex(t_philo *monitoring)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&monitoring->writing, NULL))
	{
		perror("mutex_init");
		ft_clean_exit(monitoring, MUTEX);
	}
	while (i < monitoring->philo_info[NUMBER])
	{
		if (pthread_mutex_init(&monitoring->forks[i], NULL))
		{
			perror("mutex_init");
			mutex_fault(monitoring, i);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	t_philo	monitoring;

	if (ac < 5 || ac > 6)
		display_help(&monitoring, 0);
	init_struct(&monitoring);
	parse_av(av + 1, &monitoring);
	init_philo(&monitoring);
	init_local_info(&monitoring);
	init_mutex(&monitoring);
	return (0);
}
