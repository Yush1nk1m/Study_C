#include <stdio.h>

int rec_func(int n)
{
	if (n == 1) return 1;
	else return (n + rec_func(n - 1));
}

int main(void)
{
	int n;
	printf("���ڸ� �Է��ϼ��� : ");
	scanf("%d", &n);
	printf("1���� %d������ ���� %d�Դϴ�.", n, rec_func(n));

	return 0;
}