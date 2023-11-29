/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manual_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:59:41 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/27 18:27:04 by vlevy            ###   ########.fr       */
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
	if ((*list_a)->prev == ft_find_little(list_a))
	{
		if ((*list_a)->data > (*list_a)->next->data)
			ft_sa(list_a, 1);
		ft_rra(list_a, 1);
	}
	else if ((*list_a)->next == ft_find_little(list_a))
	{
		if ((*list_a)->data < (*list_a)->prev->data)
			ft_sa(list_a, 1);
		else
			ft_ra(list_a, 1);
	}
	else
	{
		ft_ra(list_a, 1);
		ft_sa(list_a, 1);
		ft_rra(list_a, 1);
	}
}
