/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_handling_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:20:34 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/14 15:55:10 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char_handling(va_list *ap, long *count, t_flags *flags)
{
	char	*str;
	char	*pad_str;
	char	c;
	int		n;

	str = malloc(2 * sizeof(char));
	if (!str)
	{
		*count = -1;
		return ;
	}
	c = va_arg(*ap, int);
	ft_stlcpy(str, &c, 2);
	flags->arg_str = str;
	n = def_padding(flags);
	pad_str = malloc((n + 1) * sizeof(char));
	if (pad_str == NULL)
	{
		free (str);
		*count = -1;
		return ;
	}
	*count = write(1, fill_str(pad_str, flags), n);
	free(str);
	free(pad_str);
}
