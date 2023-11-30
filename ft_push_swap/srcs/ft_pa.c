/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:55:20 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/30 12:48:22 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_pa(t_dclist **list_a, t_dclist **list_b)
{
	t_dclist	*tmp;

	tmp = *list_b;
	if (!list_b || !*list_b)
		return ;
	ft_putendl_fd("pa", 1);
	ft_update_lstdc(list_b);
	tmp->prev = NULL;
	tmp->next = NULL;
	ft_lstdcadd_front(list_a, tmp);
	return ;
}
