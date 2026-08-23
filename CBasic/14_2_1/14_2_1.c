#include <stdio.h>

int main(void)
{
	char* fruits[5] = { "apple", "pear", "peach", "banana", "melon" };
	int i;

	for (i = 0; i < 5; i++)
	{
		printf("%s\n", fruits[i]);
	}

	return 0;
}