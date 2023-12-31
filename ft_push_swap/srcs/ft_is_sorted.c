/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:31:08 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/07 17:57:38 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_dclist *list)
{
	t_dclist	*head_list;

	if (!list)
		return (1);
	head_list = list;
	if (list->next == NULL)
		return (1);
	while (list->next && list->next != head_list)
	{
		if (list->data > list->next->data)
			return (0);
		list = list->next;
	}
	return (1);
}
