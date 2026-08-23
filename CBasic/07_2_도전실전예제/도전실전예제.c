#include <stdio.h>

int rec_func(int n)
{
	if (n == 1) return 1;
	else return (n + rec_func(n - 1));
}

int main(void)
{
	int n;
	printf("숫자를 입력하세요 : ");
	scanf("%d", &n);
	printf("1부터 %d까지의 합은 %d입니다.", n, rec_func(n));

	return 0;
}