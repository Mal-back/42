/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 22:13:21 by purmerinos        #+#    #+#             */
/*   Updated: 2023/12/15 22:13:22 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_target(t_dclist **list_b, t_dclist **looked_position)
{
	t_dclist	*head;

	head = *list_b;
	if ((*looked_position)->data < ft_find_little(list_b)
		|| (*looked_position)->data > ft_find_big(list_b))
		(*looked_position)->target = ft_find_big(list_b);
	else
		(*looked_position)->target
			= ft_find_next_big(list_b, (*looked_position)->data);
}

static void	calcul_cost_classic_order(t_dclist **list_a, t_dclist **list_b,
	t_dclist **looked_position, int *cheapest)
{
	(*looked_position)->direction_a = 0;
	(*looked_position)->rotate_cost_a
		= ft_cost_to_go_a(list_a, looked_position);
	assign_target(list_b, looked_position);
	resolve_direction_b(list_b, looked_position);
	resolve_cost(looked_position);
	if ((*looked_position)->final_cost < *cheapest)
	{
		*cheapest = (*looked_position)->final_cost;
		(*looked_position)->cheapest = 1;
	}
}

static void	calcul_cost_reverse_order(t_dclist **list_a, t_dclist **list_b,
	t_dclist **looked_position, int *cheapest)
{
	(*looked_position)->direction_a = 1;
	(*looked_position)->rotate_cost_a
		= ft_cost_to_go_a(list_a, looked_position);
	assign_target(list_b, looked_position);
	resolve_direction_b(list_b, looked_position);
	resolve_cost(looked_position);
	if ((*looked_position)->final_cost < *cheapest)
	{
		*cheapest = (*looked_position)->final_cost;
		(*looked_position)->cheapest = 1;
	}
}

static void	is_cheapest(t_dclist **looked_position, t_dclist **cheapest_node)
{
	if ((*looked_position)->cheapest)
	{
		if (*cheapest_node)
			(*cheapest_node)->cheapest = 0;
		*cheapest_node = *looked_position;
	}
}

void	identify_cheapest(t_dclist **list_a, t_dclist **list_b,
	t_dclist **cheapest_node)
{
	t_dclist	*looked_position;
	int			cheapest;

	cheapest = 2147483647;
	looked_position = *list_a;
	looked_position->direction_a = 0;
	while (looked_position->index < ft_lst_dcsize(*list_a) / 2 && cheapest)
	{
		calcul_cost_classic_order(list_a, list_b, &looked_position, &cheapest);
		is_cheapest(&looked_position, cheapest_node);
		looked_position = looked_position->next;
	}
	looked_position = (*list_a)->prev;
	looked_position->direction_a = 1;
	while (looked_position->index > ft_lst_dcsize(*list_a) / 2 && cheapest)
	{
		calcul_cost_reverse_order(list_a, list_b, &looked_position, &cheapest);
		is_cheapest(&looked_position, cheapest_node);
		looked_position = looked_position->next;
	}
}
