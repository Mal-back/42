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

#include "philo_bonus.h"

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

void	ft_usleep(size_t time, t_philo *philo)
{
	size_t	start;

	start = get_time();
	while (get_time() - start < time && is_alive(philo) == TRUE)
		usleep(500);
	return ;
}

int	is_alive(t_philo *philo)
{
	if (get_relative_time(philo->t_zero) >= philo->deadline)
		return (FALSE);
	return (TRUE);
}

void	write_template(t_philo *philo, char *str)
{
	printf("[%ldms] %d %s\n", get_relative_time(philo->t_zero),
		philo->who_am_i, str);
}
