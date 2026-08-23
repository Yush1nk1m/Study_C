#include <stdio.h>

int main(void)
{
	int int1, int2, result;
	char oper;
	printf("사칙연산 입력(정수) : ");
	scanf("%d%c%d", &int1, &oper, &int2);
	if (oper == '+')
	{
		result = int1 + int2;
	}
	else if (oper == '-')
	{
		result = int1 - int2;
	}
	else if (oper == '*')
	{
		result = int1 * int2;
	}
	else if (oper == '/')
	{
		result = int1 / int2;
	}
	else
	{
		printf("사칙연산이 아닙니다.");
	}

	printf("%d%c%d=%d\n", int1, oper, int2, result);

	return 0;
}