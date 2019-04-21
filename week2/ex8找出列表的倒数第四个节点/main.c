#include <stdio.h>	
#include <stdlib.h>
#include <time.h>
#define N1 9
#define N2 13

typedef struct Node {
	int num;
	struct Node *pnext;
}Node, *pNode;

void print(pNode phead)
{
	if (NULL == phead) {
		printf("It's empty.");
	}
	else {
		while (NULL != phead) {
			printf("%5d", phead->num);
			phead = phead->pnext;
		}
	}
	printf("\n");
}

void list_sort_insert(pNode *pphead, pNode *pptail, int i)
{
	pNode pnew = (pNode)calloc(1, sizeof(Node));
	pnew->num = i;
	pNode pcur, ppre;
	pcur = ppre = *pphead;
	if (NULL == *pphead) {
		*pphead = pnew;
		*pptail = pnew;
		pnew = NULL;//不需要，已经初始化为空指针。
	}
	else if (i < (*pphead)->num) {
		pnew->pnext = *pphead;
		*pphead = pnew;
	}
	else {
		while (pcur) {
			if (i < pcur->num) {
				ppre->pnext = pnew;
				pnew->pnext = pcur;
				break;
			}
			ppre = pcur;
			pcur = pcur->pnext;
		}
		if (NULL == pcur) {
			(*pptail)->pnext = pnew;
			*pptail = pnew;
		}
	}
}

pNode lastFifth(pNode *pphead)
{
	pNode pfifth, pcur;
	pcur = pfifth = *pphead;
	for (int i = 0; i < 4; ++i) {
		pcur = pcur->pnext;
	}
	while (pcur) {
		pcur = pcur->pnext;
		pfifth = pfifth->pnext;
	}
	return pfifth;
}

int main()
{
	pNode phead, ptail;
	phead = ptail = NULL;
	srand(time(NULL));
	for (int i = 0; i < N1; ++i) {
		list_sort_insert(&phead, &ptail, rand() % 100);
	}
	print(phead);
	printf("%d\n", lastFifth(&phead)->num);

	system("pause");
	return 0;
}