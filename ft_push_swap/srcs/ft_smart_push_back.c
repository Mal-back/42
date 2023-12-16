/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smart_push_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 21:52:44 by purmerinos        #+#    #+#             */
/*   Updated: 2023/12/13 21:52:45 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	separate_rotate(t_dclist **list_a, t_dclist **list_b,
		t_dclist **cheapest_node)
{
	while ((*list_a)->data != (*cheapest_node)->data)
	{
		if ((*cheapest_node)->direction_a)
			ft_rra(list_a, 1);
		else
			ft_ra(list_a, 1);
	}
	while ((*list_b)->data != (*cheapest_node)->target)
	{
		if ((*cheapest_node)->direction_b)
			ft_rrb(list_b, 1);
		else
			ft_rb(list_b, 1);
	}
}

void	push_cheapest(t_dclist **list_a, t_dclist **list_b,
	t_dclist **cheapest_node)
{
	if ((*cheapest_node)->direction_a == (*cheapest_node)->direction_b)
		combine_rotate(list_a, list_b, cheapest_node);
	else
		separate_rotate(list_a, list_b, cheapest_node);
	ft_pb(list_b, list_a);
}

void	combine_rotate(t_dclist **list_a, t_dclist **list_b,
	t_dclist **cheapest_node)
{
	if (!(*cheapest_node)->direction_b)
	{
		while ((*list_a)->data != (*cheapest_node)->data
			&& (*list_b)->data != (*cheapest_node)->target)
			ft_rr(list_a, list_b);
		while ((*list_b)->data != (*cheapest_node)->target)
			ft_rb(list_b, 1);
		while ((*list_a)->data != (*cheapest_node)->data)
			ft_ra(list_a, 1);
	}
	else
	{
		while ((*list_b)->data != (*cheapest_node)->target
			&& (*list_a)->data != (*cheapest_node)->data)
			ft_rrr(list_a, list_b);
		while ((*list_b)->data != (*cheapest_node)->target)
			ft_rrb(list_b, 1);
		while ((*list_a)->data != (*cheapest_node)->data)
			ft_rra(list_a, 1);
	}
}
