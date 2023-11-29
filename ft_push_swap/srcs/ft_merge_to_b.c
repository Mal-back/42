/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_to_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:41:47 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/28 17:43:57 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_merge_to_b(t_dclist **list_a, t_dclist **list_b)
{
	while (*list_a != NULL)
		ft_pb(list_b, list_a);
	return ;
}
