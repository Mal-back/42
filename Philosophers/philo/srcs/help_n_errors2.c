/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_n_errors2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:43:38 by purmerinos        #+#    #+#             */
/*   Updated: 2024/01/26 11:43:39 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutex(t_philo *monitoring, int idx, int error)
{
	pthread_mutex_destroy(&monitoring->writing);
	if (idx > 1)
		pthread_mutex_destroy(&monitoring->deadline_mut);
	if (idx > 2)
		pthread_mutex_destroy(&monitoring->sim_state);
	if (idx > 3)
		pthread_mutex_destroy(&monitoring->meals_mut);
	ft_clean_exit(monitoring, error);
}
