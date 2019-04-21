#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
	Stack stc;
	pStack ps = &stc;
	int val;
	initStack(ps);
	printf("%d\n", topStack(ps));
	scanf("%d", &val);
	pushStack(ps, val);
	scanf("%d", &val);
	pushStack(ps, val);
	printf("size = %d\n", size(ps));
	printf("empty yes or no: %s\n", (!empty(ps)) ? "yes" : "no");

	printf("%d\n", topStack(ps));
	popStack(ps);
	printf("%d\n", topStack(ps));
	popStack(ps);
	printf("size = %d\n", size(ps));
	printf("empty yes or no: %s\n", (!empty(ps)) ? "yes" : "no");
	

	return 0;
}