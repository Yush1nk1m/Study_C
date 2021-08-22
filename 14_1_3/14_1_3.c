#include <stdio.h>

int main(void) {
	char mark[5][5] = { 0 };
	int i, j;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (i == j) mark[i][j] = 'X';
		}
	}
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%c ", mark[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	char mark2[5][5] = { 0 };
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if ((i == j) || (i + j == 4)) mark2[i][j] = 'X';
		}
	}
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%c ", mark2[i][j]);
		}
		printf("\n");
	}

	return 0;
}