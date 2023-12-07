/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_median.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:12:00 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/07 16:39:19 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_find_median(t_dclist **list)
{
	long		little;
	t_dclist	*big;
	t_dclist	*list_copy;
	long		median;

	median = 0;
	ft_lst_copy(list, &list_copy);
	while (ft_lst_dcsize(list_copy) > 2)
	{
		little = ft_find_little(&list_copy);
		big = ft_find_big(&list_copy);
		ft_dcdel(little, &list_copy);
		ft_dcdel(big->data, &list_copy);
	}
	big = ft_find_big(&list_copy);
	median = big->data;
	ft_lst_dcclear(&list_copy);
	return (median);
}
