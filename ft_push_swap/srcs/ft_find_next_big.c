/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_big.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:13:22 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/07 17:19:46 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_find_next_big(t_dclist **list, long big)
{
	long		next_big;
	t_dclist	*head;

	head = *list;
	next_big = -2147483648;
	if ((*list)->data > next_big && (*list)->data < big)
		next_big = (*list)->data;
	*list = (*list)->next;
	while (*list != head)
	{
		if ((*list)->data < big && (*list)->data > next_big)
			next_big = (*list)->data;
		*list = (*list)->next;
	}
	return (next_big);
}
