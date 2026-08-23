#include <stdio.h>

double centi_to_meter(double height_centi);

int main(void)
{
	double res;

	res = centi_to_meter(187);
	printf("%.2lfm\n", res);

	return 0;
}

double centi_to_meter(double height_centi)
{
	double res, height_meter;

	height_meter = height_centi / 100.0;

	return height_meter;
}