

#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE		1024

int main(int argc, char** argv)
{
	if(argc < 3)
	{
		fprintf(stderr, "Usage:%s <src_file> <dest_file>\n", argv[0]);
		exit(1);
	}


	FILE* fps;
	FILE* fpd;

	char buf[BUFSIZE];

	fps = fopen(argv[1], "r");
	if(fps == NULL)
	{
		perror("fopen1()");
		exit(1);
	}
	fpd = fopen(argv[2], "w");
	if(fpd == NULL)
	{
		fclose(fps);
		perror("fopen2()");
		exit(2);
	}

	while(fgets(buf, BUFSIZE, fps) != NULL)
	{
		fputs(buf, fpd);
	}

	fclose(fpd);
	fclose(fps);

	exit(0);

}





