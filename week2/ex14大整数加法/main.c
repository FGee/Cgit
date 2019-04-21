#include <stdio.h>	
#include <stdlib.h>
#include <time.h>
#define N1 10
#define N2 8
int add1 = 0;

typedef struct Node {
	char c;
	struct Node *pnext;
}Node, *pNode;

void print(pNode phead)
{
	if (NULL == phead) {
		printf("It's empty.");
	}
	else {
		while (NULL != phead) {
			printf("%c", phead->c);
			phead = phead->pnext;
		}
	}
	printf("\n");
}

void head_insert(pNode *pphead, pNode *pptail, char ch)
{
	pNode pnew;
	pnew = (pNode)calloc(1, sizeof(Node));
	pnew->c = ch;
	if (NULL == *pphead) {
		*pphead = pnew;
		*pptail = pnew;
	}
	else {
		pnew->pnext = *pphead;
		*pphead = pnew;
	}
}

char add_unit(char ch1, char ch2)
{
	int num = ch1 - '0' + ch2 - '0';
	num = num + add1;
	if (num >= 10) {
		add1 = 1;
		return num % 10 + '0';
	}
	else {
		add1 = 0;
		return num + '0';
	}
}

void add(pNode *pphead, pNode *pptail, pNode *pphead2, pNode *pptail2)
{
	pNode ppre, pcur, ppre2, pcur2;
	ppre = pcur = *pphead;
	pcur2 = pcur2 = *pphead2;
	while (pcur && pcur2) {
		pcur->c = add_unit(pcur->c, pcur2->c);
		ppre = pcur;
		pcur = pcur->pnext;
		ppre2 = pcur2;
		pcur2 = pcur2->pnext;
		free(ppre2);
	}
	if (NULL == pcur && NULL != pcur2) {
		ppre->pnext = pcur2;
		pcur = pcur2;
		pcur->c = add_unit(pcur->c, '0');
		*pptail = *pptail2;
	}
	if (NULL != pcur && NULL == pcur2) {
		pcur->c = add_unit(pcur->c, '0');
	}
	if (NULL == pcur && NULL == pcur2) {
		if (add1 == 1) {
			pNode pnew;
			pnew = (pNode)calloc(1, sizeof(Node));
			pnew->c = add_unit('0', '0');
			ppre = pnew;
			*pptail = pnew;
		}
	}
}

void reverse(pNode *pphead)
{
	pNode ppre, pcur, pnew;
	ppre = pcur = pnew = *pphead;
	while (NULL != pcur) {
		if (*pphead == pcur) {
			pcur = ppre->pnext->pnext;
			pnew = ppre->pnext;
			pnew->pnext = ppre;

			(*pphead)->pnext = NULL;
		}
		else {
			ppre = pcur;
			pcur = ppre->pnext;
			ppre->pnext = pnew;
			pnew = ppre;
		}
	}
	*pphead = pnew;
}

int main()
{
	pNode phead, ptail, phead2, ptail2;
	int arr[N1] = { 1,2,3,4,5,6,7,8,9,10 };
	phead = ptail = NULL;
	phead2 = phead2 = NULL;
	char ch = 'a';
	while (scanf("%c", &ch)) {//不要用getchar，会读取空格
		if (ch == '\n') {
			break;
		}
		head_insert(&phead, &ptail, ch);
	}
	//print(phead);
	while (scanf("%c", &ch)) {//不要用getchar，会读取空格
		if (ch == '\n') {
			break;
		}
		head_insert(&phead2, &ptail2, ch);
	}
	//print(phead2);
	add(&phead, &ptail, &phead2, &ptail2);
	reverse(&phead);
	print(phead);


	system("pause");
	return 0;
}