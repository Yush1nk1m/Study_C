#include <stdio.h>

int main(void)
{
	/* ���� �Ҵ� */
	int** matrix = (int**)malloc(4 * sizeof(int));
	int i;
	for (i = 0; i < 4; i++)
	{
		matrix[i] = (int*)malloc(5 * sizeof(int));
	}

	/* ��ȯ */
	for (i = 0; i < 4; i++)
	{
		free(matrix[i]);
	}
	free(matrix);
}