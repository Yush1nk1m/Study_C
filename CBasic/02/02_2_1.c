#include <stdio.h>

int main(void)
{
	printf("1행 10진수 : %d\n", 0B1011);
	printf("1행 8진수 : %o\n", 0B1011);
	printf("1행 16진수 : %X\n", 0B1011);
	printf("2행 8진수 : %o\n", 17);
	printf("2행 16진수 : %X\n", 17);
	printf("3행 10진수 : %d\n", 0X1A);
	printf("3행 8진수 : %o\n", 0X1A);
	printf("4행 10진수 : %d\n", 0101);
	printf("4행 16진수 : %X\n", 0101);

	return 0;
}
/* 2진수 
1행 : 1011
2행 : 10001
3행 : 11010
4행 : 100001*/