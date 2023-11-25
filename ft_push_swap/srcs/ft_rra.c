/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:56:09 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/25 19:20:24 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_dclist **list_a, int f)
{
	if (!*list_a || !(*list_a)->next)
		return ;
	if (f)
		ft_printf("rra\n");
	*list_a = (*list_a)->prev;
	return ;
}
