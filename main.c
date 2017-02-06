
#include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
#include <stdio.h>

int main()
{
	int		fd;
	char	buff[3000];
	int		ret;

	ret =0;
	fd = 0;

	fd = open("out.txt",  O_RDWR);
	ret = read(fd, buff, 3000);
	buff[ret] = '\0';
	printf("%s\n", buff);
	return 0;
}