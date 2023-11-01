

#include <stdio.h>
#include <stdlib.h>

int nums_1(int n)
{
	int res = 0;
	for (int i = 0; i < 32; i++)
	{
		if (((n >> i) & 1) == 0)
		{
			res++;
		}
	}

	return res;
}

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		fprintf(stderr, "Usage...\n");
		exit(1);
	}
	
	int i = atoi(argv[1]);
	printf("%d\n", nums_1(i));
	exit(0);
}


