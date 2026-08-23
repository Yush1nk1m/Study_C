#include <stdio.h>

int main(void)
{
	int a;

	do
	{
		scanf("%d", &a);
	} while (a < 0);

	return 0;
}