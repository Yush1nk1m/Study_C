#include <stdio.h>

void sum(int count);

int main(void)
{
	sum(10);
	sum(100);
	return 0;
}

void sum(int count)
{
	int result = 0, i;

	for (i = 1; i <= count; i++)
	{
		result += i;
	}

	printf("1���� %d������ ���� %d�Դϴ�.\n", count, result);

	return;
}