/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_back_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 03:44:34 by purmerinos        #+#    #+#             */
/*   Updated: 2023/12/16 03:44:38 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_find_target_in_a(t_dclist **list_a, t_dclist **list_b)
{
	if ((*list_b)->data > ft_find_big(list_a)
		|| (*list_b)->data < ft_find_little(list_a))
		(*list_b)->target = ft_find_little(list_a);
	else
		(*list_b)->target = ft_find_next_little(*list_a, (*list_b)->data);
}

void	ft_indentify_cost(t_dclist **list_a, int data,
	int	*go_cost, int	*go_back_cost)
{
	t_dclist	*head;

	head = *list_a;
	*go_cost = 0;
	*go_back_cost = 0;
	while ((*list_a)->data != data)
	{
		*go_cost += 1;
		*list_a = (*list_a)->next;
	}
	*list_a = head;
	while ((*list_a)->data != data)
	{
		go_back_cost += 1;
		*list_a = (*list_a)->prev;
	}
	*list_a = head;
}

static void	ft_go_to_target(t_dclist **list_a, t_dclist **list_b)
{
	int	go_cost;
	int	go_back_cost;

	ft_indentify_cost(list_a, (*list_b)->target, &go_cost, &go_back_cost);
	while ((*list_a)->data != (*list_b)->target)
	{
		if (go_cost < go_back_cost)
			ft_ra(list_a, 1);
		else
			ft_rra(list_a, 1);
	}
}

void	ft_push_back_b(t_dclist **list_a, t_dclist **list_b)
{
	ft_find_target_in_a(list_a, list_b);
	ft_go_to_target(list_a, list_b);
	ft_pa(list_a, list_b);
}
