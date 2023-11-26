/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:01:07 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/26 20:32:59 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_sa(t_dclist **list_a, int f)
{
	t_dclist	*node_1;
	t_dclist	*node_2;

	if (!list_a)
		return ;
	node_1 = *list_a;
	node_2 = (*list_a)->next;
	if (node_1->next == NULL)
		return ;
	if (f)
		ft_putendl_fd("sa", 1);
	ft_update_lstdc(list_a);
	ft_update_lstdc(list_a);
	ft_lstdcadd_front(list_a, node_1);
	ft_lstdcadd_front(list_a, node_2);
	return ;
}
