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
	printf("3.76시간은 %d시간 %d분 %d초입니다.", hour, min, sec);

	return 0;
}