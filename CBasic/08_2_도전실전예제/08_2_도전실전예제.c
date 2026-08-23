#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[100], str2[100];
	char small[27] = "abcdefghijklmnopqrstuvwxyz", big[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	printf("문장 입력 : ");
	scanf("%s", str1);
	
	int n = 0;
	int i;
	while (str1[n] != '\0')
	{
		for (i = 0; i <= 25; i++)
		{
			if (str1[n] == big[i])
			{
				str2[n] = small[i];
				break;
			}
			else 
			{
				str2[n] = str1[n];
				continue;
			}
		}
		n++;
	}
	str2[n] = '\0';
	printf("바뀐 문장 : %s\n", str2);

	return 0;
}