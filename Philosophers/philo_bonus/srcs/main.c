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

#include "philo_bonus.h"
#include <sched.h>

static void	init_struct(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		philo->philo_info[i] = -1;
		i++;
	}
	philo->who_am_i = -1;
	philo->t_zero = 0;
	philo->meals = 0;
	philo->deadline = 0;
	philo->forks = NULL;
	philo->start = NULL;
	philo->pid = NULL;
}

static void	init_sem(t_philo *philo)
{
	philo->who_am_i = -1;
	philo->forks = sem_open("forks", O_CREAT, 0666, 0);
	if (philo->forks == SEM_FAILED)
		ft_clean_exit(philo, SEMAPHORE);
	philo->start = sem_open("start", O_CREAT, 0666, 0);
	if (philo->forks == SEM_FAILED)
		ft_clean_exit(philo, SEMAPHORE);
	philo->pid = malloc(philo->philo_info[NUMBER] * sizeof (pid_t));
	if (philo->pid == NULL)
		ft_clean_exit(philo, MALLOC);
}

int	main(int ac, char **av)
{
	t_philo	philo;

	init_struct(&philo);
	if (ac < 5 || ac > 6)
		display_help(&philo, 0);
	parse_av(av + 1, &philo);
	if (philo.philo_info[NUMBER] == 1)
		solo(&philo);
	init_sem(&philo);
	launch_sim(&philo);
	return (0);
}
