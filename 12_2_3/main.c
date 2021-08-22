#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[16], strcp[16];
	char* index = strcp;
	int i;

	printf("단어 입력 : ");
	scanf("%s", str);
	strcpy(strcp, str);

	if (strlen(str) <= 5) printf("입력한 단어 : %s, 생략한 단어 : %s\n", str, strcp);
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

		printf("입력한 단어 : %s, 생략한 단어 : %s\n", str, strcp);
	}

	return 0;
}