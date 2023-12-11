/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_final_sort_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:48:53 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/07 18:27:06 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_sort_info_a(t_dclist **list_a, t_sort_info_a *sort_info,
	int push_little_is_mandatory)
{
	sort_info->little = ft_find_little(list_a);
	sort_info->next_little = ft_find_next_little(*list_a, sort_info->little);
	sort_info->push_little_is_mandatory = push_little_is_mandatory;
}

static void	ft_rotate_and_merge(t_dclist **list_a, t_dclist **list_b,
	t_dclist **head_a)
{
	while (*list_a != *head_a)
	{
		if (*list_b && (*list_a)->data < (*list_b)->data)
			ft_pa(list_a, list_b);
		ft_rra(list_a, 1);
	}
	if (!ft_is_sorted(*list_a) && !need_to_swap(list_b))
		ft_ss(list_a, list_b);
	else if (!ft_is_sorted(*list_a))
		ft_sa(list_a, 1);
	else if (!need_to_swap(list_b))
		ft_sb(list_b, 1);
	if (*list_b && (*list_a)->data < (*list_b)->data)
	{
		ft_ra(list_a, 1);
		ft_pa(list_a, list_b);
		ft_rra(list_a, 1);
	}
	ft_merge_to_a(list_a, list_b);
	return ;
}

void	final_sort_a(t_dclist **list_a, t_dclist **list_b)
{
	t_sort_info_a	sort_info;
	t_dclist		*head_a;
	t_dclist		*tail_a;

	init_sort_info_a(list_a, &sort_info, 0);
	head_a = *list_a;
	tail_a = (*list_a)->prev;
	while (!ft_is_sorted(head_a) && ft_lst_dcsize(*list_a) != 2)
	{
		while (!ft_is_sorted(head_a) && ft_lst_dcsize(*list_a) != 2
			&& *list_a != tail_a)
			sort_down_a(list_a, list_b, &head_a, &sort_info);
		while (!ft_is_sorted(head_a) && ft_lst_dcsize(*list_a) != 2
			&& *list_a != head_a)
			sort_up_a(list_a, list_b, &tail_a, &sort_info);
	}
	ft_rotate_and_merge(list_a, list_b, &head_a);
	return ;
}
