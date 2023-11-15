/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lchexa_handling_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:20:34 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/15 20:32:53 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_lchexa_handling(va_list *ap, long *count, t_flags *flags)
{
	char	*pad_str;
	char	*str;
	int		n;
	long	nb;

	nb = (unsigned int)va_arg(*ap, int);
	if (nb == 0)
		flags->sharp = 0;
	str = ft_itoa_base(nb, "0123456789abcdef");
	if (malloc_secure(str, count))
		return ;
	flags->arg_str = str;
	if (flags->sharp > 0)
		flags->sharp = 'x';
	n = def_padding(flags);
	pad_str = malloc((n + 1) * sizeof(char));
	if (malloc_secure(pad_str, count))
	{
		free(flags->arg_str);
		return ;
	}
	*count += write(1, fill_padding(pad_str, flags), n);
	free(flags->arg_str);
	free(pad_str);
	return ;
}
