#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[20], str2[20], str3[20];
	printf("세 단어 입력 : ");
	scanf("%s%s%s", str1, str2, str3);

	if (strcmp(str1, str2) == -1) // str1 > str2
	{
		if (strcmp(str2, str3) == -1) // str1 > str2 > str3
		{
			printf("%s, %s, %s\n", str1, str2, str3);
		}
		else if (strcmp(str1, str3) == 1) // str3 > str1 > str2
		{
			printf("%s, %s, %s\n", str3, str1, str2);
		}
		else // str1 >= str3 >= str2
		{
			printf("%s, %s, %s\n", str1, str3, str2);
		}
	}
	else // str2 >= str1
	{
		if (strcmp(str2, str3) == 1) // str3 > str2 >= str1
		{
			printf("%s, %s, %s\n", str3, str2, str1);
		}
		else  if (strcmp(str1, str3) == -1) // str2 >= str1 > str3
		{
			printf("%s, %s, %s\n", str2, str1, str3);
		}
		else // str2 >= str3 >= str1
		{
			printf("%s, %s, %s\n", str2, str3, str1);
		}
	}

	return 0;
}