/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_lstdc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:31:06 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/26 20:50:04 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_update_lstdc(t_dclist **list)
{
	t_dclist	*tmp;

	tmp = (*list)->prev;
	if (!*list || !(*list)->next)
		return ;
	else if ((*list)->next == *list)
	{
		(*list)->next = NULL;
		(*list)->prev = NULL;
		*list = NULL;
	}
	else
	{
		*list = (*list)->next;
		(*list)->prev = tmp;
		tmp->next = *list;
	}
	return ;
}
