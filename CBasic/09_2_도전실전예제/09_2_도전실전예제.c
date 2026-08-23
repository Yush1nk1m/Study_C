#include <stdio.h>

void swap(double* pa, double* pb);
void line_up(double* maxp, double* midp, double* minp);

int main(void)
{
	double max, mid, min;

	printf("실수값 3개 입력 : ");
	scanf("%lf %lf %lf", &max, &mid, &min);
	line_up(&max, &mid, &min);
	printf("정렬된 값 출력 : %.1lf, %.1lf, %.1lf\n", max, mid, min);

	return 0;
}

void swap(double* pa, double* pb)
{
	double temp;

	temp = *pa;
	*pa = *pb;
	*pb = temp;
}

void line_up(double* maxp, double* midp, double* minp)
{
	if (*maxp < *midp)
	{
		if (*midp < *minp) // min > mid > max
		{
			swap(maxp, minp);
		}
		else // mid = 1st, max ? min
		{
			if (*maxp < *minp) // mid > min > max
			{
				swap(maxp, midp);
				swap(maxp, minp);
			}
			else // mid > max > min
			{
				swap(maxp, midp);
			}
		}
	}
	else // max > mid
	{
		if (*maxp > *minp) // max = 1st, mid ? min
		{
			if (*minp > *midp) // max > min > mid
			{
				swap(midp, minp);
			}
		}
		else // min > max > mid
		{
			swap(maxp, minp);
			swap(maxp, midp);
		}
	}
}
/* line_up 함수 안에서 "maxp", "midp", "minp"는 주소값을 나타낸다.
이것을 swap 함수의 인수로 전달하면 swap 함수 선언 시 인수였던 포인트는
주소값을 저장하게 되므로 그때 작동하는 것이다. */