/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:44:30 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/05 18:10:17 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_to_first_a(t_dclist **list_a)
{
	while (before_is_smaller(list_a))
		ft_rra(list_a, 1);
	// ft_rra(list_a, 1);
}

void	rotate_to_first_a(t_dclist **list_a)
{
	while (after_is_bigger(list_a))
		ft_ra(list_a, 1);
	ft_ra(list_a, 1);
}

void	ft_resolve_a(t_dclist **list_a, t_dclist **list_b,
	int size_a)
{
	t_dclist	*tail_a;
	int			local_size_a;

	tail_a = (*list_a)->prev;
	local_size_a = ft_lst_dcsize(*list_a);
	while (*list_b && *list_a != tail_a && (*list_a)->prev != (*list_a)->next)
	{
		while (*list_b && (*list_b)->data < (*list_a)->data)
			ft_pa(list_a, list_b);
		ft_ra(list_a, 1);
	}
	while (*list_b)
	{
		while (*list_b && (*list_b)->data > (*list_a)->data
			&& (*list_a)->data > (*list_a)->next->next->data)
			ft_ra(list_a, 1);
		ft_pa(list_a, list_b);
	}
	if (local_size_a == size_a)
		rotate_to_first_a(list_a);
	else
		rev_rotate_to_first_a(list_a);
}
