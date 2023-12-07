/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dcdel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:40:07 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/07 16:38:29 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dcdel(long node, t_dclist **list)
{
	t_dclist	*tmp;

	while ((*list)->data != node)
	{
		*list = (*list)->next;
	}
	(*list)->prev->next = (*list)->next;
	(*list)->next->prev = (*list)->prev;
	tmp = *list;
	*list = (*list)->next;
	free(tmp);
	return ;
}
