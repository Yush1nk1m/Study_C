#include <stdio.h>

char* my_strcat(char* pd, char* ps);
int* my_strlen(char* ps);
int* my_strcmp(char* pa, char* pb);

int main(void)
{
	char str1[80] = "first";
	char str2[80] = "second";

	my_strcat(str2, str1);
	printf("%s\n", str2);
	printf("%d\n", my_strlen(str2));
	printf("%d\n", my_strcmp(str2, str1));

	return 0;
}

char* my_strcat(char* pd, char* ps)
{
	char* po = pd;

	while (*pd != '\0')
	{
		pd++;
	}
	while (*ps != '\0')
	{
		*pd = *ps;
		pd++;
		ps++;
	}
	*pd = '\0';

	return po;
}

int* my_strlen(char* ps)
{
	int cnt = 0;
	while (*ps != '\0')
	{
		cnt++;
		ps++;
	}
	return cnt;
}

int* my_strcmp(char* pa, char* pb)
{
	while ((*pa == *pb) && (*pa != '\0'))
	{
		pa++;
		pb++;
	}

	if (*pa > *pb) return 1;
	else if (*pa < *pb) return -1;
	else return 0;
}