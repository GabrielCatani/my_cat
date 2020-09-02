#define BUF_SIZE 255
#include <unistd.h>
#include <fcntl.h>

int	display_file(char *name, char *buf)
{
	int bytes_r;
	int fd;

	fd = open(name, O_RDONLY);
	if (fd == -1)
	{
		return 1;
	}
	while((bytes_r = read(fd, buf, BUF_SIZE)))
	{
		buf[bytes_r] = '\0';
		write(1, buf, bytes_r);
	}
	return 0;
}

int	main(int argc, char *argv[])
{
	char buf[BUF_SIZE + 1];
	int bytes_r;
	int i;

	if(argc == 1)
	{
		while(1)
		{
			bytes_r = read(0, buf, BUF_SIZE);
			write(1, buf, bytes_r);
		}
	}else{
		i = 0;
		while(i++ < argc)
			display_file(argv[i], buf);
	}
	return 0;
}
