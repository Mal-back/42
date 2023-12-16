/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:08:26 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/07 16:36:16 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_dclist **list_a)
{
	if (ft_is_sorted(*list_a))
		return ;
	if ((*list_a)->data > (*list_a)->prev->data
		&& (*list_a)->data > (*list_a)->next->data)
		ft_ra(list_a, 1);
	else if ((*list_a)->next->data > (*list_a)->data
		&& (*list_a)->next->data > (*list_a)->prev->data)
		ft_rra(list_a, 1);
	if ((*list_a)->data > (*list_a)->next->data)
		ft_sa(list_a, 1);
	return ;
}
