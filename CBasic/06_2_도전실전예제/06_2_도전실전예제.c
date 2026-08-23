#include <stdio.h>

int main(void)
{
	int num, p1, p2, jumpcount = 0;

	printf("2 이상의 정수를 입력하세요 : ");
	scanf("%d", &num);

	for (p1 = 2; p1 <= num; p1++) // 소수 판별할 수 = p1
	{
		if (p1 == 2)
		{
			printf("\t%d", p1);
			jumpcount++;
		}
		else
		{
			p2 = 2;
			while (p2 <= p1)
			{
				if (p2 == p1)
				{
					printf("\t%d", p1);
					jumpcount++;
					if ((jumpcount % 5) == 0)
					{
						printf("\n");
					}
					break;
				}
				else if ((p1 % p2) == 0)
				{
					break;
				}
				else
				{
					p2++;
				}
			}
		}
	}

	return 0;
}