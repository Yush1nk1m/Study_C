#include <stdio.h>

int main(void)
{
	char small, cap = 'G';

	if ((cap >= 'A') && (cap <= 'Z'))	// 대문자 범위라면
	{
		small = cap + ('a' - 'A');		// 대/소문자의 차이를 더해 소문자로 변환
	}
	printf("대문자 : %c %c", cap, '\n');
	printf("소문자 : %c %c", small, '\n');

	return 0;
}