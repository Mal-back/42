/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsgnd_int_handling_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:20:34 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/14 21:16:46 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_int_handling(va_list *ap, long *count, t_flags *flags)
{
	char	*pad_str;
	int		n
	long	nb;

	nb = (long)va_arg(*ap, unsigned int);
	flags->arg_str = ft_itoa(nb, "012345679");
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