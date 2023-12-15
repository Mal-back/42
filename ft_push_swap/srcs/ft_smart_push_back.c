/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smart_push_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 21:52:44 by purmerinos        #+#    #+#             */
/*   Updated: 2023/12/13 21:52:45 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	separate_rotate(t_dclist **list_a, t_dclist **list_b,
		t_data_info *data_info)
{
	while ((*list_b)->data != data_info->value)
	{
		if (data_info->direction_b)
			ft_rrb(list_b, 1);
		else
			ft_rb(list_b, 1);
	}
	if (data_info->direction_a)
	{
		while (!a_is_to_good_place(list_a, data_info))
			ft_rra(list_a, 1);
	}
	else
	{
		while (!a_is_to_good_place(list_a, data_info))
			ft_ra(list_a, 1);
	}
}

static void	push_data(t_dclist **list_a, t_dclist **list_b,
	t_data_info *data_info)
{
	if (data_info->direction_a == data_info->direction_b)
		combine_rotate(list_a, list_b, data_info);
	else
		separate_rotate(list_a, list_b, data_info);
	ft_pa(list_a, list_b);
}

void	combine_rotate(t_dclist **list_a, t_dclist **list_b,
	t_data_info *data_info)
{
	if (!data_info->direction_b)
	{
		while ((*list_b)->data != data_info->value
			&& !a_is_to_good_place(list_a, data_info))
			ft_rr(list_a, list_b);
		while ((*list_b)->data != data_info->value)
			ft_rb(list_b, 1);
		while (!a_is_to_good_place(list_a, data_info))
			ft_ra(list_a, 1);
	}
	else
	{
		while ((*list_b)->data != data_info->value
			&& !a_is_to_good_place(list_a, data_info))
			ft_rrr(list_a, list_b);
		while ((*list_b)->data != data_info->value)
			ft_rrb(list_b, 1);
		while (!a_is_to_good_place(list_a, data_info))
		{
			ft_rra(list_a, 1);
		}
	}
}

static void	cost_of_push(t_dclist **list_a, t_dclist **list_b,
	t_data_info *data_info)
{
	int	go_cost;
	int	go_back_cost;

	ft_cost_to_go_b(list_b, data_info->value, &go_cost, &go_back_cost);
	resolve_direction_b(go_cost, go_back_cost, data_info);
	data_info->cost_to_rotate_a = 0;
	data_info->direction_a = 0;
	ft_cost_to_go_a(list_a, data_info);
	resolve_cost(data_info);
}

void	smart_push_back(t_dclist **list_a, t_dclist **list_b)
{
	t_data_info	big_info;
	t_data_info	little_info;

	big_info.min = ft_find_little(list_b);
	big_info.max = ft_find_big(list_b);
	little_info.min = ft_find_little(list_b);
	little_info.max = ft_find_big(list_b);
	while ((*list_b)->next)
	{
		big_info.value = ft_find_big(list_b);
		little_info.value = ft_find_little(list_b);
		cost_of_push(list_a, list_b, &big_info);
		cost_of_push(list_a, list_b, &little_info);
		if (big_info.final_cost < little_info.final_cost)
			push_data(list_a, list_b, &big_info);
		else
			push_data(list_a, list_b, &little_info);
	}
	little_info.value = ft_find_little(list_b);
	cost_of_push(list_a, list_b, &little_info);
	push_data(list_a, list_b, &little_info);
}
