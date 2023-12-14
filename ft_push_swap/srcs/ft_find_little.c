/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_little.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:27:35 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/07 15:30:23 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_find_little(t_dclist **list_a)
{
	t_dclist	*little;
	t_dclist	*head_a;

	little = *list_a;
	head_a = *list_a;
	if (!(*list_a)->next)
		return ((*list_a)->data);
	else
		*list_a = (*list_a)->next;
	while (*list_a != head_a)
	{
		if ((*list_a)->data < little->data)
			little = *list_a;
		*list_a = (*list_a)->next;
	}
	return (little->data);
}
