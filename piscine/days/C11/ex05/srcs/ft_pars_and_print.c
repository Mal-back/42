/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_and_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 20:43:30 by vlevy             #+#    #+#             */
/*   Updated: 2023/07/14 14:28:31 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putnbr(int nb)
{
	char				c;

	c = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (nb < 0)
	{
		write (1, "-", 1);
		nb *= -1;
	}
	if (nb < 10)
	{
		c = nb + '0';
		write (1, &c, 1);
	}
	else
	{
		ft_putnbr(nb / 10);
		c = nb % 10 + '0';
		write(1, &c, 1);
	}
}

int	ft_atoi(char *str)
{
	int				i;
	int				isneg;
	int				res;

	i = 0;
	isneg = 1;
	res = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	while ((str[i] == 43) || (str[i] == 45))
	{
		if (str[i] == 45)
			isneg *= -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * isneg);
}

void	ft_putstr(char *str)
{
	int				i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i ++;
	}
}
