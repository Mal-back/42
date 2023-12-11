/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_final_sort_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:21:55 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/07 18:51:22 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_sort_info_b(t_dclist **list_b, t_sort_info_b *sort_info,
	int need_to_push_big)
{
	sort_info->big = ft_find_big(list_b);
	sort_info->next_big = ft_find_next_big(list_b, sort_info->big);
	sort_info->push_big_is_mandatory = need_to_push_big;
}

static void	ft_rotate_and_merge(t_dclist **list_b, t_dclist **list_a,
	t_dclist **head_b)
{
	while (*list_b != *head_b)
	{
		if (*list_a && (*list_b)->prev->data > (*list_a)->data)
			ft_pb(list_b, list_a);
		ft_rrb(list_b, 1);
	}
	if (!ft_is_reverse_sorted(*list_b) && need_to_swap(list_a))
		ft_ss(list_a, list_b);
	else if (!ft_is_reverse_sorted(*list_b))
		ft_sb(list_b, 1);
	else if (need_to_swap(list_a))
		ft_sa(list_a, 1);
	if (*list_a && (*list_b)->data > (*list_a)->data)
	{
		ft_rb(list_b, 1);
		ft_pb(list_b, list_a);
		ft_rrb(list_b, 1);
	}
	ft_merge_to_b(list_a, list_b);
}

void	final_sort_b(t_dclist **list_b, t_dclist **list_a)
{
	t_dclist		*head_b;
	t_dclist		*tail_b;
	t_sort_info_b	sort_info;

	init_sort_info_b(list_b, &sort_info, 0);
	head_b = *list_b;
	tail_b = (*list_b)->prev;
	while (!ft_is_reverse_sorted(head_b) && ft_lst_dcsize(*list_b) != 2)
	{
		while (!ft_is_reverse_sorted(head_b) && ft_lst_dcsize(*list_b) != 2
			&& *list_b != tail_b)
			sort_down_b(list_b, list_a, &head_b, &sort_info);
		while (!ft_is_reverse_sorted(head_b) && ft_lst_dcsize(*list_b) != 2
			&& *list_b != head_b)
			sort_up_b(list_b, list_a, &tail_b, &sort_info);
	}
	ft_rotate_and_merge(list_b, list_a, &head_b);
	return ;
}
