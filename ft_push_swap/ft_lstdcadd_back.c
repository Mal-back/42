/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdcadd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:33:12 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/24 14:51:51 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstdcadd_back(tdc_list **lst, tdc_list *new_node)
{
	tdc_list	*tmp;

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
	new_node->prev = tmp->prev;
	tmp->prev->next = new_node;
	tmp->prev = new_node;
	new_node->next = tmp;
	return ;
}
