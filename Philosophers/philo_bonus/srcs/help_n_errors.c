/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_n_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:14:09 by purmerinos        #+#    #+#             */
/*   Updated: 2024/01/26 12:14:11 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <stdlib.h>

void	display_help(t_philo *philo, int code)
{
	printf("Usage : ./philo [Numbers_of_philo] [time_to_die] [time_to_eat] \
[time_to_sleep]\n All values should be positive integers.\n");
	ft_clean_exit(philo, code);
}

void	ft_clean_exit(t_philo *philo, int code)
{
	if (philo->forks != SEM_FAILED && philo->forks != NULL)
	{
		sem_close(philo->forks);
		sem_unlink("forks");
	}
	if (philo->start != SEM_FAILED && philo->start != NULL)
	{
		sem_close(philo->start);
		sem_unlink("start");
	}
	if (philo->pid)
		free (philo->pid);
	exit(code);
}

void	exit_routine(t_philo *philo, int idx)
{
	int	i;

	i = 0;
	while (i < idx)
	{
		sem_post(philo->forks);
		i++;
	}
	sem_close(philo->forks);
	exit(philo->who_am_i);
}

void	kill_childrens(t_philo *philo, int idx)
{
	int	i;

	i = 0;
	while (i < idx)
	{
		kill(philo->pid[i], SIGKILL);
		i++;
	}
}

void	solo(t_philo *monitoring)
{
	printf("[0ms] 1 has taken a fork\n");
	usleep(monitoring->philo_info[TIME_TO_DIE] * 1000);
	printf("[%dms] 1 died\n", monitoring->philo_info[TIME_TO_DIE] + 1);
	exit(EXIT_SUCCESS);
}
