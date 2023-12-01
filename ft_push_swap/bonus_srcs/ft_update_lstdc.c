/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_lstdc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:31:06 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/30 13:14:50 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_update_lstdc(t_dclist **list)
{
	t_dclist	*tmp;

	tmp = (*list)->prev;
	if (!*list)
		return ;
	else if ((*list)->next == NULL)
		*list = NULL;
	else if ((*list)->next == tmp)
	{
		tmp->next = NULL;
		tmp->prev = NULL;
		*list = tmp;
	}
	else
	{
		(*list)->next->prev = tmp;
		tmp->next = (*list)->next;
		*list = (*list)->next;
	}
	return ;
}
