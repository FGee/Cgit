#include <stdio.h>	
#include <stdlib.h>
#include <time.h>
#define N1 9
#define N2 13

typedef struct Node {
	int num;
	struct Node *pnext;
}Node, *pNode;

void print(pNode phead);
void list_sort_insert(pNode *pphead, pNode *pptail, int i);
void listMerge(pNode *pphead1, pNode *pptail1,
	pNode *pphead2, pNode *pptail2);
