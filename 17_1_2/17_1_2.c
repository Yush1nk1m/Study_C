#include <stdio.h>

struct cracker
{
	int price;
	int calories;
};

int main(void)
{
	struct cracker basasac;
	printf("�ٻ���� ���ݰ� ������ �Է��ϼ��� : ");
	scanf("%d%d", &basasac.price, &basasac.calories);
	printf("�ٻ���� ���� : %d��\n", basasac.price);
	printf("�ٻ���� ���� : %dkcal\n", basasac.calories);

	return 0;
}