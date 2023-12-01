/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdcadd_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:21:29 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/30 15:21:17 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstdcadd_front(t_dclist **list, t_dclist *new_node)
{
	if (!new_node)
		return ;
	else if (!*list)
	{
		*list = new_node;
		new_node->next = NULL;
		new_node->prev = NULL;
	}
	else if ((*list)->next == NULL)
	{
		(*list)->next = new_node;
		(*list)->prev = new_node;
		new_node->prev = *list;
		new_node->next = *list;
	}
	else
	{
		new_node->prev = (*list)->prev;
		new_node->next = *list;
		(*list)->prev->next = new_node;
		(*list)->prev = new_node;
	}
	*list = new_node;
	return ;
}
