/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <vlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:12:30 by vlevy             #+#    #+#             */
/*   Updated: 2023/11/20 18:48:37 by vlevy            ###   ########.fr       */
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
	fd = open("bible.txt", O_RDONLY);
	while (i == 0 || str != NULL)
	{
	 str = get_next_line(fd);
	 //printf("%send", str); 
	 free(str);
	 i++;
	}
	printf("i = %d\n", i);
	close(fd);
	return (0);
}
