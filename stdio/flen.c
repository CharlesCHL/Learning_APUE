

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	if(argc < 2)
	{
		fprintf(stderr, "Usage...\n");
		exit(0);
	}	

	FILE* fp;

	fp = fopen(argv[1], "r");
	if(fp == NULL)
	{
		perror("fopen()");
		exit(2);
	}

	fseek(fp, 0, SEEK_END);
	printf("%ld\n", ftell(fp));	

#if 0
	int count = 0;
	int ch;
	while((ch = fgetc(fp)) != EOF)
	{
		printf("%d\t", ch);
		count++;
	}
	
	printf("count = %d\n", count);

#endif

	fclose(fp);

	exit(0);

}




