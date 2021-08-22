#include <stdio.h>
#include <string.h>

void swap(char* type, void* pa, void* pb);

int main(void)
{
	int age1, age2;
	double height1, height2;

	printf("ù ��° ����� ���̿� Ű �Է� : ");
	scanf("%d%lf", &age1, &height1);
	printf("�� ��° ����� ���̿� Ű �Է� : ");
	scanf("%d%lf", &age2, &height2);

	swap("int", &age1, &age2);
	swap("double", &height1, &height2);

	printf("ù ��° ����� ���̿� Ű : %d, %.1lf\n", age1, height1);
	printf("�� ��° ����� ���̿� Ű : %d, %.1lf\n", age2, height2);

	return 0;
}

void swap(char* type, void* pa, void* pb)
{
	int itemp;
	double dtemp;

	if (strcmp(type, "int") == 0)
	{
		itemp = *(int*)pa;
		*(int*)pa = *(int*)pb;
		*(int*)pb = itemp;
	}

	else if (strcmp(type, "double") == 0)
	{
		dtemp = *(double*)pa;
		*(double*)pa = *(double*)pb;
		*(double*)pb = dtemp;
	}
}