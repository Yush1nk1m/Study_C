#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[16], strcp[16];
	char* index = strcp;
	int i;

	printf("�ܾ� �Է� : ");
	scanf("%s", str);
	strcpy(strcp, str);

	if (strlen(str) <= 5) printf("�Է��� �ܾ� : %s, ������ �ܾ� : %s\n", str, strcp);
	else
	{
		for (i = 0; i < 5; i++)
		{
			index++;
		}
		while (*index != '\0')
		{

			*index = '*';
			index++;
		}

		printf("�Է��� �ܾ� : %s, ������ �ܾ� : %s\n", str, strcp);
	}

	return 0;
}