#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10

typedef struct {
	char *p;
	int size;
	int capacity;
}DynArr;

int main()
{
	DynArr d;
	d.size = 0;//≥ı ºªØ
	d.capacity = N;
	d.p = NULL;

	d.p = (char*)malloc(d.capacity);

	while (scanf("%c", d.p + d.size) != EOF) {
		d.size++;
		if (d.size == d.capacity) {
			d.capacity = d.capacity * 2;
			d.p = (char*)realloc(d.p, d.capacity);
		}
	}
	d.p[d.size - 1] = '\0';
	printf("%s\n", d.p);

	system("pause");
	return 0; 
}