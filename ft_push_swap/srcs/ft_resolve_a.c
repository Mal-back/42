/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:44:30 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/03 20:39:05 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_resolve_a(t_dclist **list_a, t_dclist **list_b,
	int size_a)
{
	int			local_size_a;
	t_dclist	*head_a;

	head_a = *list_a;
	local_size_a = ft_lst_dcsize(*list_a);
	while (*list_b)
	{
		if ((*list_b)->data < (*list_a)->data)
		{
			ft_pa(list_a, list_b);
			if ((*list_a)->next == head_a)
				head_a = *list_a;
		}
		else
			ft_ra(list_a, 1);
		if ((*list_a)->next == head_a)
		{
			ft_ra(list_a, 1);
			while (*list_b)
			{
				ft_pa(list_a, list_b);
				ft_ra(list_a, 1);
			}
		}
	}
	while (*list_a != head_a)
	{
		if (local_size_a == size_a)
			ft_ra(list_a, 1);
		else
			ft_rra(list_a, 1);
	}
}
