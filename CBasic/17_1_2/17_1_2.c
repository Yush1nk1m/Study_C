#include <stdio.h>

struct cracker
{
	int price;
	int calories;
};

int main(void)
{
	struct cracker basasac;
	printf("바사삭의 가격과 열량을 입력하세요 : ");
	scanf("%d%d", &basasac.price, &basasac.calories);
	printf("바사삭의 가격 : %d원\n", basasac.price);
	printf("바사삭의 열량 : %dkcal\n", basasac.calories);

	return 0;
}