/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_handling_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:20:34 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/14 17:18:11 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_str_handling(va_list *ap, long *count, t_flags *flags)
{
	char	*pad_str;

	flags->arg_str = va_arg(*ap, char *);
	if (flags->arg_str == NULL)
		flags->arg_str = "(null)"
	n = def_padding(flags);
	pad_str = malloc((n + 1) * sizeof(char));
	if (pad_str == NULL)
	{
		free (str);
		*count = -1;
		return ;
	}
	*count = write(1, fill_str(pad_str, flags), n);
	free(pad_str);
}
