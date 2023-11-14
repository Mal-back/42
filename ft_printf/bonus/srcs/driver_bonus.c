/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   driver_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:42:00 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/14 17:01:16 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	long		count;
	char		*format;
	int			i;

	if (!format)
		return (-1);
	va_start(ap, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (count == -1)
			return (count);
		if (*format == '%')
		{
			count = write(1, format, i);
			format = ft_identifier(ap, format + i, &count);
			i = 0;
		}
		i++;
	}
	va_end(ap);
	return (count);
}

char	*ft_identifier(va_list *ap, const char *format, long *count)
{
	int		i;
	t_flags	flags;

	i = 1;
	format = flag_check(format, flags);
	if (*format == 'c')
		ft_char_handling(ap, count, flags);
	else if (*format == 's')
		ft_str_handling(ap, count, flags);
	else if (*format == 'i' || *format == 'd')
		ft_int_handling(ap, count, flags);
	else if (*format == 'u')
		ft_unsgndint_handling(ap, count, flags);
	else if (*format == 'x')
		ft_lchexa_handling(ap, count, flags);
	else if (*format == 'p')
		ft_ptr_handling(ap, count, flags);
	else if (*format == 'X')
		ft_uchexa_handling(ap, count, flags);
	else if (*format == '%')
		*count = write(1, "%", 1);
	return (format);
}

void	init_flags(t_flags *flags)
{
	flags->sign = 0;
	flags->sharp = 0;
	flags->pad_size_beg = 0;
	flags->pad_size_end = 0;
	flags->pad_side = -1;
	flags->pad_value = 0;
	flags->precision = 0;
	flags->precision_value = 0;
}

char	*flag_check(char *format, t_flags *flags)
{	
	init_flags(&flags);
	while (*format)
	{
		if (*format == '#')
			flag->sharp = 1;
		else if (*format == '+')
			flag->sign = '+';
		else if (*format == ' ' && flag->sharp == -1)
			flag->sign = ' ';
		else if (*format == '-' && pad_size_beg == -1)
		{
			flag->pad_side = 1;
			flag->pad_sign = -32;
		}
		else if (*format == '0' && flag->pad_value != -32)
			flag->pad_sign = '0';
		else if (*format == '.')
			flag->precision == 1;
		else if (ft_isnum(*format))
			format = ft_pad_check(format, flags, ap);
		else
			return (format);
		format++;
	}
	return (format);
}

char	*ft_pad_check(char *format, t_flags *flags)
{
	if (flags->precision == 1)
		flags->precision_value = ft_atoi(*format);
	else
		flags->pad_value = ft_atoi(*format);
	while (ft_isnum(*format))
		format++;
	return (format);
}
