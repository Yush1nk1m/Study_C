#include <stdio.h>

int main(void)
{
	int num, grade;

	printf("�й� �Է� : ");
	scanf("%d", &num);
	getchar();
	printf("���� �Է� : ");
	grade = getchar();
	printf("�й� : %d, ���� : %c\n", num, grade);

	return 0;
}