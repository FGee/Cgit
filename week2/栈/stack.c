#include "stack.h"

void initStack(pStack ps)
{
	ps->phead = NULL;
	ps->size = 0;
}

void pushStack(pStack ps, int val)
{
	pNode pnew;
	pnew = (pNode)calloc(1, sizeof(Node));
	pnew->elem = val;
	if (ps->phead == NULL) {
		ps->phead = pnew;
		ps->size = 1;
	}
	else {
		pnew->pnext = ps->phead;
		ps->phead = pnew;
		ps->size++;
	}
}

int topStack(pStack ps)
{
	if (NULL == ps->phead) {
		printf("It's empty.\n");
		return 0;
	}
	else {
		return ps->phead->elem;
	}
}

void popStack(pStack ps)
{
	if (NULL == ps->phead) {
		printf("It's empty.");
		return;
	}
	else {
		ps->phead = ps->phead->pnext;
		ps->size--;
	}
}

int empty(pStack ps)
{
	if (NULL == ps->phead){
		return ps->phead;
	}
	else {
		return ps->phead;
	}
}

int size(pStack ps)
{
	return ps->size;
}