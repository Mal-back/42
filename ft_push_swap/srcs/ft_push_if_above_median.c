/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_if_above_median.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:11:47 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/06 21:42:31 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate_to_good_place(t_dclist **list_b, t_dclist **head_b,
	int absolute_size, int local_size)
{
	if (local_size != absolute_size)
	{
		while (*list_b != *head_b)
			ft_rrb(list_b, 1);
	}
}

void	ft_push_if_above_median(t_dclist **list_a, t_dclist **list_b,
		int median, int absolute_size)
{
	t_dclist	*head_b;
	t_dclist	*tail_b;
	int			local_size;

	tail_b = (*list_b)->prev;
	head_b = *list_b;
	local_size = ft_lst_dcsize(*list_b);
	while (*list_b != tail_b)
	{
		if ((*list_b)->data > median)
		{
			if (*list_b == head_b)
				head_b = (*list_b)->next;
			ft_pa(list_a, list_b);
		}
		else
			ft_rb(list_b, 1);
	}
	if ((*list_b)->data > median)
	{
		ft_pa(list_a, list_b);
		ft_rrb(list_b, 1);
	}
	ft_rotate_to_good_place(list_b, &head_b, local_size, absolute_size);
}
