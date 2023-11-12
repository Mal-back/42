/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   driver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:42:00 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/12 20:22:27 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	if (!format)
		return (-1);
	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			format = ft_identifier(&ap, format, &count);
		else
			ft_putchar_count(*format, &count);
		if (*format != 0)
			format++;
	}
	va_end(ap);
	return (count);
}

const char	*ft_identifier(va_list *ap, const char *format, int *count)
{
	int	i;

	i = 1;
	while (flag_check(format[i]))
		i++;
	if (format[i] == 'c')
		ft_char_handling(ap, count);
	else if (format[i] == 's')
		ft_str_handling(ap, count);
	else if (format[i] == 'i' || format[i] == 'd')
		ft_int_handling(ap, count);
	else if (format[i] == 'u')
		ft_unsgndint_handling(ap, count);
	else if (format[i] == 'x')
		ft_lchexa_handling(ap, count);
	else if (format[i] == 'p')
		ft_ptr_handling(ap, count);
	else if (format[i] == 'X')
		ft_uchexa_handling(ap, count);
	else if (format[i] == '%')
		ft_putchar_count('%', count);
	else
		ft_error_handling(format + i, count);
	return (format + i);
}

int	flag_check(char c)
{
	char	*flag_set;
	int		i;

	flag_set = "# +-0.";
	i = 0;
	while (flag_set[i])
	{
		if (c == flag_set[i])
			return (1);
		i++;
	}
	return (0);
}
