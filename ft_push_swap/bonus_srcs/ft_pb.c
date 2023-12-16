/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:12:45 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/30 13:15:38 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pb(t_dclist **list_b, t_dclist **list_a)
{
	t_dclist	*tmp;

	tmp = *list_a;
	if (!list_a || !*list_a)
		return ;
	ft_update_lstdc(list_a);
	tmp->prev = NULL;
	tmp->next = NULL;
	ft_lstdcadd_front(list_b, tmp);
	return ;
}
