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

static void	go_good_place(t_dclist **list_a, int target, int size)
{
	int			i;
	t_dclist	*head;

	head = *list_a;
	i = 0;
	// ft_printf("Jsuis la lol\n");
	while ((*list_a)->end_place != target)
	{
		*list_a = (*list_a)->next;
		i++;
	}	
	*list_a = head;
	while ((*list_a)->end_place != target)
	{
		if (i < size / 2)
			ft_ra(list_a, 1);
		else
			ft_rra(list_a, 1);
	}
	if (target)
		ft_ra(list_a, 1);
}

void	ft_quick_sort_init(t_dclist **list_a, int absolute_size_a)
{
	t_dclist	*list_b;
	int			limit;
	int			upper_limit;
	int			i;

	list_b = NULL;
	limit = absolute_size_a / 5;
	ft_give_index(list_a);
	i = 5;
	while (i)
	{
		if (i == 5)
			upper_limit = absolute_size_a;
		else
			upper_limit = limit * i;
		ft_push_init(list_a, &list_b, limit * (i - 1), upper_limit);
		smart_push_back(list_a, &list_b);
		if (i > 1)
			go_good_place(list_a, absolute_size_a - 1, absolute_size_a);
		else
			go_good_place(list_a, 0, absolute_size_a);
		i--;
	}
	// ft_print_test(*list_a);
}
