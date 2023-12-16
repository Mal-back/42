/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:01:15 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/25 19:20:45 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrr(t_dclist **list_a, t_dclist **list_b)
{
	if (!*list_a && !*list_b && !(*list_a)->next && !(*list_b)->next)
		return ;
	ft_rra(list_a, 0);
	ft_rrb(list_b, 0);
}
