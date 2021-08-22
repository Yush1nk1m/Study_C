#include <stdio.h>

void swap(double* pa, double* pb);
void line_up(double* maxp, double* midp, double* minp);

int main(void)
{
	double max, mid, min;

	printf("�Ǽ��� 3�� �Է� : ");
	scanf("%lf %lf %lf", &max, &mid, &min);
	line_up(&max, &mid, &min);
	printf("���ĵ� �� ��� : %.1lf, %.1lf, %.1lf\n", max, mid, min);

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
/* line_up �Լ� �ȿ��� "maxp", "midp", "minp"�� �ּҰ��� ��Ÿ����.
�̰��� swap �Լ��� �μ��� �����ϸ� swap �Լ� ���� �� �μ����� ����Ʈ��
�ּҰ��� �����ϰ� �ǹǷ� �׶� �۵��ϴ� ���̴�. */