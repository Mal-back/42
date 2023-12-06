/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:32:54 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/06 21:22:52 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_bubble_up(t_dclist **list_b, t_dclist **list_a,
	t_dclist **head_b, t_dclist **head_a)
{
	while (*list_b != *head_b)
	{
		if (*list_a != *head_a)
			ft_rrr(list_a, list_b);
		else
			ft_rrb(list_b, 1);
		if (!need_to_swap(list_b) && need_to_swap(list_a) && *list_a != *head_a)
			ft_ss(list_a, list_b);
		else if (!need_to_swap(list_b))
			ft_sb(list_b, 1);
		else if (need_to_swap(list_a) && *list_a != *head_a)
			ft_sa(list_a, 1);
	}
}

static void	ft_bubble_down(t_dclist **list_b, t_dclist **list_a,
	t_dclist **tail_b, t_dclist **tail_a)
{
	while (*list_b != *tail_b)
	{
		if (!need_to_swap(list_b) && need_to_swap(list_a) && *list_a != *tail_a)
			ft_ss(list_a, list_b);
		else if (!need_to_swap(list_b))
			ft_sb(list_b, 1);
		else if (need_to_swap(list_a) && *list_a != *tail_a)
			ft_sa(list_a, 1);
		if (*list_a != *tail_a)
			ft_rr(list_a, list_b);
		else
			ft_rb(list_b, 1);
	}
}

static void	ft_rotate_to_good_place(t_dclist **list_b, t_dclist **list_a)
{
	while (!before_is_smaller(list_b) && before_is_smaller(list_a))
		ft_rrr(list_a, list_b);
	while (!before_is_smaller(list_b))
		ft_rrb(list_b, 1);
	while (before_is_smaller(list_a))
		ft_rra(list_a, 1);
}

void	ft_bubble_sort_b(t_dclist **list_b, t_dclist **list_a)
{
	t_dclist	*head_b;
	t_dclist	*head_a;
	t_dclist	*tail_b;
	t_dclist	*tail_a;

	head_b = *list_b;
	head_a = *list_a;
	tail_b = (*list_b)->prev;
	tail_a = (*list_a)->prev;
	while (head_b != tail_b)
	{
		ft_bubble_down(list_b, list_a, &tail_b, &tail_a);
		if (tail_b == head_b)
			break ;
		else
			tail_b = tail_b->prev;
		if (tail_a != head_a)
			tail_a = tail_a->prev;
		ft_bubble_up(list_b, list_a, &head_b, &head_b);
		if (head_b == tail_b)
			break ;
		else
			head_b = head_b->next;
		if (head_a != tail_a)
			head_a = head_a->next;
	}
	ft_rotate_to_good_place(list_b, list_a);
}
