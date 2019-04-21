#include <stdio.h>	
#include <stdlib.h>
#include <string.h>

typedef struct student {
	int num;
	struct student *pnext;
}Stu, *pStu;

void scan(pStu *pphead, Stu **pptail);
void print(pStu phead);
void list_tail_insert(pStu *pphead, Stu **pptail, int i);
void list_sort_insert(pStu *pphead, pStu *pptail, int i);
void list_delete(pStu *pphead, pStu *pptail, int i);
void list_merge(pStu *pphead1, pStu *pptail1, pStu *pphead2, pStu *pptail2);