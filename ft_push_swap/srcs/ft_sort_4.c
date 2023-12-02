/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:18:31 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/02 22:31:02 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_4(t_dclist **list_a)
{
	t_dclist	*list_b;
	t_dclist	*little;

	little = ft_find_little(list_a);
	list_b = NULL;
	if (*list_a == little)
		ft_pb(&list_b, list_a);
	else if ((*list_a)->next == little)
	{
		ft_ra(list_a, 1);
		ft_pb(&list_b, list_a);
	}
	else if ((*list_a)->prev == little)
	{
		ft_rra(list_a, 1);
		ft_pb(&list_b, list_a);
	}
	else
	{
		ft_ra(list_a, 1);
		ft_ra(list_a, 1);
		ft_pb(&list_b, list_a);
	}
	ft_sort_3(list_a);
	ft_pa(list_a, &list_b);
}
