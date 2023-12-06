/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:56:17 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/06 22:28:26 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_quick_sort_b(t_dclist **list_b, int ultimate_size_a,
		int ultimate_size_b)
{
	t_dclist	*list_a;
	int			median;
	int			size_list;

	list_a = NULL;
	size_list = ft_lst_dcsize(*list_b);
	median = ft_find_median_b(list_b);
	ft_push_if_above_median(&list_a, list_b, median,
		ultimate_size_b);
	if (size_list > 10)
	{
		ft_quick_sort_a(&list_a, ultimate_size_a, ultimate_size_b);
		ft_quick_sort_b(list_b, ultimate_size_a, ultimate_size_b);
	}
	else
	{
		ft_manual_sort(&list_a, ft_lst_dcsize(list_a));
		ft_manual_sort(list_b, ft_lst_dcsize(*list_b));
	}
		// ft_bubble_sort_b(list_b, &list_a);
	ft_merge_to_b(&list_a, list_b);
	return ;
}
