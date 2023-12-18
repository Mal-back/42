/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:55:20 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/02 17:04:55 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_dclist **list_a, t_dclist **list_b)
{
	t_dclist	*tmp;

	tmp = *list_b;
	if (!list_b || !*list_b)
		return ;
	ft_printf("pa\n");
	ft_update_lstdc(list_b);
	ft_lstdcadd_front(list_a, tmp);
	return ;
}
