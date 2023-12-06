/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:11:42 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/06 21:23:39 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_bubble_up(t_dclist **list_a, t_dclist **list_b,
	t_dclist **head_a, t_dclist **head_b)
{
	while (*list_a != *head_a)
	{
		if (*list_b != *head_b)
			ft_rrr(list_a, list_b);
		else
			ft_rra(list_a, 1);
		if (need_to_swap(list_a) && !need_to_swap(list_b) && *list_b != *head_b)
			ft_ss(list_a, list_b);
		else if (need_to_swap(list_a))
			ft_sa(list_a, 1);
		else if (!need_to_swap(list_b) && *list_b != *head_b)
			ft_sb(list_b, 1);
	}
}

static void	ft_bubble_down(t_dclist **list_a, t_dclist **list_b,
	t_dclist **tail_a, t_dclist **tail_b)
{
	while (*list_a != *tail_a)
	{
		if (need_to_swap(list_a) && !need_to_swap(list_b) && *list_b != *tail_b)
			ft_ss(list_a, list_b);
		else if (need_to_swap(list_a))
			ft_sa(list_a, 1);
		else if (!need_to_swap(list_b) && *list_b != *tail_b)
			ft_sb(list_b, 1);
		if (*list_b != *tail_b)
			ft_rr(list_a, list_b);
		else
			ft_ra(list_a, 1);
	}
}

static void	rotate_to_good_place(t_dclist **list_a, t_dclist **list_b)
{
	while (before_is_smaller(list_a) && !before_is_smaller(list_b))
		ft_rrr(list_a, list_b);
	while (before_is_smaller(list_a))
		ft_rra(list_a, 1);
	while (!before_is_smaller(list_b))
		ft_rrb(list_b, 1);
}

void	ft_bubble_sort(t_dclist **list_a, t_dclist **list_b)
{
	t_dclist	*head_a;
	t_dclist	*head_b;
	t_dclist	*tail_a;
	t_dclist	*tail_b;

	head_a = *list_a;
	tail_a = (*list_a)->prev;
	head_b = *list_b;
	tail_b = (*list_b)->prev;
	while (head_a != tail_a)
	{
		ft_bubble_down(list_a, list_b, &tail_a, &tail_b);
		if (tail_a == head_a)
			break ;
		else
			tail_a = tail_a->prev;
		if (tail_b != head_b)
			tail_b = tail_b->prev;
		ft_bubble_up(list_a, list_b, &head_a, &head_b);
		if (head_a == tail_a)
			break ;
		else
			head_a = head_a->next;
		if (head_b != tail_b)
			head_b = head_b ->next;
	}
	rotate_to_good_place(list_a, list_b);
}
