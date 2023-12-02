/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:56:09 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/02 18:38:21 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_dclist **list_a, int f)
{
	if (!*list_a)
		return ;
	if (f)
		ft_printf("rra\n");
	if ((*list_a)->next)
		*list_a = (*list_a)->prev;
	return ;
}
