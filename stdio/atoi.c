

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int year = 2023, month = 8, day = 21;
	char buf[1024];

	sprintf(buf, "%d-%d-%d", year, month, day);
	puts(buf);

	int i;
	char str[] = "12345";
	i = atoi(str);
	printf("i = %d\n", i);

	exit(0);

}



