/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_if_below_median.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:54:16 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/30 17:53:20 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_if_below_median(t_dclist **list_a, t_dclist **list_b,
		int median_of_three, int absolute_size)
{
	t_dclist	*tail_a;
	int			local_size;
	int			rotate_counter;

	tail_a = (*list_a)->prev;
	rotate_counter = 0;
	local_size = ft_lst_dcsize(*list_a);
	while (*list_a != tail_a)
	{
		if ((*list_a)->data <= median_of_three)
			ft_pb(list_b, list_a);
		else
		{
			ft_ra(list_a, 1);
			rotate_counter++;
		}
	}
	if ((*list_a)->data <= median_of_three)
		ft_pb(list_b, list_a);
	absolute_size++;
	while (rotate_counter > 0)
	{
		ft_rra(list_a, 1);
		rotate_counter--;
	}
}
