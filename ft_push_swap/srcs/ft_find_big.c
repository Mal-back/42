/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:29:57 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/07 17:12:52 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_find_big(t_dclist **list)
{
	long		big;
	t_dclist	*head;

	head = *list;
	big = (*list)->data;
	if (!(*list)->next)
		return (big);
	else
		*list = (*list)->next;
	while (*list != head)
	{
		if ((*list)->data > big)
			big = (*list)->data;
		*list = (*list)->next;
	}
	return (big);
}
