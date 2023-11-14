/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_padding_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:46:50 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/14 15:25:18 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	def_padding(t_flags *flags)
{
	int	f;

	f = 0;
	if (flags->sharp > 0)
		f += 2;
	if (flags->sign > 0)
		f += 1;
	flags->left_padding_space = flags->pad_value - f - flags->precision_value
		- ft_strlen(arg_str);
	if (flags->left_padding_space < 0)
		flags->left_padding_space = 0;
	if (flags->pad_sign == '0')
	{
		left_padding_zero = left_padding_space;
		left_padding_space = 0;
	}
	if (flags->pad_side_value == 1)
	{
		flags->right_padding = flags->left_padding_space;
		flags->pad_sign = 32;
		flags->left_padding = 0;
	}
	return (f + flags->left_padding_space + flags->left_padding_zero
		+ flags->right_padding + flags->precision->value
		+ ft_strlen(arg_str));
}
