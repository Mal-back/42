/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:05:55 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/06 22:04:16 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

long	ft_atol(char **str, int *flag)
{
	unsigned int	result;
	unsigned int	max_value;
	int				i;
	int				sign;

	i = 0;
	max_value = INT_MAX;
	result = 0;
	sign = 1;
	if (!ft_isdigit(**str))
		return (UINT_MAX);
	while (ft_isdigit(**str))
	{
		result = 10 * result + (**str - 48);
		if (result > max_value + 1)
			return (UINT_MAX);
		*str += 1;
		*flag = 0;
	}
	return (result);
}
