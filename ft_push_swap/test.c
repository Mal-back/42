#include "libft.h"
#include <fcntl.h>
#include <stdio.h>
int	main()
{
	int fd = open("instructions.txt", O_RDONLY);
	char *str = NULL;
	int 	i = 0;
	while (str || !i)
	{	
		str = get_next_line(fd);
		printf("%s", str);
		i++;
	}
}
