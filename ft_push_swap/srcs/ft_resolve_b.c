/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:44:30 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/03 21:01:09 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_resolve_b(t_dclist **list_a, t_dclist **list_b,
	int size_b)
{
	int			local_size_b;
	t_dclist	*head_b;

	head_b = *list_b;
	local_size_b = ft_lst_dcsize(*list_b);
	while (*list_a)
	{
		if ((*list_a)->data < (*list_b)->data)
		{
			ft_pb(list_b, list_a);
			if ((*list_b)->next == head_b)
				head_b = *list_b;
		}
		else
			ft_rb(list_b, 1);
		if ((*list_b)->next == head_b)
		{
			ft_rb(list_b, 1);
			while (*list_a)
			{
				ft_pb(list_b, list_a);
				ft_rb(list_b, 1);
			}
		}
	}
	while (*list_b != head_b)
	{
		if (local_size_b == size_b)
			ft_rb(list_b, 1);
		else
			ft_rrb(list_b, 1);
	}
}
