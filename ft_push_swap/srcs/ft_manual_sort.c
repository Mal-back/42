/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manual_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:59:41 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/02 20:12:40 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_manual_sort(t_dclist **list_a, int lst_size)
{
	if (lst_size == 2)
	{
		ft_sa(list_a, 1);
		return ;
	}
	if (lst_size == 3)
		ft_sort_3(list_a);
}
