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
	printf("이름 : %s\n", mp->name);
	printf("나이 : %d\n", mp->age);
	if ((mp->sex) == 'm') printf("성별 : 남\n");
	else if ((mp->sex) == 'f') printf("성별 : 여\n");
	printf("키 : %.1lf\n", mp->height);

	return 0;
}