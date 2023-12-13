/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:35:49 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/07 15:03:37 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_sb(t_dclist **list_b, int f)
{
	long	tmp;
	int		tmp_place;

	if (!list_b || !*list_b || !(*list_b)->next)
		return ;
	if (f)
		ft_putendl_fd("sb", 1);
	tmp = (*list_b)->data;
	tmp_place = (*list_b)->end_place;
	(*list_b)->data = (*list_b)->next->data;
	(*list_b)->end_place = (*list_b)->next->end_place;
	(*list_b)->next->data = tmp;
	(*list_b)->next->end_place = tmp_place;
	return ;
}
