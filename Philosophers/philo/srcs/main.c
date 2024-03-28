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
		i++;
	}
	monitoring->sim_is_running = 0;
	monitoring->philo = NULL;
	monitoring->threads = NULL;
	monitoring->forks = NULL;
	monitoring->number_of_forks_set = 0;
	monitoring->deadline_is_set = FALSE;
	monitoring->writing_is_set = FALSE;
	monitoring->meals_is_set = FALSE;
	monitoring->sim_state_is_set = FALSE;
}

int	init_philo(t_philo *monitoring)
{
	monitoring->threads = malloc((monitoring->philo_info[NUMBER] + 1)
			* sizeof(pthread_t));
	monitoring->forks = malloc((monitoring->philo_info[NUMBER])
			* sizeof(pthread_mutex_t));
	monitoring->philo = malloc(((monitoring->philo_info[NUMBER] + 1))
			* sizeof(t_local_info));
	if (monitoring->threads == NULL || monitoring->forks == NULL
		|| monitoring->philo == NULL)
	{
		ft_clean_exit(monitoring);
		return (-1);
	}
	return (0);
}

void	init_local_info(t_philo *monitoring)
{
	int	i;

	i = 0;
	while (i < monitoring->philo_info[NUMBER])
	{
		monitoring->philo[i].who_am_i = i;
		monitoring->philo[i].start = &monitoring->start;
		monitoring->philo[i].sim_is_running = &monitoring->sim_is_running;
		monitoring->philo[i].number_of_meals = 0;
		monitoring->philo[i].philo_info = monitoring->philo_info;
		monitoring->philo[i].writing = &monitoring->writing;
		monitoring->philo[i].sim_state = &monitoring->sim_state;
		monitoring->philo[i].deadline_mut = &monitoring->deadline_mut;
		monitoring->philo[i].meals_mut = &monitoring->meals_mut;
		monitoring->philo[i].my_fork = &monitoring->forks[i];
		if (i != monitoring->philo_info[NUMBER] - 1)
			monitoring->philo[i].other_fork = &monitoring->forks[i + 1];
		else
			monitoring->philo[i].other_fork = &monitoring->forks[0];
		monitoring->philo[i].deadline = monitoring->philo_info[TIME_TO_DIE];
		i++;
	}
}

int	init_mutex(t_philo *monitoring)
{
	int	i;

	i = 0;
	if (save_mutex_init(&monitoring->writing, &monitoring->writing_is_set))
		return (ft_clean_exit(monitoring), -1);
	if (save_mutex_init(&monitoring->sim_state, &monitoring->sim_state_is_set))
		return (mutex_fault(monitoring), -1);
	if (save_mutex_init(&monitoring->meals_mut, &monitoring->meals_is_set))
		return (mutex_fault(monitoring), -1);
	if (save_mutex_init(&monitoring->deadline_mut,
			&monitoring->deadline_is_set))
		return (mutex_fault(monitoring), -1);
	while (i < monitoring->philo_info[NUMBER])
	{
		if (save_fork_init(&monitoring->forks[i],
				&monitoring->number_of_forks_set))
			return (mutex_fault(monitoring), -1);
		++i;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_philo	monitoring;

	if (ac < 5 || ac > 6)
		return (display_help(), 0);
	init_struct(&monitoring);
	if (parse_av(av + 1, &monitoring) == -1)
		return (display_help(), 0);
	if (init_philo(&monitoring) == -1)
		return (1);
	init_local_info(&monitoring);
	if (init_mutex(&monitoring) == -1)
		return (1);
	if (monitoring.philo_info[NUMBER] == 1)
		return (solo(&monitoring), 0);
	return (launch_simulation(&monitoring));
}
