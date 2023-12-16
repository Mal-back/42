/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:56:09 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/02 18:40:01 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrb(t_dclist **list_b, int f)
{
	if (!*list_b)
		return ;
	if (f)
		ft_putendl_fd("rrb", 1);
	if ((*list_b)->next)
		*list_b = (*list_b)->prev;
	return ;
}
