#include <stdio.h>
#include <string.h>

int main(int ac, char ** av)
{
	char str[1024];
	int j=0;
	for (int i=0; i< strlen(av[1]);i++)
	{
		str[i] =  av[1][i]-j;
		j++;		
	}
	printf("%s", str);
}
