/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 22:51:01 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/07 13:33:52 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_dual_sort(t_dclist **list_a, t_dclist **list_b)
{
	if ((*list_a)->data > (*list_a)->prev->data
		&& (*list_a)->data > (*list_a)->next->data)
	{
		if (ft_is_sorted(*list_b))
			ft_rrr(list_a, list_b);
		else
			ft_rra(list_a, 1);
	}
	else if ((*list_a)->next->data > (*list_a)->data
		&& (*list_a)->next->data > (*list_a)->prev->data)
	{
		if (ft_is_sorted(*list_b))
			ft_rr(list_a, list_b);
		else
			ft_ra(list_a, 1);
	}
	if ((*list_a)->data > (*list_a)->next->data)
	{
		if (ft_is_sorted(*list_b))
			ft_ss(list_a, list_b);
		else
			ft_sa(list_a, 1);
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
		long little, long second_little)
{
	if ((*list_a)->data == little || (*list_a)->data == second_little)
		ft_pb(list_b, list_a);
	else if ((*list_a)->prev->data == little
		|| (*list_a)->prev->data == second_little)
	{
		ft_rra(list_a, 1);
		ft_pb(list_b, list_a);
	}
	else if ((*list_a)->next->data == little
		|| (*list_a)->next->data == second_little)
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
	long		little;
	long		second_little;
	t_dclist	*list_b;

	list_b = NULL;
	little = ft_find_little(list_a);
	second_little = ft_find_next_little(*list_a, little);
	if ((*list_a)->data == little || (*list_a)->data == second_little)
		ft_pb(&list_b, list_a);
	else if ((*list_a)->prev->data == little
		|| (*list_a)->prev->data == second_little)
	{
		ft_rra(list_a, 1);
		ft_pb(&list_b, list_a);
	}
	else if ((*list_a)->next->data == little
		|| (*list_a)->next->data == second_little)
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
	ft_continue_sort_5(list_a, &list_b, little, second_little);
}
