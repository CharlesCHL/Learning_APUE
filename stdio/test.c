

#include <stdio.h>
#include <unistd.h>

#define MAXLINE		20


int main(void)
{
	char ff[MAXLINE];

	while(fgets(ff, MAXLINE, stdin) != NULL)
	{
		if(fputs(ff, stdout) == EOF)
			printf("output error");
	}


	if(ferror(stdin))
		printf("input error");


	return 0;

}



