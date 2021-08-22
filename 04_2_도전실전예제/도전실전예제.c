#include <stdio.h>

int main(void)
{
	double height, weight, bmi;
	printf("몸무게(kg)와 키(cm) 입력 : ");
	scanf("%lf%lf", &weight, &height);
	height /= 100.0;
	bmi = weight / (height * height);
	printf("%s\n", (bmi >= 20.0 && bmi < 25.0) ? "표준입니다." : "체중관리가 필요합니다.");

	return 0;
}