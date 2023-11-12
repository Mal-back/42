/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:05:49 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/08 16:09:49 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
	return ;
}

/*#include <stdio.h>
int	main(void)
{
	char *str = "Souvenir souvenir me rappele";
	ft_putendl_fd(str, 1);
}*/
