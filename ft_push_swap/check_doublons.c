/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_doublons.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:23:11 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/24 16:37:49 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_doublons(long nb, tdc_list *list)
{
	tdc_list	*tmp;

	tmp = list;
	if (!list)
		return (0);
	while (tmp->next != list && tmp->next)
	{
		if (nb == *(long *)tmp->data)
			return (1);
		tmp = tmp->next;
	}
	if (nb == *(long *)tmp->data)
		return (1);
}
