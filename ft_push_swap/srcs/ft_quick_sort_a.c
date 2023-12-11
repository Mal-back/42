/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:37:41 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/06 22:29:44 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_quick_sort_a(t_dclist **list_a, int ultimate_size_a,
		int ultimate_size_b)
{
	t_dclist	*list_b;
	int			median;
	int			list_size;

	list_size = ft_lst_dcsize(*list_a);
	list_b = NULL;
	if (list_size > 15)
	{
		median = ft_find_median(list_a);
		ft_push_if_below_median(list_a, &list_b,
			median, ultimate_size_a);
		ft_quick_sort_a(list_a, ultimate_size_a, ultimate_size_b);
		ft_quick_sort_b(&list_b, ultimate_size_a, ultimate_size_b);
		ft_merge_to_a(list_a, &list_b);
	}
	else
		final_sort_a(list_a, &list_b);
	return ;
}
