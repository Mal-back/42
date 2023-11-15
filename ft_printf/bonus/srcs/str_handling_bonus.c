/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_handling_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:20:34 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/15 14:53:44 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_str_handling(va_list *ap, long *count, t_flags *flags)
{
	char	*pad_str;
	char	*null_str;
	int		n;

	null_str = "(null)";
	flags->arg_str = va_arg(*ap, char *);
	if (flags->arg_str == NULL)
		flags->arg_str = null_str;
	n = def_padding(flags);
	pad_str = malloc((n + 1) * sizeof(char));
	if (pad_str == NULL)
	{
		*count = -1;
		return ;
	}
	*count += write(1, fill_padding(pad_str, flags), n);
	free(pad_str);
	return ;
}
