#include <stdio.h>
#include "pixbuf2binmtx.h"

void printmatrix(int x, int y,int **p_arr)
{
  	printf("\n");

  	for(int i = 0; i < x; i++)
  	{
    		for(int j = 0; j < y; j++)
    		{
			printf("%d ", p_arr[i][j]);
    		}

    		printf("\n");
  	}

  	printf("\n");

}
