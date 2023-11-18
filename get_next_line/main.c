/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:12:30 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/18 22:57:13 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int 	fd;
	int 	i = 0;
	char	*str;
	fd = open("sample3.txt", O_RDONLY);
	while (i == 0 || str != NULL)
	{
	 str = get_next_line(fd);
	 printf("%s", str);
	 i++;
	}
	printf("i = %d\n", i);
	free(str);
	return (0);
}
