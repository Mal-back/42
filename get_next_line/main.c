/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:12:30 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/17 16:54:21 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int	main(void)
{
	char buff[9];
	int fd;
	int i = 0;
	int n;
	fd = open("test", O_RDONLY);
	while (i < 10)
	{
	 n = read(fd, buff, 8);
	 printf("%d\n", n);
	 i++;
	}
	return (0);
}
