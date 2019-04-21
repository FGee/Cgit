#include <stdio.h>	
#include <stdlib.h>
#define N 10

typedef char Elem;

typedef struct node {
	Elem elem;
	struct node *pleft;
	struct node *pright;
}Node, *pNode;

void preOrder(pNode p)
{
	if (p) {
		printf("%c", p->elem);
		preOrder(p->pleft);
		preOrder(p->pright);
	}
	//return;
}

void midOrder(pNode p)
{
	if (p) {
		preOrder(p->pleft);
		printf("%c", p->elem);
		preOrder(p->pright);
	}
	return;
}

void lastOrder(pNode p)
{
	if (p) {
		preOrder(p->pleft);
		preOrder(p->pright);
		printf("%c", p->elem);
	}
	//return;
}

int main()
{
	Elem elarr[N + 1] = "ABCDEFGHIJ";
	pNode parr[N];
	for (int i = 0; i < N; ++i) {
		parr[i] = (pNode)calloc(1, sizeof(Node));
		parr[i]->elem = elarr[i];
	}
	pNode treenode = parr[0];

	for (int i = 1, j = 0; i < N; ++i) {//²ã´Î½¨Ê÷
		if (parr[j]->pleft == NULL) {
			parr[j]->pleft = parr[i];
		}
		else if (parr[j]->pright == NULL) {
			parr[j]->pright = parr[i];
			++j;
		}
	}

	preOrder(treenode);
	printf("\n-------------------------\n");
	midOrder(treenode);
	printf("\n-------------------------\n");
	lastOrder(treenode);
	printf("\n-------------------------\n");



	return 0;
	system("pause");
}