/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_if_above_median.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:11:47 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/06 21:42:31 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	ft_rotate_to_good_place(t_dclist **list_b, t_dclist **head_b)
{
	if ((*list_b)->next == *head_b)
		ft_rrb(list_b, 1);
	while (*list_b != *head_b)
	{
		if (!need_to_swap(list_b))
			ft_sb(list_b, 1);
		ft_rrb(list_b, 1);
	}
	if (!need_to_swap(list_b))
		ft_sb(list_b, 1);
}

// static void	ft_opportunist_sort(t_dclist **list_a, t_dclist **list_b,
// 	t_dclist **head_b, int median)
// {
// 	int	a_is_gt_1;
//
// 	a_is_gt_1 = 0;
// 	if ((*list_b)->next == *head_b)
// 		return ;
// 	if (ft_lst_dcsize(*list_b) > 1)
// 		a_is_gt_1++;
// 	if ((*list_b)->data <= median && (*list_b)->next->data <= median
// 		&& !need_to_swap(list_b) && need_to_swap(list_a) && a_is_gt_1)
// 		ft_ss(list_a, list_b);
// 	else if ((*list_b)->data > median && (*list_b)->next->data > median
// 		&& !need_to_swap(list_b) && need_to_swap(list_a) && a_is_gt_1)
// 		ft_ss(list_a, list_b);
// 	else if ((*list_b)->data <= median && (*list_b)->next->data <= median
// 		&& !need_to_swap(list_b))
// 		ft_sb(list_b, 1);
// 	else if ((*list_b)->data > median && (*list_b)->next->data > median
// 		&& !need_to_swap(list_b))
// 		ft_sb(list_b, 1);
// 	else if (need_to_swap(list_a) && a_is_gt_1)
// 		ft_sa(list_a, 1);
// }

static t_dclist	*last_element_to_push(t_dclist **list_b, int median)
{
	t_dclist	*head;
	t_dclist	*tail;

	head = *list_b;
	tail = *list_b;
	*list_b = (*list_b)->next;
	while (*list_b != head)
	{
		if ((*list_b)->data > median)
			tail = *list_b;
		*list_b = (*list_b)->next;
	}
	return (tail);
}

void	ft_push_if_above_median(t_dclist **list_a, t_dclist **list_b,
		int median, int absolute_size)
{
	t_dclist	*head_b;
	t_dclist	*tail_b;
	int			local_size;

	tail_b = last_element_to_push(list_b, median);
	head_b = *list_b;
	local_size = ft_lst_dcsize(*list_b);
	while (*list_b != tail_b)
	{
	// ft_opportunist_sort(list_a, list_b, &head_b, median);
		if ((*list_b)->data > median)
		{
			if (*list_b == head_b)
				head_b = (*list_b)->next;
			ft_pa(list_a, list_b);
		}
		else
			ft_rb(list_b, 1);
	}
	if ((*list_b) != head_b)
	{
		ft_pa(list_a, list_b);
		ft_rrb(list_b, 1);
	}
	if (local_size != absolute_size)
		ft_rotate_to_good_place(list_b, &head_b);
}
