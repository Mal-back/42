/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:59:29 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/02 18:00:13 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_quick_sort_init(t_dclist **list_a, int absolute_size_a,
		int absolute_size_b)
{
	t_dclist	*list_b;
	int			median_of_three;

	median_of_three = ft_find_median_of_three(*list_a, ft_lst_dcsize(*list_a));
	list_b = NULL;
	ft_push_if_below_median(list_a, &list_b, median_of_three, absolute_size_a);
	absolute_size_a = ft_lst_dcsize(*list_a);
	absolute_size_b = ft_lst_dcsize(list_b);
	ft_quick_sort_a(list_a, absolute_size_a, absolute_size_b);
	ft_quick_sort_b(&list_b, absolute_size_a, absolute_size_b);
	ft_merge_to_a(list_a, &list_b);
}
