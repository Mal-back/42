/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:12:45 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/24 18:31:26 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_pb(tdc_list **list_b, tdc_list **list_a)
{
	if (!*list_a)
		return ;
	ft_putendl_fd("pb", 1);
	if (*list_b == NULL)
	{
		*list_b = *list_a;
		*list_a = (*list_a)->next;
		return ;
	}
	(*list_b)->prev->next = *list_a;
	(*list_b)->prev = *list_a;
	(*list_a)->next = *list_b;
	(*list_a)->prev = (*list_b)->prev;
	*list_b = *list_a;
	*list_a = (*list_a)->next;
}
