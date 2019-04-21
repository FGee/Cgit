#include "func.h"

void scan(pStu *pphead, Stu **pptail)
{
	int val;
	while (scanf("%d", &val) != EOF) {
		list_sort_insert(pphead, pptail, val);
	}
}

void print(pStu phead)
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

void list_tail_insert(pStu *pphead, Stu **pptail, int i)
{
	pStu pnew = (pStu)calloc(1, sizeof(Stu));
	pnew->num = i;
	if (NULL == *pptail) {
		*pptail = pnew;
		*pphead = pnew;
	}
	else {
		(*pptail)->pnext = pnew;
		*pptail = pnew;
	}
	pnew->pnext = NULL;
}

void list_head_insert(pStu *pphead, pStu *pptail, int i)
{
	pStu pnew = (pStu)malloc(sizeof(Stu));
	memset(pnew, 0, sizeof(Stu));
	pnew->num = i;
	if (NULL == *pphead) {
		*pptail = pnew;
		*pphead = pnew;
		pnew->pnext = NULL;
	}
	else {
		pnew->pnext = *pphead;
		*pphead = pnew;
	}
}

void list_sort_insert(pStu *pphead, pStu *pptail, int i)
{
	pStu pnew = (pStu)calloc(1, sizeof(Stu));
	pnew->num = i;
	pStu pcur, ppre;
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
		while (pcur) {//插入中间
			if (i < pcur->num) {
				ppre->pnext = pnew;
				pnew->pnext = pcur;
				break;
			}
			ppre = pcur;
			pcur = pcur->pnext;
		}
		if (NULL == pcur) {//尾插
			(*pptail)->pnext = pnew;
			*pptail = pnew;
		}
	}
}

void list_delete(pStu *pphead, pStu *pptail, int i)
{
	pStu pnew = (pStu)calloc(1, sizeof(Stu));
	pnew->num = i;
	pStu pcur, ppre;
	pcur = ppre = *pphead;
	if (NULL == *pphead) {
		printf("It's empty.\n");
		return;
	}
	else if (i == pcur->num) { //删除的是头结点
		*pphead = pcur->pnext;
		if (NULL == *pphead) {//可能删除后链表为空
			*pptail = NULL;
		}
		//free(ppre);
	}
	else {
		while (pcur) {
			if (i == pcur->num) {
				ppre->pnext = pcur->pnext;//@1
				//free(ppre);
				break;
			}
			ppre = pcur;
			pcur = pcur->pnext;
		}
		if (pcur == *pptail) {//删除的是尾节点
			*pptail = ppre;
			//(*pptail)->pnext = NULL;不需要，有@1
			//free(ppre);
		}
		if (NULL == pcur) {//不再该链表内
			printf("The elem isn't exist.\n");
			return;
		}
	}
	free(pcur);
	if (NULL == *pphead) {
		printf("It's empty.\n");
	}
}

void list_merge(pStu *pphead1, pStu *pptail1, pStu *pphead2, pStu *pptail2)
{
	pStu ppre1, ppre2, pcur1, pcur2;
	ppre1 = pcur1 = *pphead1;
	ppre2 = pcur2 = *pphead2;
	if ((*pphead1)->num > (*pphead2)->num) {
		ppre2 = pcur2;
		pcur2 = pcur2->pnext;

		ppre2->pnext = pcur1;
		*pphead1 = ppre2;

		ppre1 = *pphead1;
	}
	while (*pptail1 == pcur1 && *pptail2 == pcur2) {
		if (pcur1->num >= pcur2->num) {
			ppre2 = pcur2;
			pcur2 = pcur2->pnext;

			ppre1->pnext = ppre1;
			ppre1->pnext = pcur1;

			ppre1 = ppre2;
			ppre2 = NULL;
		}
		else if (pcur1->num < pcur2->num) {
			ppre2 = pcur2;
			pcur2 = pcur2->pnext;

			ppre1 = pcur1;
			pcur1 = pcur1->pnext;

			ppre1 = ppre2;
			ppre2->pnext = pcur1;

			ppre1 = ppre2;
			ppre2 = NULL;
		}
	}
	if (NULL == pcur1 && NULL != pcur2) {
		ppre1->pnext = pcur2;
		*pptail1 = *pptail2;
	}
	*pphead2 = NULL;
	*pptail2 = NULL;
}

