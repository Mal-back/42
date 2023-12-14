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

#include "push_swap.h"

void	ft_push_init(t_dclist **list_a, t_dclist **list_b,
		int limit, int i)
{
	t_dclist	*tail_a;
	t_dclist	*head_a;

	tail_a = (*list_a)->prev;
	head_a = *list_a;
	while (*list_a != tail_a && (*list_a)->end_place < limit * i)
	{
		// ft_print_test(*list_a);
		if ((*list_a)->end_place >= limit * (i - 1))
		{
			if (*list_a == head_a)
				head_a = (*list_a)->next;
			ft_pb(list_b, list_a);
		}
		else
			ft_ra(list_a, 1);
	}
	if ((*list_a)->end_place >= limit * (i - 1))
		ft_pb(list_b, list_a);
}
