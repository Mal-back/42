/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_if_below_median.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:54:16 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/06 21:42:21 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate_to_good_place(t_dclist **list_a, t_dclist **head_a,
	int absolute_size, int local_size)
{
	if (local_size != absolute_size)
	{
		while (*list_a != *head_a)
			ft_rra(list_a, 1);
	}
}

void	ft_push_if_below_median(t_dclist **list_a, t_dclist **list_b,
		int median, int absolute_size)
{
	t_dclist	*tail_a;
	t_dclist	*head_a;
	int			local_size;

	tail_a = (*list_a)->prev;
	head_a = *list_a;
	local_size = ft_lst_dcsize(*list_a);
	while (*list_a != tail_a)
	{
		if ((*list_a)->data < median)
		{
			if (*list_a == head_a)
				head_a = (*list_a)->next;
			ft_pb(list_b, list_a);
		}
		else
			ft_ra(list_a, 1);
	}
	if ((*list_a)->data < median)
	{
		ft_pb(list_b, list_a);
		ft_rra(list_a, 1);
	}
	ft_rotate_to_good_place(list_a, &head_a, absolute_size, local_size);
}
