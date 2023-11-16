/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:29:00 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/16 13:20:19 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_flags
{
	int		f;
	int		sign;
	int		sharp;
	int		pad_side;
	int		pad_sign;
	int		pad_value;
	int		precision;
	int		precision_value;
	int		left_padding_space;
	int		left_padding_zero;
	int		right_padding;
	char	*arg_str;

}							t_flags;

const char			*ft_identifier(va_list *ap, const char *format,
						long *count);
const char			*ft_pad_check(const char *format, t_flags *flags);
const char			*flag_check(const char *format, t_flags *flags);
int					ft_printf(const char *format, ...);
void				init_flags(t_flags *flags);
int					def_padding(t_flags *flags);
char				*fill_padding(char *pad_str, t_flags *flags);
char				*ft_itoa_base(long nb, char *base);
char				*ft_itoa_ptr(unsigned long long nb, char *base);
int					ft_printf(const char *format, ...);
int					malloc_secure(char *str, long *count);
char				*char_padding(char *pad_str, t_flags *flags, long *count);

void				ft_char_handling(va_list *ap, long *count, t_flags *flags);
void				ft_str_handling(va_list *ap, long *count, t_flags *flags);
void				ft_int_handling(va_list *ap, long *count, t_flags *flags);
void				ft_unsgnd_int_handling(va_list *ap, long *count,
						t_flags *flags);
void				ft_lchexa_handling(va_list *ap, long *count,
						t_flags *flags);
void				ft_uchhexa_handling(va_list *ap, long *count,
						t_flags *flags);
void				ft_ptr_handling(va_list *ap, long *count, t_flags *flags);

#endif
