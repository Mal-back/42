/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:59:29 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/07 15:30:56 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_give_index(t_dclist **list_a)
{
	t_dclist	*head;
	long		little;
	long		big;
	int			i;

	head = *list_a;
	i = 0;
	little = ft_find_little(list_a);
	big = ft_find_big(list_a);
	while (little != big)
	{
		while ((*list_a)->data != little)
			*list_a = (*list_a)->next;
		(*list_a)->end_place = i;
		little = ft_find_next_little(*list_a, little);
		i++;
	}
	while ((*list_a)->data != little)
		*list_a = (*list_a)->next;
	(*list_a)->end_place = i;
	*list_a = head;
}

static void	init_list_b(t_dclist **list_b)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		list_b[i] = NULL;
		i++;
	}
}

void	ft_quick_sort_init(t_dclist **list_a, int absolute_size_a)
{
	t_dclist	*list_b;
	int			limit;
	int			i;

	list_b = NULL;
	limit = ft_lst_dcsize(*list_a) / 4;
	i = 3;
	while (i--)
	{
		ft_push_init(list_a, &list_b, limit * i);
		smart_push_back(list_a, &list_b);
	}
}
