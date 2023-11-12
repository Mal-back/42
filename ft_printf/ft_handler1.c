/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:20:34 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/11 21:27:46 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char_handling(va_list *ap, int *count)
{
	va_list	ap_c;

	va_copy(ap_c, *ap);
	ft_putchar_count(va_arg(ap_c, int), count);
	va_copy(*ap, ap_c);
	va_end(ap_c);
	return ;
}

void	ft_str_handling(va_list *ap, int *count)
{
	va_list	ap_c;

	va_copy(ap_c, *ap);
	ft_putstr_count(va_arg(ap_c, char *), count);
	va_copy(*ap, ap_c);
	va_end(ap_c);
	return ;
}

void	ft_int_handling(va_list *ap, int *count)
{
	va_list	ap_c;

	va_copy(ap_c, *ap);
	ft_putnbr_count("0123456789", (long)va_arg(ap_c, int), 10, count);
	va_copy(*ap, ap_c);
	va_end(ap_c);
	return ;
}

void	ft_unsgndint_handling(va_list *ap, int *count)
{
	va_list	ap_c;

	va_copy(ap_c, *ap);
	ft_putnbr_count("0123456789", va_arg(ap_c, unsigned int), 10, count);
	va_copy(*ap, ap_c);
	va_end(ap_c);
	return ;
}

void	ft_lchexa_handling(va_list *ap, int *count)
{
	va_list	ap_c;

	va_copy(ap_c, *ap);
	ft_putnbr_count("0123456789bcdef", (long)va_arg(ap_c, unsigned int), 16,
		count);
	va_copy(*ap, ap_c);
	va_end(ap_c);
	return ;
}
