#include <stdio.h>
#include <stdlib.h>

int** init_matrix(int width, int height)
{
	int** matrix = malloc(width*sizeof(int*)); //allocation memoire totale

	for(int i = 0; i < width; i++)
	{
		matrix[i] = malloc(height*sizeof(int));	//allocation memoire partielle

		for(int j = 0; j < height; j++)
		{
			matrix[i][j] = 0;
		}
	}

	return matrix;
}

