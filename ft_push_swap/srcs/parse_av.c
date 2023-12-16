/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:35:51 by vlevy             #+#    #+#             */
/*   Updated: 2023/12/06 22:14:02 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	add_node(t_dclist **list, unsigned int nb, int sign)
{
	t_dclist		*new_node;
	unsigned int	max_value;

	new_node = NULL;
	max_value = INT_MAX;
	if (sign == -1)
		max_value++;
	if (nb > max_value || check_doublons(nb, *list))
		return (1);
	new_node = ft_lst_dcnew(((int) nb) * sign);
	if (new_node == NULL)
		return (1);
	ft_lstdcadd_back(list, new_node);
	return (0);
}

static int	handle_sign(char **str, int *flag)
{
	int	sign;

	sign = 1;
	if (ft_is_sign(**str))
	{
		if (**str == '-')
			sign *= -1;
		*str += 1;
		*flag = 1;
	}
	return (sign);
}

int	parse_av(char *str, t_dclist **list)
{
	unsigned int		nb;
	int					sign;
	int					flag;

	nb = 0;
	flag = 0;
	while (ft_isdigit(*str) || *str == 32 || ft_is_sign(*str))
	{
		if (*str == 32)
			str++;
		else
		{
			sign = handle_sign(&str, &flag);
			nb = ft_atol(&str, &flag);
			if (add_node(list, nb, sign))
				return (1);
		}
	}
	if (*str || flag)
		return (1);
	return (0);
}
