/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_median_of_three.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:19:05 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/29 19:44:27 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_median_of_three(t_dclist *list, int lst_size)
{
	long	first;
	long	middle;
	long	last;
	int		i;

	first = list->data;
	last = list->prev->data;
	i = 0;
	while (i < lst_size / 2)
	{
		list = list->next;
		i++;
	}
	middle = list->data;
	if ((first > last && first < middle) || (first < last && first > middle))
		return (first);
	else if ((middle > first && middle < last)
		|| (middle < first && middle > last))
		return (middle);
	return (last);
}
