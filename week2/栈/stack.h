#include <stdio.h>
#include <stdlib.h>
#define Elem int 

typedef struct tag {
	Elem elem;
	struct tag *pnext;
}Node, *pNode;

typedef struct {
	pNode phead;
	int size;
}Stack, *pStack;

void initStack(pStack);
void pushStack(pStack, int);
void popStack(pStack);
int topStack(pStack);
int empty(pStack);
int size(pStack);


