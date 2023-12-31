/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manual_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:59:41 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/04 17:11:28 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_manual_sort(t_dclist **list_a, int lst_size)
{
	if (ft_is_sorted(*list_a))
		return ;
	else if (lst_size == 2)
	{
		ft_sa(list_a, 1);
		return ;
	}
	if (lst_size == 3)
		ft_sort_3(list_a);
	else if (lst_size == 4)
		ft_sort_4(list_a);
	else if (lst_size == 5)
		ft_sort_5(list_a);
}
