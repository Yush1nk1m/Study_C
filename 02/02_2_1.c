#include <stdio.h>

int main(void)
{
	printf("1�� 10���� : %d\n", 0B1011);
	printf("1�� 8���� : %o\n", 0B1011);
	printf("1�� 16���� : %X\n", 0B1011);
	printf("2�� 8���� : %o\n", 17);
	printf("2�� 16���� : %X\n", 17);
	printf("3�� 10���� : %d\n", 0X1A);
	printf("3�� 8���� : %o\n", 0X1A);
	printf("4�� 10���� : %d\n", 0101);
	printf("4�� 16���� : %X\n", 0101);

	return 0;
}
/* 2���� 
1�� : 1011
2�� : 10001
3�� : 11010
4�� : 100001*/