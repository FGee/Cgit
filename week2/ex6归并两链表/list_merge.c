#include "listMerge.h"

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

void listMerge(pNode *pphead1, pNode *pptail1,
	pNode *pphead2, pNode *pptail2)
{
	pNode ppre1, pcur1, pcur2;
	ppre1 = *pphead1;
	pcur1 = *pphead1;
	pcur2 = *pphead2;

	while (NULL != pcur1 && NULL != pcur2) {//其中有一个达尾部即停止
		if (pcur1 == *pphead1 && pcur2 == *pphead2 && pcur2->num < pcur1->num) {
			*pphead1 = *pphead2;//针对于改变链表一的头结点的情况
			pcur2 = pcur2->pnext;//链表二插入链表一头结点之前
			(*pphead1)->pnext = pcur1;//新链表以链表一的头指针为头指针
			ppre1 = *pphead1;
		}
		if (pcur2->num < pcur1->num) {//当满足链表二当前元素前插至链表一的条件
			ppre1->pnext = pcur2;
			pcur2 = pcur2->pnext;
			ppre1->pnext->pnext = pcur1;
			ppre1 = ppre1->pnext;
		}
		else {
			ppre1 = pcur1;//右移链表1的游标使其产生可以让链表2前插的情况
			pcur1 = pcur1->pnext;
		}
	}
	if (NULL == pcur1) {
		ppre1 = pcur1;
		*pptail1 = *pptail2;
	}
	*pphead2 = NULL;
	*pptail2 = NULL;
}