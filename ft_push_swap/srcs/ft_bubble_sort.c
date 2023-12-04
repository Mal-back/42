/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:11:42 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/04 20:58:53 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	need_to_push_back_tail(t_dclist **src, t_dclist **dest)
{
	if (!*src)
		return (0);
	if ((*src)->data > (*dest)->data)
		return (1);
	return (0);
}

int	need_to_push_back_head(t_dclist **src, t_dclist **dest)
{
	if (!*src)
		return (0);
	if ((*src)->data < (*dest)->data)
		return (1);
	return (0);
}

int	before_is_smaller(t_dclist **list)
{
	if (!*list || !(*list)->next)
		return (0);
	if ((*list)->prev->data < (*list)->data)
		return (1);
	return (0);
}

int	after_is_bigger(t_dclist **list)
{
	if (!*list || !(*list)->next)
		return (0);
	if ((*list)->next->data > (*list)->data)
		return (1);
	return (0);
}

void	ft_bubble_up(t_dclist **list_a, t_dclist **list_b,
	t_dclist **head_a, t_dclist **head_b)
{
	while (*list_a != *head_a)
	{
		if (*list_b != *head_b)
			ft_rrr(list_a, list_b);
		else
			ft_rra(list_a, 1);
		if (need_to_swap(list_a) && need_to_swap(list_b))
			ft_ss(list_a, list_b);
		else if (need_to_swap(list_a))
			ft_sa(list_a, 1);
		else if (need_to_swap(list_b))
			ft_sb(list_b, 1);
	}
}

void	ft_bubble_down(t_dclist **list_a, t_dclist **list_b,
	t_dclist **tail_a, t_dclist **tail_b)
{
	while (*list_a != *tail_a)
	{
		if (need_to_swap(list_a) && need_to_swap(list_b))
			ft_ss(list_a, list_b);
		else if (need_to_swap(list_a))
			ft_sa(list_a, 1);
		else if (need_to_swap(list_b))
			ft_sb(list_b, 1);
		if (*list_b != *tail_b)
			ft_rr(list_a, list_b);
		else
			ft_ra(list_a, 1);
	}
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
		tail_a = tail_a->prev;
		if (tail_b->prev)
			tail_b = tail_b->prev;
		ft_bubble_up(list_a, list_b, &head_a, &head_b);
		if (head_a != tail_a)
		{
			head_a = head_a->next;
			if (head_b->next != NULL)
				head_b = head_b->next;
		}
	}
	while (before_is_smaller(list_a))
	{
		ft_rra(list_a, 1);
	}
}
