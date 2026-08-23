#include <stdio.h>
#define ADD(x, y) ((x) + (y))
#define SUB(x, y) ((x) + (y))
#define MUL(x, y) ((x) * (y))
#define DIV(x, y) ((x) / (y))

#define input_expression(x, op, y) scanf("%d %c %d", &x, &op, &y)

int main(void)
{
	int x, y, result;
	char op;

	while (1)
	{
		printf("수식 입력(종료 Ctrl+Z) : ");
		if (input_expression(x, op, y) < 0) break;

		switch (op)
		{
		case '+': result = ADD(x, y); break;
		case '-': result = SUB(x, y); break;
		case '*': result = MUL(x, y); break;
		case '/': result = DIV(x, y); break;
		}

		printf("%d %c %d = %d\n", x, op, y, result);
	}

	return 0;
}