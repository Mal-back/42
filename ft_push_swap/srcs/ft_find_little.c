/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_little.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:27:35 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/27 18:36:45 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dclist	*ft_find_little(t_dclist **list_a)
{
	t_dclist	*head_a;
	t_dclist	*little;

	little = *list_a;
	head_a = (*list_a)->next;
	*list_a = (*list_a)->next;
	while ((*list_a)->next != head_a)
	{
		if ((*list_a)->data < little->data)
			little = *list_a;
		*list_a = (*list_a)->next;
	}
	return (little);
}
