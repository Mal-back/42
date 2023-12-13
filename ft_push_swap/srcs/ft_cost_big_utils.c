/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost_big_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:37:40 by purmerinos        #+#    #+#             */
/*   Updated: 2023/12/13 22:37:41 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	resolve_direction_b(int go_cost, int go_back_cost,
	t_data_info *data_info)
{
	if (go_cost > go_back_cost)
	{
		data_info->cost_to_rotate_b = go_cost;
		data_info->direction_b = 0;
	}
	else
	{
		data_info->cost_to_rotate_b = go_back_cost;
		data_info->direction_b = 1;
	}
}

void	resolve_cost(t_data_info *data_info)
{
	if (data_info->direction_a != data_info->direction_b)
		data_info->final_cost = data_info->cost_to_rotate_b
			+ data_info->cost_to_rotate_b;
	else
	{
		if (data_info->cost_to_rotate_b > data_info->cost_to_rotate_a)
			data_info->final_cost = data_info->cost_to_rotate_a
				+ (data_info->cost_to_rotate_b - data_info->cost_to_rotate_a);
		else
			data_info->final_cost = data_info->cost_to_rotate_b
				+ (data_info->cost_to_rotate_a - data_info->cost_to_rotate_b);
	}
}

void	combine_rotate(t_dclist **list_a, t_dclist **list_b,
	t_data_info *data_info)
{
	if (!data_info->direction_b)
	{
		while ((*list_b)->data != data_info->value
			&& (*list_a)->data < data_info->value)
			ft_rr(list_a, list_b);
		while ((*list_b)->data != data_info->value)
			ft_rb(list_b, 1);
		while ((*list_a)->data < data_info->value)
			ft_ra(list_a, 1);
	}
	else
	{
		while ((*list_b)->data != data_info->value
			&& (*list_a)->prev->data > data_info->value)
			ft_rrr(list_a, list_b);
		while ((*list_b)->data != data_info->value)
			ft_rrb(list_b, 1);
		while ((*list_a)->prev->data > data_info->value)
			ft_rra(list_a, 1);
	}
}

void	ft_cost_to_go_a(t_dclist **list_a, t_data_info *data_info)
{
	t_dclist	*head;

	data_info->cost_to_rotate_a = 0;
	if ((*list_a)->data < data_info->min || (*list_a)->data > data_info->max)
		data_info->direction_a = 0;
	else if ((*list_a)->data > data_info->value)
	{
		data_info->direction_a = 1;
		while ((*list_a)->prev->data > data_info->value)
		{
			data_info->cost_to_rotate_a += 1;
			*list_a = (*list_a)->prev;
		}
	}
	else
	{
		data_info->direction_a = 0;
		while ((*list_a)->data < data_info->value)
		{
			data_info->cost_to_rotate_a += 1;
			*list_a = (*list_a)->next;
		}
	}
	*list_a = head;
}

void	ft_cost_to_go_b(t_dclist **list_b, int number,
	int *go_cost, int *go_back_cost)
{
	t_dclist	*head;

	head = *list_b;
	*go_cost = 0;
	*go_back_cost = 0;
	while ((*list_b)->data != number)
	{
		*go_cost += 1;
		*list_b = (*list_b)->next;
	}
	*list_b = head;
	while ((*list_b)->data != number)
	{
		go_back_cost += 1;
		*list_b = (*list_b)->prev;
	}
	*list_b = head;
}
