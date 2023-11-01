

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>


static off_t flen(const char* filename)
{
	struct stat statres;
	if (stat(filename, &statres) != 0)
	{
		perror("stat()");
		exit(1);
	}

	return statres.st_size;

}

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		fprintf(stderr, "Usage...\n");
		exit(1);
	}

	printf("%lld\n", flen(argv[1]));

	exit(0);

}


