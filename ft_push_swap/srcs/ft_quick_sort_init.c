/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:59:29 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/07 15:30:56 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_quick_sort_init(t_dclist **list_a, int absolute_size_a)
{
	t_dclist	*list_b;
	long		median;
	int			absolute_size_b;

	list_b = NULL;
	if (absolute_size_a > 999999)
	{
		median = ft_find_median(list_a);
		ft_push_if_below_median(list_a, &list_b, median, absolute_size_a);
		absolute_size_a = ft_lst_dcsize(*list_a);
		absolute_size_b = ft_lst_dcsize(list_b);
		ft_quick_sort_a(list_a, absolute_size_a, absolute_size_b);
		ft_quick_sort_b(&list_b, absolute_size_a, absolute_size_b);
	}
	else
	{
		// ft_manual_sort(list_a, ft_lst_dcsize(*list_a));
		test_sort(list_a, &list_b);
		// ft_manual_sort(&list_b, ft_lst_dcsize(list_b));
		// ft_bubble_sort(list_a, &list_b);
	}
	ft_merge_to_a(list_a, &list_b);
}
