/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:29:33 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/24 18:44:04 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_ra(tdc_list **list_a, int f)
{
	if (!*list_a || !(*list_a)->next)
		return ;
	if (f)
		ft_putendl_fd("ra", 1);
	*list_a = (*list_a)->next;
	return ;
}
