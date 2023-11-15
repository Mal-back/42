/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_handling_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:20:34 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/14 21:28:31 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_int_handling(va_list *ap, long *count, t_flags *flags)
{
	char				*pad_str;
	int					n;
	unsigned long long	nb;

	nb = (unsigned long long)va_arg(*ap, int);
	if (nb = 0)
		flag->arg_str = "(nil)";
	else
		flags->arg_str = ft_itoa_ptr(nb, "012345679abcdef");
	flag->sharp = 'x';
	n = def_padding(flags);
	pad_str = malloc((n + 1) * sizeof(char));
	if (pad_str == NULL)
	{
		*count = -1;
		return ;
	}
	*count = write(1, fill_str(pad_str, flags), n);
	free(pad_str);
}
