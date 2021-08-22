#include <stdio.h>

int main(void)
{
	int kor = 3, eng = 5, mat = 4;
	int credits;
	int res;
	double kscore = 3.8, escore = 4.4, mscore = 3.9;
	double grade;

	credits = kor + eng + mat;
	grade = (kscore * kor + escore * eng + mscore * mat) / credits;
	res = (credits >= 10) && (grade > 4.0);

	printf("%d\n", res);

	return 0;
}