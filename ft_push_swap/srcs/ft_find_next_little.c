/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_little.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:57:55 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/07 13:30:57 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_find_next_little(t_dclist *list_a, long little)
{
	t_dclist	*next_little;
	t_dclist	*head_a;

	if (list_a->data != little)
		next_little = list_a;
	else
		next_little = list_a->next;
	head_a = list_a;
	while (list_a->next != head_a)
	{
		if (list_a->data != little && list_a->data < next_little->data)
			next_little = list_a;
		list_a = list_a->next;
	}
	if (list_a->data != little && list_a->data < next_little->data)
		next_little = list_a;
	list_a = list_a->next;
	return (next_little->data);
}
