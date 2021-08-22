#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;	// �Է� ���� ���� ����
	int i, j;	// �ݺ� ���� ����

	printf("��� �Է� : ");
	scanf("%d", &n);

	int* num = (int*)malloc((n - 1) * sizeof(int));
	for (i = 0; i < (n - 1); i++)
	{
		num[i] = i + 2;
	}

	int primebool;
	for (i = 0; i < (n - 1); i++)
	{
		if (i == 0)
		{
			printf("%5d", num[i]);
		}
		else
		{
			for (j = 0; j < i; j++)
			{
				primebool = 0;
				if (num[i] % num[j] == 0)
				{
					primebool = 1;
					break;
				}
			}
			if (primebool == 1)
			{
				printf("    X");
			}
			else
			{
				printf("%5d", num[i]);
			}
		}
		if ((i + 1) % 5 == 0)
		{
			printf("\n");
		}
	}

	free(num);

	return 0;
}