/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:01:17 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/05 15:01:21 by vlevy            ###   ########.fr       */
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
