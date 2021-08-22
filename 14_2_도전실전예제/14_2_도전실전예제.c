#include <stdio.h>

int main(void)
{
	int matrix[5][6] = { {0} };
	int i, j;
	int num = 1;
	// 초기화
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 5; j++)
		{
			matrix[i][j] = num;
			matrix[i][5] += matrix[i][j];
			matrix[4][j] += matrix[i][j];
			num++;
		}
	}
	i--;
	for (j = 0; j < 5; j++)
	{
		matrix[4][5] += matrix[i][j];
	}
	// 출력
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 6; j++)
		{
			printf("%5d", matrix[i][j]);
		}
		printf("\n");
	}

	return 0;
}