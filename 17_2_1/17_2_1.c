#include <stdio.h>

struct marriage
{
	char name[20];
	int age;
	char sex;
	double height;
};

int main(void)
{
	struct marriage m1 = { "Andy", 22, 'm', 187.5 };
	struct marriage* mp = &m1;
	printf("�̸� : %s\n", mp->name);
	printf("���� : %d\n", mp->age);
	if ((mp->sex) == 'm') printf("���� : ��\n");
	else if ((mp->sex) == 'f') printf("���� : ��\n");
	printf("Ű : %.1lf\n", mp->height);

	return 0;
}