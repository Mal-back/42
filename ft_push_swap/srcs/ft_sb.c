/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:35:49 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/25 19:32:18 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_sb(t_dclist **list_b, int f)
{
	t_dclist	*tmp;

	if (!list_b)
		return ;
	tmp = *list_b;
	if (tmp->next == NULL)
		return ;
	if (f)
		ft_putendl_fd("sb", 1);
	(*list_b)->next->prev = tmp->prev;
	(*list_b)->next->next = tmp;
	(*list_b)->prev = tmp->next;
	(*list_b)->next = tmp->next->next;
	*list_b = tmp;
	return ;
}
