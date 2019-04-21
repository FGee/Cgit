#include <stdio.h>	
#include <stdlib.h>
#include <time.h>
#define N1 14
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

void deleteRepeat(pNode *pphead)
{
	pNode pcur, ppre, ptemppre, ptempcur;
	ppre = pcur = *pphead;
	pcur = pcur->pnext;
	while (pcur) {
		if (pcur->num == ppre->num) {
			while (pcur != NULL && pcur->num == ppre->num) {
				pcur = pcur->pnext;
			}

			ptempcur = ppre->pnext;
			while (ptempcur != pcur) {//释放节点空间
				ptemppre = ptempcur;
				ptempcur = ptempcur->pnext;
				free(ptemppre);
			}

			ppre->pnext = pcur;//链接两条断链


			if (pcur != NULL) {//在不为尾节点的情况下右移
				ppre = pcur;
				pcur = pcur->pnext;
			}
		}
		else {
			ppre = pcur;
			pcur = pcur->pnext;
		}
	}
}

int main()
{
	pNode phead, ptail;
	int arr[N1] = { 5,5,5,7,8,8,8,15,24,26,56,78,89,89 };
	phead = ptail = NULL;
	for (int i = 0; i < N1; ++i) {
		list_sort_insert(&phead, &ptail, arr[i]);
	}
	print(phead);
	deleteRepeat(&phead);
	print(phead);
	

	system("pause");
	return 0;
}