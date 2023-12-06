/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:29:57 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/05 20:39:15 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dclist	*ft_find_big(t_dclist **list)
{
	t_dclist	*big;
	t_dclist	*head;

	big = *list;
	*list = (*list)->next;
	head = *list;
	while ((*list)->next != head)
	{
		if ((*list)->data > big->data)
			big = *list;
		*list = (*list)->next;
	}
	return (big);
}
