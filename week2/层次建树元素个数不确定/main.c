#include <stdio.h>
#include <stdlib.h>

typedef char Elem;
typedef struct node {
	Elem c;
	struct node *pleft;
	struct node *pright;
}Node, *pNode;

typedef struct que{
	pNode p;
	struct que *pnext;
}Que_t, *pQue_t;

void preOrder(pNode p)
{
	if (p) {
		putchar(p->c);
		preOrder(p->pleft);
		preOrder(p->pright);
	}
	return;
}

int main()
{
	Elem c;
	pNode treeRoot = NULL, treeNew;
	pQue_t queHead = NULL, queTail = NULL, queNew, queFree;
	while (scanf("%c", &c) != EOF) {
		if (c == '\n') {
			break;
		}
		treeNew = (pNode)calloc(1, sizeof(Node));
		treeNew->c = c;
		queNew = (pQue_t)calloc(1, sizeof(Que_t));
		queNew->p = treeNew;
		if (NULL == treeRoot) {
			treeRoot = treeNew;
			queHead = queTail = queNew;
		}
		else {
			if (NULL == queHead->p->pleft) {
				queHead->p->pleft = treeNew;
			}
			else if (NULL == queHead->p->pright) {
				queHead->p->pright = treeNew;
				queFree = queHead;
				queHead = queHead->pnext;
				free(queFree);
			}
			queTail->pnext = queNew;
			queTail = queNew;
		}
	}

	preOrder(treeRoot);
	putchar('\n');

	system("pause");
	return 0;
}