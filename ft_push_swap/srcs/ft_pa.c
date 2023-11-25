/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:55:20 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/25 19:19:16 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_pa(t_dclist **list_a, t_dclist **list_b)
{
	if (!*list_b)
		return ;
	ft_printf("pa\n");
	if (*list_a == NULL)
	{
		*list_a = *list_b;
		*list_b = (*list_b)->next;
		return ;
	}
	(*list_a)->prev->next = *list_b;
	(*list_a)->prev = *list_b;
	(*list_b)->next = *list_a;
	(*list_b)->prev = (*list_a)->prev;
	*list_a = *list_b;
	*list_b = (*list_b)->next;
}
