#include <stdio.h>
#include <string.h>

int main(void) {
	FILE* a = fopen("a.txt", "r");
	if (a == NULL) {
		printf("a.txt 개방 실패\n");
		return 1;
	}
	char word[10][20] = { 0 };
	char wordbuf[20];
	int i, checkEOF;
	for (i = 0; i < 10; i++) {
		checkEOF = fscanf(a, " %s ", wordbuf); // 단어 저장용 버퍼
		if (checkEOF == EOF) break;
		else strcpy(word[i], wordbuf);
	}

	FILE* b = fopen("b.txt", "r");
	if (b == NULL) {
		printf("b.txt 개방 실패\n");
		return 1;
	}
	FILE* c = fopen("c.txt", "w");
	if (c == NULL) {
		printf("c.txt 개방 실패\n");
		return 1;
	}
	int cmp, j, repeat;
	while (1) {
		checkEOF = fscanf(b, " %s ", wordbuf); // 단어 대조용 버퍼
		if (checkEOF == EOF) break;
		else {
			repeat = 0;
			for (j = 0; j < i; j++) {
				cmp = strcmp(wordbuf, word[j]);
				if (cmp == 0) repeat = 1;
			}
			if (repeat == 0) {
				fprintf(c, wordbuf);
				fputc('\n', c);
			}
		}
	}
	fclose(a); fclose(b); fclose(c);
}