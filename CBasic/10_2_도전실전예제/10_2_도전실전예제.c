#include <stdio.h>

void input_nums(int* lotto_nums);
void print_nums(int* lotto_nums);

int main(void)
{
	int lotto_nums[6];

	input_nums(lotto_nums);
	print_nums(lotto_nums);
	return 0;
}

void input_nums(int* lotto_nums)
{
	int i = 0;
	int j;
	for (i = 0; i < 6; i++)
	{
		int repeat = 1;
		while (repeat != 0)
		{
			printf("번호 입력 : ");
			scanf("%d", lotto_nums + i);
			if (i == 0)
			{
				repeat = 0;
				break;
			}
			for (j = 0; j < i; j++)
			{
				if (lotto_nums[j] == lotto_nums[i])
				{
					repeat = 1;
					break;
				}
				else repeat = 0;
			}
			if (repeat == 1) printf("같은 번호가 있습니다!");
		}
	}
}

void print_nums(int* lotto_nums)
{
	int i;
	printf("로또 번호 : ");
	for (i = 0; i < 6; i++)
	{
		printf("%d  ", lotto_nums[i]);
	}
}