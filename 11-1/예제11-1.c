#include <stdio.h>

int main(void)
{
	char small, cap = 'G';

	if ((cap >= 'A') && (cap <= 'Z'))	// �빮�� �������
	{
		small = cap + ('a' - 'A');		// ��/�ҹ����� ���̸� ���� �ҹ��ڷ� ��ȯ
	}
	printf("�빮�� : %c %c", cap, '\n');
	printf("�ҹ��� : %c %c", small, '\n');

	return 0;
}