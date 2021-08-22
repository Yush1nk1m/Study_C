#include <stdio.h>

void ascend(struct GRADE* grading, int num);

typedef struct GRADE
{
	int num;
	char name[20];
	int kor, eng, math, total;
	double average;
	char grd;
}Grade;

int main(void)
{
	Grade grade[5] = { 0 };
	int i;
	for (i = 0; i < 5; i++)
	{
		printf("�й� : ");
		scanf("%d", &(grade[i].num));
		printf("�̸� : ");
		scanf(" %s", &(grade[i].name));
		printf("����, ����, ���� ���� : ");
		scanf("%d%d%d", &(grade[i].kor), &(grade[i].eng), &(grade[i].math));
		grade[i].total = grade[i].kor + grade[i].eng + grade[i].math;
		grade[i].average = grade[i].total / 3.0;
		if (grade[i].average >= 90.0) grade[i].grd = 'A';
		else if (grade[i].average >= 80.0) grade[i].grd = 'B';
		else if (grade[i].average >= 70.0) grade[i].grd = 'C';
		else grade[i].grd = 'F';
	}

	printf("# ���� �� ������...\n");
	for (i = 0; i < 5; i++)
	{
		printf("%5d%10s%5d%5d%5d%5d%5.1lf%5c\n", grade[i].num, grade[i].name,
			grade[i].kor, grade[i].eng, grade[i].math, grade[i].total,
			grade[i].average, grade[i].grd);
	}
	ascend(grade, 5);
	printf("# ���� �� ������...\n");
	for (i = 0; i < 5; i++)
	{
		printf("%5d%10s%5d%5d%5d%5d%5.1lf%5c\n", grade[i].num, grade[i].name,
			grade[i].kor, grade[i].eng, grade[i].math, grade[i].total,
			grade[i].average, grade[i].grd);
	}
}

void ascend(struct GRADE* grading, int num)
{
	int i, j;
	Grade temp;
	num--;
	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num - i; j++)
		{
			if (grading[j].total < grading[j + 1].total)
			{
				temp = grading[j];
				grading[j] = grading[j + 1];
				grading[j + 1] = temp;
			}
		}
	}
}