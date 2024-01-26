/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:51:28 by purmerinos        #+#    #+#             */
/*   Updated: 2024/01/26 14:51:29 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <stdlib.h>

static void	living_loop(t_philo *philo)
{
	sem_wait(philo->forks);
	if (is_alive(philo) == FALSE)
		exit_routine(philo, 1);
	write_template(philo, "has taken a fork");
	sem_wait(philo->forks);
	if (is_alive(philo) == FALSE)
		exit_routine(philo, 2);
	write_template(philo, "has taken a fork");
	write_template(philo, "is eating");
	philo->meals++;
	philo->deadline = get_relative_time(philo->t_zero)
		+ philo->philo_info[TIME_TO_DIE];
	ft_usleep(philo->philo_info[TIME_TO_EAT], philo);
	sem_post(philo->forks);
	sem_post(philo->forks);
	if (is_alive(philo) == FALSE)
		exit_routine(philo, 0);
	write_template(philo, "is sleeping");
	ft_usleep(philo->philo_info[TIME_TO_SLEEP], philo);
	if (is_alive(philo) == FALSE)
		exit_routine(philo, 0);
	write_template(philo, "is thinking");
}

static int	philo_routine(t_philo *philo)
{
	free(philo->pid);
	sem_wait(philo->start);
	sem_close(philo->start);
	philo->t_zero = get_time();
	philo->deadline = get_relative_time(philo->t_zero)
		+ philo->philo_info[TIME_TO_DIE];
	if (philo->who_am_i % 2)
		ft_usleep(philo->philo_info[TIME_TO_EAT] / 2, philo);
	while (1)
	{
		living_loop(philo);
		if (philo->meals == philo->philo_info[SIM_LIMIT])
		{
			sem_close(philo->forks);
			sem_close(philo->start);
			exit(0);
		}
	}
	exit(0);
}

static void	starting_point(t_philo *philo, int i)
{
	while (i < philo->philo_info[NUMBER])
	{
		sem_post(philo->start);
		sem_post(philo->forks);
		i++;
	}
	philo->t_zero = get_time();
}

static void	wait_for_end(t_philo *philo)
{
	int	status;
	int	i;

	starting_point(philo, 0);
	i = 0;
	while (i < philo->philo_info[NUMBER])
	{
		waitpid(-1, &status, 0);
		if (WEXITSTATUS(status) != 0)
		{
			philo->who_am_i = WEXITSTATUS(status);
			kill_childrens(philo, philo->philo_info[NUMBER]);
			write_template(philo, "died");
			ft_clean_exit(philo, EXIT_SUCCESS);
		}
		i++;
	}
	printf("All child ate %d times. Ending simulation now.\n",
		philo->philo_info[SIM_LIMIT]);
	ft_clean_exit(philo, EXIT_SUCCESS);
}

void	launch_sim(t_philo *philo)
{
	int		i;

	i = 0;
	while (i < philo->philo_info[NUMBER])
	{
		philo->pid[i] = fork();
		if (philo->pid[i] == -1)
		{
			kill_childrens(philo, i);
			ft_clean_exit(philo, PID);
		}
		if (philo->pid[i] == 0)
		{
			philo->who_am_i = i + 1;
			philo_routine(philo);
		}
		i++;
	}
	wait_for_end(philo);
}
