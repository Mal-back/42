/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:05:55 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/25 20:18:41 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

long	ft_atol(char **str)
{
	long	result;
	int		i;
	int		sign;

	result = 0;
	i = 0;
	sign = 1;
	while (ft_isblank(**str))
		*str += 1;
	if (ft_is_sign(**str))
	{
		if (**str == '-')
			sign *= -1;
		*str += 1;
	}
	if (!ft_isdigit(**str))
		return (2147483987);
	while (ft_isdigit(**str))
	{
		result = 10 * result + (**str - 48);
		*str += 1;
	}
	return (result * sign);
}
