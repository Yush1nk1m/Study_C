#include <stdio.h>

int main(void)
{
	/* 동적 할당 */
	int** matrix = (int**)malloc(4 * sizeof(int));
	int i;
	for (i = 0; i < 4; i++)
	{
		matrix[i] = (int*)malloc(5 * sizeof(int));
	}

	/* 반환 */
	for (i = 0; i < 4; i++)
	{
		free(matrix[i]);
	}
	free(matrix);
}