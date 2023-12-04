/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 22:51:01 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/03 18:19:20 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_dual_sort(t_dclist **list_a, t_dclist **list_b)
{
	if ((*list_a)->prev == ft_find_little(list_a))
	{
		if ((*list_a)->data > (*list_a)->next->data)
			ft_sa(list_a, 1);
		ft_rrr(list_a, list_b);
	}
	else if ((*list_a)->next == ft_find_little(list_a))
	{
		if ((*list_a)->data < (*list_a)->prev->data)
			ft_ss(list_a, list_b);
		else
			ft_rr(list_a, list_b);
	}
	else
	{
		ft_ra(list_a, 1);
		ft_ss(list_a, list_b);
		ft_rra(list_a, 1);
	}
}

static void	ft_actual_sort_5(t_dclist **list_a, t_dclist **list_b)
{
	if (ft_is_sorted(*list_a) && !ft_is_sorted(*list_b))
	{
		ft_pa(list_a, list_b);
		ft_pa(list_a, list_b);
	}
	else if (ft_is_sorted(*list_a) && ft_is_sorted(*list_b))
	{
		ft_sb(list_b, 1);
		ft_pa(list_a, list_b);
		ft_pa(list_a, list_b);
	}
	else if (!ft_is_sorted(*list_b))
	{
		ft_sort_3(list_a);
		ft_pa(list_a, list_b);
		ft_pa(list_a, list_b);
	}
	else
	{
		ft_dual_sort(list_a, list_b);
		ft_pa(list_a, list_b);
		ft_pa(list_a, list_b);
	}
}

static void	ft_continue_sort_5(t_dclist **list_a, t_dclist **list_b,
		t_dclist **little, t_dclist **second_little)
{
	if (*list_a == *little || *list_a == *second_little)
		ft_pb(list_b, list_a);
	else if ((*list_a)->prev == *little || (*list_a)->prev == *second_little)
	{
		ft_rra(list_a, 1);
		ft_pb(list_b, list_a);
	}
	else if ((*list_a)->next == *little || (*list_a)->next == *second_little)
	{
		ft_ra(list_a, 1);
		ft_pb(list_b, list_a);
	}
	else
	{
		ft_ra(list_a, 1);
		ft_ra(list_a, 1);
		ft_pb(list_b, list_a);
	}
	ft_actual_sort_5(list_a, list_b);
}
void	ft_sort_5(t_dclist **list_a)
{
	t_dclist	*little;
	t_dclist	*second_little;
	t_dclist	*list_b;

	list_b = NULL;
	little = ft_find_little(list_a);
	second_little = ft_find_next_little(*list_a, &little);
	if (*list_a == little || *list_a == second_little)
		ft_pb(&list_b, list_a);
	else if ((*list_a)->prev == little || (*list_a)->prev == second_little)
	{
		ft_rra(list_a, 1);
		ft_pb(&list_b, list_a);
	}
	else if ((*list_a)->next == little || (*list_a)->next == second_little)
	{
		ft_ra(list_a, 1);
		ft_pb(&list_b, list_a);
	}
	else
	{
		ft_ra(list_a, 1);
		ft_ra(list_a, 1);
		ft_pb(&list_b, list_a);
	}
	ft_continue_sort_5(list_a, &list_b, &little, &second_little);
}
