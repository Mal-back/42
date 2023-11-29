/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_if_above_median.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:11:47 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/29 19:46:56 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_if_above_median(t_dclist **list_a, t_dclist **list_b,
		int median_of_three, int absolute_size)
{
	t_dclist	*tail_b;
	int			local_size;
	int			rotate_counter;

	tail_b = (*list_b)->prev;
	rotate_counter = 0;
	local_size = ft_lst_dcsize(*list_b);
	while (*list_b != tail_b)
	{
		if ((*list_b)->data >= median_of_three)
			ft_pa(list_a, list_b);
		else
		{
			ft_rb(list_b, 1);
			rotate_counter++;
		}
	}
	if ((*list_b)->data >= median_of_three)
		ft_pa(list_a, list_b);
	if (local_size != absolute_size)
	{
		while (rotate_counter--)
			ft_rrb(list_b, 1);
	}
}
