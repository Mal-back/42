/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:42:59 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/28 16:22:30 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dclist	*ft_algo_init(t_dclist *list_a)
{
	int			list_size;

	list_size = ft_lst_dcsize(list_a);
	if (ft_is_sorted(list_a))
		return (list_a);
	if (list_size < 4)
	{
		ft_manual_sort(&list_a, list_size);
		return (list_a);
	}
	ft_quick_sort_init(&list_a, list_size, 0);
	return (list_a);
}
