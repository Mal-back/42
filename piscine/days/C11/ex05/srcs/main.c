/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 13:39:19 by vlevy             #+#    #+#             */
/*   Updated: 2023/07/14 14:40:35 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(int ac, char **av)
{
	int					a;
	int					b;
	void					(*p[5])(int a, int b);

	if (ac != 4)
		return (1);
	a = ft_atoi(av[1]);
	b = ft_atoi(av[3]);
	p[0] = ft_add;
	p[1] = ft_sub;
	p[2] = ft_mul;
	p[3] = ft_div;
	p[4] = ft_mod;
	if (ft_find_op(av[2][0], b) < 0)
		ft_print_error(ft_find_op(av[2][0], b));
	else
	(	*p[ft_find_op(av[2][0], b)])(a, b);
	return (0);
}

int	ft_find_op(char c, int b)
{
	if (c == '+')
		return (0);
	else if (c == '-')
		return (1);
	else if (c == '*')
		return (2);
	else if (c == '/')
	{
		if (b == 0)
			return (-1);
		return (3);
	}
	else if (c == '%')
	{
		if (b == 0)
			return (-2);
		return (4);
	}
	return (-3);
}

void	ft_print_error(int a)
{
	if (a == -1)
		ft_putstr("Stop : division by zero\n");
	else if (a == -2)
		ft_putstr("Stop : modulo by zero\n");
	else
		write(1, "0\n", 2);
}
