/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_reverse_sorted.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:54:47 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/07 18:00:56 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_reverse_sorted(t_dclist *list)
{
	t_dclist	*head;

	if (!list)
		return (1);
	head = list;
	if (list->next == NULL)
		return (1);
	while (list->next != head)
	{
		if (list->data < list->next->data)
			return (0);
		list = list->next;
	}
	return (1);
}
