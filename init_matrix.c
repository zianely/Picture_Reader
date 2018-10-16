#include <stdio.h>
#include <stdlib.h>

int** init_matrix(int width, int height)
{
	int** matrix = malloc(width*sizeof(int*));
	for(int i = 0; i < width; i++)
	{
		matrix[i] = malloc(height*sizeof(int));
		for(int j = 0; j < height; j++)
		{
			matrix[i][j] = 0;
		}
	}
	return matrix;

	/* printf("- Matrice unite :\n");
  	 
	 for(int i=0; i < 10; i++)
  	 {
     		 for(int j=0; j < 10; j++)
     		 {
        		 printf("%d ",matrix[i][j]);
     		 }
  		 printf("\n");
  	 }
 
 	  return 0;*/

}

