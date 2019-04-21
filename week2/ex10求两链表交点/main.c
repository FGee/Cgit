#include <stdio.h>	
#include <stdlib.h>
#include <time.h>
#define N1 9
#define N2 8

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

int size(pNode *pphead)
{
	int cnt = 0;
	pNode pcur = *pphead;
	while (pcur) {
		pcur = pcur->pnext;
		++cnt;
	}
	return cnt;
}

pNode isIntersect(pNode *pphead1, pNode *pphead2, int diff)
{
	pNode pcur1, pcur2;
	pcur1 = *pphead1;
	pcur2 = *pphead2;
	if (diff > 0) {
		for (int i = 0; i < diff; ++i) {
			pcur1 = pcur1->pnext;
		}
	}
	else {
		for (int i = 0; i < -diff; ++i) {
			pcur2 = pcur2->pnext;
		}
	}
	while (pcur1 && pcur2) {
		if (pcur1 == pcur2) {
			return pcur1;
		}
		pcur1 = pcur1->pnext;
		pcur2 = pcur2->pnext;
	}
	return NULL;
}

int main()
{
	pNode phead1, ptail1, phead2, ptail2;
	int arr1[N1] = { 5,7,8,15,24,26,56,78,89 };
	int arr2[N2] = { 9,13,15,24,26,56,78,89 };
	phead1 = ptail1 = phead2 = ptail2 = NULL;
	srand(time(NULL));
	for (int i = 0; i < N1; ++i) {
		list_sort_insert(&phead1, &ptail1, arr1[i]);
	}
	print(phead1);
	for (int j = 0; j < N2; ++j) {
		list_sort_insert(&phead2, &ptail2, arr2[j]);
	}
	ptail2->pnext = phead1;
	ptail2 = ptail1;
	print(phead2);
	printf("%d %d\n", size(&phead1), size(&phead2));
	pNode pIntersect;
	pIntersect = isIntersect(&phead1, &phead2, size(&phead1) - size(&phead2));
	printf("%s : %d\n", (pIntersect) ? "yes" : "no", pIntersect->num);

	system("pause");
	return 0;
}