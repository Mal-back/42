/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:01:07 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/04 19:04:22 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_sa(t_dclist **list_a, int f)
{
	long	tmp;

	if (!list_a || !(*list_a)->next)
		return ;
	if (f)
		ft_putendl_fd("sa", 1);
	tmp = (*list_a)->data;
	(*list_a)->data = (*list_a)->next->data;
	(*list_a)->next->data = tmp;
	return ;
}
