/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:20:34 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/12 21:24:28 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ptr_handling(va_list *ap, int *count)
{
	va_list	ap_c;
	unsigned long long	p;

	va_copy(ap_c, *ap);
	p = (unsigned long long)va_arg(ap_c, void *);
	if (p == 0)
		ft_putstr_count("(nil)", count);
	else
	{
		ft_putstr_count("0x", count);
		ft_bputnbr_count("0123456789abcdef", p, 16, count);
	}
	va_copy(*ap, ap_c);
	va_end(ap_c);
	return ;
}

void	ft_uchexa_handling(va_list *ap, int *count)
{
	va_list	ap_c;

	va_copy(ap_c, *ap);
	ft_putnbr_count("0123456789ABCDEF", (unsigned int)va_arg(ap_c, int), 16,
		count);
	va_copy(*ap, ap_c);
	va_end(ap_c);
	return ;
}

void	ft_error_handling(const char *format, int *count)
{
	if (*format++ == 0)
		*count = -1;
	else
	{
		ft_putchar_count(*format, count);
		ft_putchar_count(*format++, count);
	}
	return ;
}
