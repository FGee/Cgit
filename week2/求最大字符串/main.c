#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *p, const void *q)
{
	char *p1 = *(char**)p;
	char *p2 = *(char**)q;
	return strcmp(p1, p2);
}

typedef int(*pfunc)(const void*, const void*);

void big(char **pArr, char **pbig1, char **pbig2)
{
	pfunc pcmp = &compare;
	qsort(pArr, 5, sizeof(char*), *pcmp);
	*pbig1 = pArr[4];
	*pbig2 = pArr[3];
}

int main()
{
	char *pArr[5] = { "xiongda","lele","hanmeimei","guangtouqiang","BeiJing" };
	char *pbig1, *pbig2;
	big(pArr, &pbig1, &pbig2);
	puts(pbig1);
	putchar('\n');
	puts(pbig2);
	putchar('\n');

	system("pause");
	return 0;
}