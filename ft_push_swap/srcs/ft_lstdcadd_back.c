/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdcadd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:33:12 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/25 21:45:35 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstdcadd_back(t_dclist **lst, t_dclist *new_node)
{
	t_dclist	*tmp;

	if (!lst || !new_node)
		return ;
	if (*lst == NULL)
	{
		*lst = new_node;
		return ;
	}
	tmp = *lst;
	if (tmp->next == NULL)
	{
		tmp->next = new_node;
		tmp->prev = new_node;
		new_node->prev = tmp;
		new_node->next = tmp;
		return ;
	}
	while (tmp->next != *lst)
		tmp = tmp->next;
	new_node->prev = tmp;
	tmp->next = new_node;
	new_node->next = *lst;
	return ;
}
