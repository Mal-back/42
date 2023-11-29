/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_if_below_median.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:54:16 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/28 17:16:05 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_if_below_median(t_dclist **list_a, t_dclist **list_b,
		int median_of_three, int absolute_size)
{
	t_dclist	*head_a;
	int			local_size;
	int			rotate_counter;

	head_a = *list_a;
	rotate_counter = 0;
	local_size = ft_lst_dcsize(*list_a);
	while ((*list_a)->next != head_a)
	{
		if ((*list_a)->data <= median_of_three)
		{
			ft_pb(list_b, list_a);
			head_a = *list_a;
		}
		else
		{
			ft_ra(list_a, 1);
			rotate_counter++;
		}
	}
	if (local_size != absolute_size)
	{
		while (rotate_counter--)
			ft_rra(list_a, 1);
	}
}
