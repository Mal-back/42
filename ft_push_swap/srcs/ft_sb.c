/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:35:49 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/30 14:40:12 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_sb(t_dclist **list_b, int f)
{
	t_dclist	*node_1;
	t_dclist	*node_2;

	if (!list_b || !*list_b)
		return ;
	node_1 = *list_b;
	node_2 = (*list_b)->next;
	if (f)
		ft_putendl_fd("sb", 1);
	ft_update_lstdc(list_b);
	ft_update_lstdc(list_b);
	ft_lstdcadd_front(list_b, node_1);
	ft_lstdcadd_front(list_b, node_2);
	return ;
}
