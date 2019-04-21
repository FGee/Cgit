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
		pnew = NULL;//����Ҫ���Ѿ���ʼ��Ϊ��ָ�롣
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

	while (NULL != pcur1 && NULL != pcur2) {//������һ����β����ֹͣ
		if (pcur1 == *pphead1 && pcur2 == *pphead2 && pcur2->num < pcur1->num) {
			*pphead1 = *pphead2;//����ڸı�����һ��ͷ�������
			pcur2 = pcur2->pnext;//�������������һͷ���֮ǰ
			(*pphead1)->pnext = pcur1;//������������һ��ͷָ��Ϊͷָ��
			ppre1 = *pphead1;
		}
		if (pcur2->num < pcur1->num) {//�������������ǰԪ��ǰ��������һ������
			ppre1->pnext = pcur2;
			pcur2 = pcur2->pnext;
			ppre1->pnext->pnext = pcur1;
			ppre1 = ppre1->pnext;
		}
		else {
			ppre1 = pcur1;//��������1���α�ʹ���������������2ǰ������
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