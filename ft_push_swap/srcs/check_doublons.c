/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_doublons.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:23:11 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/25 20:14:19 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	check_doublons(long nb, t_dclist *list)
{
	t_dclist	*tmp;

	tmp = list;
	if (!list)
		return (0);
	while (tmp->next != list && tmp->next)
	{
		if (nb == tmp->data)
			return (1);
		tmp = tmp->next;
	}
	if (nb == tmp->data)
		return (1);
	return (0);
}
