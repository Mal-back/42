/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:01:15 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/24 19:04:39 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_rrr(tdc_list **list_a, tdc_list **list_b)
{
	if (!*list_a && !*list_b && !(*list_a)->next && !(*list_b)->next)
		return ;
	ft_putendl_fd("rrr", 1);
	ft_rra(list_a, 0);
	ft_rrb(list_b, 0);
}