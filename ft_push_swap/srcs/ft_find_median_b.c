/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_median_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:04:16 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/07 16:40:30 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_find_median_b(t_dclist **list)
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
	little = ft_find_little(&list_copy);
	median = little;
	ft_lst_dcclear(&list_copy);
	return (median);
}
