#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	char *str = "numbers.dict";
	int fd = open(str, O_RDONLY);
	char buff[1];
	int size = 0;

	int i = 0;
	while(read(fd, buff, 351) > 0)
	{
		size++;
	}
	int success = close(fd);
	printf("%d\n", size);

	return (0);
}

/*s_struct
int a 
char *str

100000000

if s_struc[i].number = a
	write s_struct[i].str*/
