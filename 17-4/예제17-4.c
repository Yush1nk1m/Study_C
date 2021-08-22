#include <stdio.h>

struct student		// 학생 구조체 선언
{
	int id;			// 학번
	char name[20];	// 이름
	double grade;	// 학점
};

int main(void)
{
	struct student s1 = { 315, "홍길동", 2.4 },	// 구조체 변수 선언과 초기화
		s2 = { 316, "이순신", 3.7 },
		s3 = { 317, "세종대왕", 4.4 };

	struct student max;							// 최고 학점을 저장할 구조체 변수

	max = s1;
	if (s2.grade > max.grade) max = s2;
	if (s3.grade > max.grade) max = s3;

	printf("학번 : %d\n", max.id);
	printf("이름 : %s\n", max.name);
	printf("학점 : %.1lf\n", max.grade);

	return 0;
}