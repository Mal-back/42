/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buuble_sort_5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:44:57 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/04 16:58:12 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	need_to_swap(t_dclist **list)
{
	if (!*list || !(*list)->next)
		return (0);
	if ((*list)->data > (*list)->next->data)
		return (1);
	return (0);
}
