#include <stdio.h>	
#include <stdlib.h>
#include <time.h>
#define N1 10
#define N2 8
int ind = 0;

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

void odd_even(pNode *pphead, pNode *pptail, pNode *pphead2, pNode *pptail2)
{
	pNode pcur, ppre, pcur2;
	ppre = pcur = *pphead;
	pcur2 = *pphead2;
	while (pcur && pcur->pnext) {
		while (pcur && ind < 2) {
			pcur = pcur->pnext;
			++ind;
		}
		if (ind == 1) {//偶数情况
			if (pcur2 == NULL) {
				*pphead = ppre->pnext;
				pcur2 = *pphead;
			}
			else {
				pcur2->pnext = ppre->pnext;
				pcur2 = ppre->pnext;
			}
			ppre->pnext = NULL;
			*pptail = ppre;
		}
		if (ind == 2) {//奇数情况
			if (pcur2 == NULL) {
				*pphead2 = ppre->pnext;
				pcur2 = *pphead2;
			}
			else {
				pcur2->pnext = ppre->pnext;
				pcur2 = ppre->pnext;
			}
			ppre->pnext = pcur;
			ppre = pcur;
			ind = 0;
		}
	}
	*pptail = ppre;
	pcur2->pnext = NULL;
	*pptail2 = pcur2;
}

int main()
{
	pNode phead, ptail, phead2, ptail2;
	int arr[N1] = { 1,2,3,4,5,6,7,8,9,10 };
	phead = ptail = NULL;
	phead2 = phead2 = NULL;
	for (int i = 0; i < N1; ++i) {
		list_sort_insert(&phead, &ptail, arr[i]);
	}
	print(phead);
	odd_even(&phead, &ptail, &phead2, &ptail2);
	print(phead);
	print(phead2);


	system("pause");
	return 0;
}