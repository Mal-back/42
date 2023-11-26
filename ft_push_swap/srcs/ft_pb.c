/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:12:45 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/26 19:46:49 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_pb(t_dclist **list_b, t_dclist **list_a)
{
	t_dclist	*tmp;

	tmp = *list_a;
	if (!list_a)
		return ;
	ft_putendl_fd("pb", 1);
	ft_update_lstdc(list_a);
	ft_lstdcadd_front(list_b, tmp);
	return ;
}
