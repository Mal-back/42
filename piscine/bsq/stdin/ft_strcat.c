/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 19:22:00 by vlevy             #+#    #+#             */
/*   Updated: 2023/07/03 10:28:43 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int				i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	unsigned int				size_src;
	unsigned int				size_dest;
	unsigned int				i;

	size_dest = ft_strlen(dest);
	size_src = ft_strlen(src);
	if (size_src == 0)
		return (dest);
	i = 0;
	while (i <= size_src)
	{
		dest[size_dest + i] = src[i];
		i++;
	}
	return (dest);
}
