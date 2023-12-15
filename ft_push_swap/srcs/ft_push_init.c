/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:32:34 by purmerinos        #+#    #+#             */
/*   Updated: 2023/12/12 19:32:36 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

void	ft_push_init(t_dclist **list_a, t_dclist **list_b,
		int limit, int upper_limit)
{
	t_dclist	*tail_a;
	t_dclist	*head_a;

	tail_a = (*list_a)->prev;
	head_a = *list_a;
	// printf("Limit : %d \t i : %d \n", limit, i);
	while (*list_a != tail_a && (*list_a)->end_place < upper_limit)
	{
		// ft_print_test(*list_a);
		if ((*list_a)->end_place >= limit)
		{
			// if (*list_a == head_a)
			// 	head_a = (*list_a)->prev;
			ft_pb(list_b, list_a);
		}
		else
			ft_ra(list_a, 1);
	}
	if ((*list_a)->end_place >= limit && (*list_a)->end_place < upper_limit)
		ft_pb(list_b, list_a);
}
