/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_str_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:57:25 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/14 17:02:06 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*fill_str(char *pad_str, t_flags *flags)
{
	char	*tmp;

	tmp = pad_str;
	while (flags->left_padding_space--)
		*tmp++ = ' ';
	if (sharp > 0)
	{
		*tmp++ = '0';
		*tmp++ = flags->sharp;
	}
	if (sign > 0)
		*tmp++ = flags->sign;
	while (flags->left_padding_zero--)
		*tmp++ = '0';
	while (flags->precison_value--)
		*tmp++ = '0';
	tmp = ft_strlcpy(tmp, arg_str, ft_strlen(arg_str) + 1);
	while (*tmp)
		tmp++;
	while (flags->right_padding--)
		*tmp++ = ' ';
	*tmp = 0;
	return (pad_str);
}
