/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:56:17 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/01 22:11:27 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_quick_sort_b(t_dclist **list_b, int ultimate_size_a,
		int ultimate_size_b)
{
	t_dclist	*list_a;
	int			median_of_three;
	int			size_list;

	list_a = NULL;
	size_list = ft_lst_dcsize(*list_b);
	if (size_list > 2)
	{
		median_of_three = ft_find_median_of_three(*list_b, size_list);
		ft_push_if_above_median(&list_a, list_b, median_of_three,
			ultimate_size_b);
		ft_quick_sort_a(&list_a, ultimate_size_a, ultimate_size_b);
		ft_quick_sort_b(list_b, ultimate_size_a, ultimate_size_b);
	}
	else if (size_list == 2 && (*list_b)->data < (*list_b)->next->data)
		ft_sb(list_b, 1);
	ft_merge_to_b(&list_a, list_b);
	return ;
}