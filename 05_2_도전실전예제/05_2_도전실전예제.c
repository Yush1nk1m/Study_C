#include <stdio.h>

int main(void)
{
	int int1, int2, result;
	char oper;
	printf("��Ģ���� �Է�(����) : ");
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
		printf("��Ģ������ �ƴմϴ�.");
	}

	printf("%d%c%d=%d\n", int1, oper, int2, result);

	return 0;
}