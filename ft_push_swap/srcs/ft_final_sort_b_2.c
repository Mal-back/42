/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_final_sort_b_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:43:15 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/07 19:19:16 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_down_b_next(t_dclist **list_b, t_dclist **list_a,
	t_dclist **head_b, t_sort_info_b *sort_info)
{
	if ((*list_b)->data == sort_info->big)
	{
		if (*list_b == *head_b)
			*head_b = (*head_b)->next;
		if (need_to_swap(list_a) && ft_lst_dcsize(*list_a) > 2)
			ft_sa(list_a, 1);
		ft_pa(list_a, list_b);
		init_sort_info_b(list_b, sort_info, 0);
	}
	else if ((*list_b)->data == sort_info->next_big
		&& !sort_info->push_big_is_mandatory)
	{
		if (*list_b == *head_b)
			*head_b = (*head_b)->next;
		if (need_to_swap(list_a) && ft_lst_dcsize(*list_a) > 2)
			ft_sa(list_a, 1);
		ft_pa(list_a, list_b);
		init_sort_info_b(list_b, sort_info, 1);
	}
	else
		ft_rb(list_b, 1);
	return ;
}

void	sort_down_b(t_dclist **list_b, t_dclist **list_a,
	t_dclist **head_b, t_sort_info_b *sort_info)
{
	if (!need_to_swap(list_b) && need_to_swap(list_a)
		&& ft_lst_dcsize(*list_a) > 1)
	{
		ft_ss(list_a, list_b);
		sort_info->push_big_is_mandatory = 0;
	}
	else if (!need_to_swap(list_b))
		ft_sb(list_b, 1);
	else if (need_to_swap(list_a) && ft_lst_dcsize(*list_a) > 1)
	{
		ft_sa(list_a, 1);
		sort_info->push_big_is_mandatory = 0;
	}
	else
		sort_down_b_next(list_b, list_a, head_b, sort_info);
	return ;
}

void	sort_up_b_next(t_dclist **list_b, t_dclist **list_a,
	t_dclist **tail_b, t_sort_info_b *sort_info)
{
	if ((*list_b)->data == sort_info->big)
	{
		if (*list_b == *tail_b)
			*tail_b = (*tail_b)->prev;
		ft_pa(list_a, list_b);
		init_sort_info_b(list_b, sort_info, 0);
		ft_rrb(list_b, 1);
	}
	else if ((*list_b)->data == sort_info->next_big
		&& !sort_info->push_big_is_mandatory)
	{
		if (*list_b == *tail_b)
			*tail_b = (*tail_b)->prev;
		ft_pa(list_a, list_b);
		init_sort_info_b(list_b, sort_info, 1);
		ft_rrb(list_b, 1);
	}
	else
		ft_rrb(list_b, 1);
}

void	sort_up_b(t_dclist **list_b, t_dclist **list_a,
	t_dclist **tail_b, t_sort_info_b *sort_info)
{
	if (!need_to_swap(list_b) && *list_b != *tail_b
		&& need_to_swap(list_a) && ft_lst_dcsize(*list_a) > 1)
	{
		ft_ss(list_a, list_b);
		sort_info->push_big_is_mandatory = 0;
	}
	else if (!need_to_swap(list_b) && *list_b != *tail_b)
	{
		ft_sb(list_b, 1);
		sort_info->push_big_is_mandatory = 0;
	}
	else if (need_to_swap(list_a) && ft_lst_dcsize(*list_a) > 1)
		ft_sa(list_a, 1);
	else
		sort_up_b_next(list_b, list_a, tail_b, sort_info);
	return ;
}
