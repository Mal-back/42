/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:35:49 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/07 15:03:37 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sb(t_dclist **list_b, int f)
{
	long	tmp;
	int		tmp_place;

	if (!list_b || !*list_b || !(*list_b)->next)
		return ;
	if (f)
		ft_printf("sb\n");
	tmp = (*list_b)->data;
	tmp_place = (*list_b)->index;
	(*list_b)->data = (*list_b)->next->data;
	(*list_b)->index = (*list_b)->next->index;
	(*list_b)->next->data = tmp;
	(*list_b)->next->index = tmp_place;
	return ;
}
