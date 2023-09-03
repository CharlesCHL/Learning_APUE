

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define FNAME	"tmp/out"

int main()
{
	int fd;
/**
	close(1);
	fd = open(FNAME, O_WRONLY|O_CREAT|O_TRUNC, 0600);
	if(fd != 1)
	{
		perror("open()");
		exit(1);
	}
*/
	fd = open(FNAME, O_CREAT|O_TRUNC|O_WRONLY, 0600);
	if(fd < 0)
	{
		perror("open()");
		exit(1);
	}

	close(1);
	dup(fd);
//	上面两步可以通过一步(原子操作)完成
//	dup2(fd, 1);
//	可以防止fd == 1的情况

	if(fd != 1)
		close(fd);

/*************************/
	puts("hello!");

	close(1);

	exit(0);
}




