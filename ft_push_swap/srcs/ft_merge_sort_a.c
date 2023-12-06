/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_sort_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:30:15 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/05 18:31:16 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_merge_sort_a(t_dclist **list_a, int size_a, int size_b)
{
	t_dclist	*list_b;
	int			local_size_a;
	int			i;

	local_size_a = ft_lst_dcsize(*list_a);
	list_b = NULL;
	i = 0;
	while (i < local_size_a / 2)
	{
		ft_pb(&list_b, list_a);
		i++;
	}
	if (local_size_a > 20)
	{
		ft_merge_sort_a(list_a, size_a, size_b);
		ft_merge_sort_b(&list_b, size_a, size_b);
	}
	else
		ft_bubble_sort(list_a, &list_b);
	ft_resolve_a(list_a, &list_b, size_a);
}
