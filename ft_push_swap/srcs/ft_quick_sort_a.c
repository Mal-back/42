/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:37:41 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/03 18:27:52 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_quick_sort_a(t_dclist **list_a, int ultimate_size_a,
		int ultimate_size_b)
{
	t_dclist	*list_b;
	int			lst_size;
	int			median_of_three;

	lst_size = ft_lst_dcsize(*list_a);
	list_b = NULL;
	if (lst_size > 3)
	{
		median_of_three = ft_find_median_of_three(*list_a, lst_size);
		ft_push_if_below_median(list_a, &list_b,
			median_of_three, ultimate_size_a);
		ft_quick_sort_a(list_a, ultimate_size_a, ultimate_size_b);
		ft_quick_sort_b(&list_b, ultimate_size_a, ultimate_size_b);
		ft_merge_to_a(list_a, &list_b);
	}
	else
		ft_manual_sort(list_a, lst_size);
	return ;
}
