/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_final_sort_a_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:16:49 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/07 19:12:25 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_down_a_next(t_dclist **list_a, t_dclist **list_b,
	t_dclist **head_a, t_sort_info_a *sort_info)
{
	if ((*list_a)->data == sort_info->little)
	{
		if (*list_a == *head_a)
			*head_a = (*head_a)->next;
		if (!need_to_swap(list_b) && ft_lst_dcsize(*list_b) > 2)
			ft_sb(list_b, 1);
		ft_pb(list_b, list_a);
		init_sort_info_a(list_a, sort_info, 0);
	}
	else if ((*list_a)->data == sort_info->next_little
		&& !sort_info->push_little_is_mandatory)
	{
		if (*list_a == *head_a)
			*head_a = (*list_a)->next;
		if (!need_to_swap(list_b) && ft_lst_dcsize(*list_b) > 2)
			ft_sb(list_b, 1);
		ft_pb(list_b, list_a);
		init_sort_info_a(list_a, sort_info, 1);
	}
	else
		ft_ra(list_a, 1);
	return ;
}

void	sort_down_a(t_dclist **list_a, t_dclist **list_b,
		t_dclist **head_a, t_sort_info_a *sort_info)
{
	if (need_to_swap(list_a) && !need_to_swap(list_b)
		&& ft_lst_dcsize(*list_b) > 1)
	{
		ft_ss(list_a, list_b);
		sort_info->push_little_is_mandatory = 0;
	}
	else if (need_to_swap(list_a))
		ft_sa(list_a, 1);
	else if (!need_to_swap(list_b) && ft_lst_dcsize(*list_b) > 1)
	{
		ft_sb(list_b, 1);
		sort_info->push_little_is_mandatory = 0;
	}
	else
		sort_down_a_next(list_a, list_b, head_a, sort_info);
	return ;
}

static void	sort_up_a_next(t_dclist **list_a, t_dclist **list_b,
	t_dclist **tail_a, t_sort_info_a *sort_info)
{
	if ((*list_a)->data == sort_info->little)
	{
		if (*list_a == *tail_a)
			*tail_a = (*tail_a)->prev;
		ft_pb(list_b, list_a);
		init_sort_info_a(list_a, sort_info, 0);
		ft_rra(list_a, 1);
	}
	else if ((*list_a)->data == sort_info->next_little
		&& !sort_info->push_little_is_mandatory)
	{
		if (*list_a == *tail_a)
			*tail_a = (*tail_a)->prev;
		ft_pb(list_b, list_a);
		init_sort_info_a(list_a, sort_info, 1);
		ft_rra(list_a, 1);
	}
	else
		ft_rra(list_a, 1);
	return ;
}

void	sort_up_a(t_dclist **list_a, t_dclist **list_b,
	t_dclist **tail_a, t_sort_info_a *sort_info)
{
	if (need_to_swap(list_a) && *list_a != *tail_a
		&& !need_to_swap(list_b) && ft_lst_dcsize(*list_b) > 1)
	{
		ft_ss(list_a, list_b);
		sort_info->push_little_is_mandatory = 0;
	}
	else if (need_to_swap(list_a) && *list_a != *tail_a)
		ft_sa(list_a, 1);
	else if (!need_to_swap(list_b) && ft_lst_dcsize(*list_b) > 1)
	{
		ft_sb(list_b, 1);
		sort_info->push_little_is_mandatory = 0;
	}
	else
		sort_up_a_next(list_a, list_b, tail_a, sort_info);
	return ;
}
