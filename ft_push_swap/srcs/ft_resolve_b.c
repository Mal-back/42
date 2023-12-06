/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:44:30 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/05 18:10:05 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_to_first_b(t_dclist **list_b)
{
	while (before_is_smaller(list_b))
		ft_rrb(list_b, 1);
	// ft_rra(list_b, 1);
}

void	rotate_to_first_b(t_dclist **list_b)
{
	while (after_is_bigger(list_b))
		ft_rb(list_b, 1);
	ft_rb(list_b, 1);
}

void	ft_resolve_b(t_dclist **list_a, t_dclist **list_b,
	int size_b)
{
	t_dclist	*tail_b;
	int			local_size_b;

	tail_b = (*list_b)->prev;
	local_size_b = ft_lst_dcsize(*list_b);
	while (*list_a && *list_b != tail_b && (*list_b)->prev != (*list_b)->next)
	{
		while (*list_a && (*list_a)->data < (*list_b)->data)
			ft_pb(list_b, list_a);
		ft_rb(list_b, 1);
	}
	while (*list_a)
	{
		while (*list_a && (*list_a)->data > (*list_b)->data
			&& (*list_b)->data > (*list_b)->next->next->data)
			ft_rb(list_b, 1);
		ft_pb(list_b, list_a);
	}
	if (local_size_b == size_b)
		rotate_to_first_b(list_b);
	else
		rev_rotate_to_first_b(list_b);
}
