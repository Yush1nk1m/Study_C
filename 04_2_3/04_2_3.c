#include <stdio.h>

int main(void)
{
	int hour, min, sec;
	double time = 3.76;

	hour = (int)time;
	time -= (int)time;
	time *= 60.0;
	min = (int)time;
	time -= (int)time;
	time *= 60.0;
	sec = (int)time;
	printf("3.76�ð��� %d�ð� %d�� %d���Դϴ�.", hour, min, sec);

	return 0;
}