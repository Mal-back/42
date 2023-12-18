/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:01:07 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/07 15:03:58 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_dclist **list_a, int f)
{
	long	tmp;

	if (!list_a || !*list_a || !(*list_a)->next)
		return ;
	if (f)
		ft_printf("sa\n");
	tmp = (*list_a)->data;
	(*list_a)->data = (*list_a)->next->data;
	(*list_a)->next->data = tmp;
	return ;
}
