/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_sort_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:14:06 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/03 21:12:13 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <threads.h>

void	ft_merge_sort_b(t_dclist **list_b, int size_a, int size_b)
{
	t_dclist	*list_a;
	int			local_size_b;
	int			i;

	local_size_b = ft_lst_dcsize(*list_b);
	list_a = NULL;
	i = 0;
	if (local_size_b > 3)
	{
		while (i < local_size_b / 2)
		{
			ft_pa(&list_a, list_b);
			i++;
		}
		ft_merge_sort_b(list_b, size_a, size_b);
		ft_merge_sort_a(&list_a, size_a, size_b);
		ft_resolve_b(&list_a, list_b, size_a);
	}
	else
		ft_manual_sort(list_b, local_size_b);
}
