/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:01:07 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/25 19:39:14 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_sa(t_dclist **list_a, int f)
{
	t_dclist	*tmp;

	if (!list_a)
		return ;
	tmp = *list_a;
	if (tmp->next == NULL)
		return ;
	if (f)
		ft_putendl_fd("sa", 1);
	(*list_a)->next->prev = tmp->prev;
	(*list_a)->next->next = tmp;
	(*list_a)->prev = tmp->next;
	(*list_a)->next = tmp->next->next;
	*list_a = tmp;
	return ;
}
