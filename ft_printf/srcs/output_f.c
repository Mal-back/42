/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:33:47 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/12 21:25:42 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_count(char c, int *count)
{
	write(1, &c, 1);
	*count += 1;
	return ;
}

void	ft_putstr_count(char *str, int *count)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putchar_count(str[i++], count);
	return ;
}

void	ft_bputnbr_count(const char *base, unsigned long long n, int base_len, int *count)
{
	char	c;

	if (n < 0)
	{
		write(1, "-", 1);
		*count += 1;
		return (ft_putnbr_count(base, n * -1, base_len, count));
	}
	else if (n < (unsigned long long)base_len)
	{
		c = base[n];
		write(1, &c, 1);
		*count += 1;
		return ;
	}
	ft_putnbr_count(base, n / base_len, base_len, count);
	c = base[n % base_len];
	write(1, &c, 1);
	*count += 1;
	return ;
}

void	ft_putnbr_count(const char *base, long n, int base_len, int *count)
{
	char	c;

	if (n < 0)
	{
		write(1, "-", 1);
		*count += 1;
		return (ft_putnbr_count(base, n * -1, base_len, count));
	}
	else if (n < base_len)
	{
		c = base[n];
		write(1, &c, 1);
		*count += 1;
		return ;
	}
	ft_putnbr_count(base, n / base_len, base_len, count);
	c = base[n % base_len];
	write(1, &c, 1);
	*count += 1;
	return ;
}
