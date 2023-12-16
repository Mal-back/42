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
	if (go_cost < go_back_cost)
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

int	is_in_range(t_dclist **list_a, t_data_info *data_info)
{
	if ((*list_a)->data >= data_info->min && (*list_a)->data <= data_info->max)
		return (1);
	return (0);
}

void	ft_cost_to_go_a(t_dclist **list_a, t_data_info *data_info)
{
	t_dclist	*head;

	head = *list_a;
	if (is_in_range(list_a, data_info) && (*list_a)->data > data_info->value)
		data_info->direction_a += 1;
	while (!a_is_to_good_place(list_a, data_info))
	{
		if (data_info->direction_a)
		{
			data_info->cost_to_rotate_a += 1;
			*list_a = (*list_a)->next;
		}
		else
		{
			*list_a = (*list_a)->prev;
			data_info->cost_to_rotate_a += 1;
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
		*go_back_cost += 1;
		*list_b = (*list_b)->prev;
	}
	*list_b = head;
}

int	a_is_to_good_place(t_dclist **list_a, t_data_info *data_info)
{
	if (!is_in_range(list_a, data_info)
		&& !is_in_range(&(*list_a)->prev, data_info))
		return (1);
	else if (is_in_range(list_a, data_info)
		&& is_in_range(&(*list_a)->prev, data_info))
	{
		if ((*list_a)->data > data_info->value
			&& (*list_a)->prev->data < data_info->value)
			return (1);
	}
	else if (is_in_range(list_a, data_info))
	{
		if ((*list_a)->data > data_info->value)
			return (1);
	}
	else
		return (1);
	return (0);
}
