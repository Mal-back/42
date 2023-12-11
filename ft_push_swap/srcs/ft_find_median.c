/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_median.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:12:00 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/07 16:39:19 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_find_median(t_dclist **list)
{
	long		little;
	long		next_little;
	long		big;
	long		next_big;

	little = ft_find_little(list);
	big = ft_find_big(list);
	while (little != big)
	{
		next_little = ft_find_next_little(*list, little);
		if (big != next_little)
		{
			next_big = ft_find_next_big(list, big);
			big = next_big;
		}
		little = next_little;
	}
	return (big);
}
