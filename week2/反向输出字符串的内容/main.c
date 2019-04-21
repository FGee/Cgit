#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 30

void reverse(char *p, char *q)
{
	while (p < q) {
		char temp = *p;
		*p = *q;
		*q = temp;
		++p;
		--q;
	}
}

int main()
{
	char *buff;
	buff = (char*)calloc(N, sizeof(char));

	while (gets(buff) != NULL) {//gets()²»¶ÁÈ¡¿Õ¸ñ
		reverse(buff, buff + strlen(buff) - 1);
		char *ppre, *pcur;
		ppre = pcur = buff;
		while (*pcur != '\0') {
			while (*pcur == ' ' && *pcur != '\0') {
				++pcur;
			}
			ppre = pcur;
			while (*pcur != ' ' && *pcur != '\0') {
				++pcur;
			}
			reverse(ppre, pcur  - 1);
		}
		puts(buff);
	}

	system("pause");
	return 0;
}