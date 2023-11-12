/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:29:00 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/11 21:29:21 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

void	ft_putchar_count(char c, int *count);
void	ft_putstr_count(char *str, int *count);
void	ft_putnbr_count(const char *base, long n, int base_len, int *count);
void	ft_identifier(va_list *ap, const char *format, int *count);
void	ft_char_handling(va_list *ap, int *count);
void	ft_str_handling(va_list *ap, int *count);
void	ft_int_handling(va_list *ap, int *count);
void	ft_unsgndint_handling(va_list *ap, int *count);
void	ft_lchexa_handling(va_list *ap, int *count);
void	ft_ptr_handling(va_list *ap, int *count);
void	ft_uchexa_handling(va_list *ap, int *count);
void	ft_error_handling(const char *format, int *count);

int		flag_check(char c);
int		ft_printf(const char *format, ...);

#endif
