/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdc_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:04:39 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/29 19:55:24 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lst_dcsize(t_dclist *list)
{
	t_dclist	*head_ptr;
	int			lst_size;

	if (list == NULL)
		return (0);
	head_ptr = list;
	if (!head_ptr->next)
		return (1);
	lst_size = 0;
	while (list->next != head_ptr)
	{
		list = list->next;
		lst_size++;
	}
	return (lst_size + 1);
}
