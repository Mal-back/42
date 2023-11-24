/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:40:27 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/24 18:46:42 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_rr(tdc_list **list_a, tdc_list **list_b)
{
	if (!list_a && !list_b && !(*list_a)->next || !(*list_b)->next)
		return ;
	ft_putendl_fd("rr", 1);
	ft_ra(list_a, 0);
	ft_rb(list_b, 0);
	return;
}
