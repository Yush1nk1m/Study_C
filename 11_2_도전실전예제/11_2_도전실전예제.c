#include <stdio.h>

int main(void)
{
	char ch;
	int endcheck, max;
	int i = 0;
	while (1)
	{
		endcheck = scanf("%c", &ch);
		if (endcheck == -1) break;
		while (ch != '\n')
		{
			i++;
			ch = getchar();
		}
		max = i; // ù �ܾ�
		while (1)
		{
			i = 0;
			endcheck = scanf("%c", &ch);
			if (endcheck == -1) break;
			while (ch != '\n')
			{
				i++;
				ch = getchar();
			}
			if (i > max) max = i;
		}
		printf("���� �� �ܾ��� ���� : %d\n", max);

		return 0;
	}
}