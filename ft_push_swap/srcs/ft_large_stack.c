/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:59:29 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/07 15:30:56 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_give_index(t_dclist **list_a)
{
	t_dclist	*head;
	int			i;

	head = *list_a;
	i = 0;
	while (*list_a != head || !i)
	{
		(*list_a)->index = i;
		(*list_a)->cheapest = 0;
		*list_a = (*list_a)->next;
		i++;
	}
}

static void	ft_go_to_min(t_dclist **list_a)
{
	int	go_cost;
	int	go_back_cost;

	ft_indentify_cost(list_a, ft_find_little(list_a), &go_cost, &go_back_cost);
	while (!ft_is_sorted(*list_a))
	{
		if (go_cost < go_back_cost)
			ft_ra(list_a, 1);
		else
			ft_rra(list_a, 1);
	}
}

void	ft_quick_sort_init(t_dclist **list_a, int absolute_size_a)
{
	t_dclist	*list_b;
	t_dclist	*cheapest_node;

	list_b = NULL;
	absolute_size_a++;
	cheapest_node = NULL;
	ft_pb(&list_b, list_a);
	ft_pb(&list_b, list_a);
	ft_give_index(list_a);
	while (ft_lst_dcsize(*list_a) > 5)
	{
		identify_cheapest(list_a, &list_b, &cheapest_node);
		push_cheapest(list_a, &list_b, &cheapest_node);
		ft_give_index(list_a);
	}
	ft_sort_5(list_a);
	while (list_b)
		ft_push_back_b(list_a, &list_b);
	ft_go_to_min(list_a);
}
