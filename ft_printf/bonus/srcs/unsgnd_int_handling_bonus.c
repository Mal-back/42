/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsgnd_int_handling_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:20:34 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/15 16:18:01 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_unsgnd_int_handling(va_list *ap, long *count, t_flags *flags)
{
	char	*pad_str;
	int		n;
	long	nb;

	nb = (long)va_arg(*ap, unsigned int);
	flags->arg_str = ft_itoa_base(nb, "0123456789");
	if (malloc_secure(flags->arg_str, count))
		return ;
	n = def_padding(flags);
	pad_str = malloc((n + 1) * sizeof(char));
	if (malloc_secure(pad_str, count))
	{
		free(flags->arg_str);
		return ;
	}
	*count = write(1, fill_padding(pad_str, flags), n);
	free(pad_str);
	free(flags->arg_str);
	return ;
}
