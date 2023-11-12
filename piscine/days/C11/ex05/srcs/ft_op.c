/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 13:47:05 by vlevy             #+#    #+#             */
/*   Updated: 2023/07/14 14:24:07 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_add(int a, int b)
{
	ft_putnbr(a + b);
	write(1, "\n", 1);
}

void	ft_sub(int a, int b)
{
	ft_putnbr(a - b);
	write(1, "\n", 1);
}

void	ft_mul(int a, int b)
{
	ft_putnbr(a * b);
	write(1, "\n", 1);
}

void	ft_div(int a, int b)
{
	ft_putnbr(a / b);
	write(1, "\n", 1);
}

void	ft_mod(int a, int b)
{
	ft_putnbr(a % b);
	write(1, "\n", 1);
}
