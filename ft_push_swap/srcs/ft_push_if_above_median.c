/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_if_above_median.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:11:47 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/28 17:14:46 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_if_above_median(t_dclist **list_a, t_dclist **list_b,
		int median_of_three, int absolute_size)
{
	t_dclist	*head_b;
	int			local_size;
	int			rotate_counter;

	head_b = *list_b;
	rotate_counter = 0;
	local_size = ft_lst_dcsize(*list_b);
	while ((*list_b)->next != head_b)
	{
		if ((*list_b)->data >= median_of_three)
		{
			ft_pa(list_a, list_b);
			head_b = *list_b;
		}
		else
		{
			ft_rb(list_b, 1);
			rotate_counter++;
		}
	}
	if (local_size != absolute_size)
	{
		while (rotate_counter--)
			ft_rrb(list_b, 1);
	}
}
