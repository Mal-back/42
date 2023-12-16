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

#include "libft.h"
#include "push_swap.h"

void	resolve_direction_b(t_dclist **list_b, t_dclist **looked_position)
{
	int	go_cost;
	int	go_back_cost;

	ft_cost_to_go_b(list_b, (*looked_position)->target,
		&go_cost, &go_back_cost);
	if (go_cost < go_back_cost)
	{
		(*looked_position)->rotate_cost_b = go_cost;
		(*looked_position)->direction_b = 0;
	}
	else
	{
		(*looked_position)->rotate_cost_b = go_back_cost;
		(*looked_position)->direction_b = 1;
	}
}

void	resolve_cost(t_dclist **looked_position)
{
	if ((*looked_position)->direction_a != (*looked_position)->direction_b)
		(*looked_position)->final_cost = (*looked_position)->rotate_cost_a
			+ (*looked_position)->rotate_cost_b;
	else
	{
		if ((*looked_position)->rotate_cost_b
			> (*looked_position)->rotate_cost_a)
			(*looked_position)->final_cost = (*looked_position)->rotate_cost_a
				+ ((*looked_position)->rotate_cost_b
					- (*looked_position)->rotate_cost_a);
		else
			(*looked_position)->final_cost = (*looked_position)->rotate_cost_b
				+ ((*looked_position)->rotate_cost_a
					- (*looked_position)->rotate_cost_b);
	}
}

int	is_in_range(t_dclist **list_a, t_data_info *data_info)
{
	if ((*list_a)->data >= data_info->min && (*list_a)->data <= data_info->max)
		return (1);
	return (0);
}

int	ft_cost_to_go_a(t_dclist **list_a, t_dclist **looked_position)
{
	t_dclist	*head;
	int			cost;

	head = *list_a;
	cost = 0;
	while (head != *looked_position)
	{
		if (!(*looked_position)->direction_a)
			head = head->next;
		else
			head = head->prev;
		cost++;
	}
	return (cost);
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
