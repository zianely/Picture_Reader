#include <stdio.h>

void printarray(unsigned char *arr, int len)
{
	printf("\n");

	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");
}
