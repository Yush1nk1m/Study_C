#include <stdio.h>

int main(void)
{
	FILE* afp, * bfp;
	int num = 10;
	int res;

	afp = fopen("a.txt", "wt");		// �ؽ�Ʈ ���� ��� ���� ����
	if (afp == NULL)
	{
		printf("���� ���� ����");
		return 1;
	}
	fprintf(afp, "%d", num);

	bfp = fopen("b.txt", "wb");
	if (bfp == NULL)
	{
		printf("���� ���� ����");
		return 1;
	}
	fwrite(&num, sizeof(num), 1, bfp);

	fclose(afp);
	fclose(bfp);

	bfp = fopen("b.txt", "rb");
	if (bfp == NULL)
	{
		printf("���� ���� ����");
		return 1;
	}
	fread(&res, sizeof(res), 1, bfp);
	printf("%d", res);

	fclose(bfp);

	return 0;
}