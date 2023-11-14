/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:29:00 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/14 16:58:19 by vlevy            ###   ########.fr       */
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
	int		sign;
	int		sharp;
	int		pad_side;
	int		pad_sign;
	int		pad_value;
	int		precison;
	int		precision_value;
	int		left_padding_space;
	int		left_padding_zero;
	int		right_padding;
	char	*arg_str;

}							t_flags;

char				*ft_identifier(va_list *ap, const char *format, int *count);
char				*ft_pad_check(char *format, t_flags *flags);
int					flag_check(char c);
int					ft_printf(const char *format, ...);
void				init_flags(t_flags *flags);
int					def_padding(t_flags *flags);
char				*fill_str(char *pad_str, t_flags *flags);

void				ft_char_handling(va_list *ap, long *count, t_flags *flags);

#endif
