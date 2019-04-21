#include <stdio.h>	
#include <stdlib.h>	
#include <string.h>
#define PARR_MAXSIEZ 5

typedef struct student {
	int ID;
	char name[20];
	char gender;
	float chinese;
	float math;
	float english;
	float totalScore;
	struct student *pnext;
} Stu, *pStu;

void headInsert(pStu *pphead, pStu *pptail, pStu p_tmp_stu)
{
	pStu pnew;
	pnew = (pStu)calloc(1, sizeof(Stu));
	pnew->ID = p_tmp_stu->ID;
	strcpy(pnew->name, p_tmp_stu->name);
	pnew->gender = p_tmp_stu->gender;
	pnew->chinese = p_tmp_stu->chinese;
	pnew->math = p_tmp_stu->math;
	pnew->english = p_tmp_stu->english;
	pnew->totalScore = pnew->chinese + pnew->math + pnew->english;

	if (NULL == *pphead) {
		*pphead = pnew;
		*pptail = pnew;
	}
	else {
		pnew->pnext = *pphead;
		*pphead = pnew;
	}
}

void sort(pStu *pphead, pStu *pptail)
{
	pStu pnew, premain;
	premain = *pphead;
	*pphead = NULL;
	while (NULL != premain) {//链表的有序插入算法
		pnew = premain;
		premain = premain->pnext;
		pnew->pnext = NULL;
		pStu ppre, pcur;
		ppre = pcur = *pphead;
		if (NULL == *pphead) {
			*pphead = pnew;
			*pptail = pnew;
			pnew->pnext = NULL;
		}
		else if (pnew->totalScore > (*pphead)->totalScore) {//头插法
			pnew->pnext = *pphead;
			*pphead = pnew;
		}
		else {
			while (pcur) {
				if (pnew->totalScore > pcur->totalScore) {
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
}

void print(pStu phead, FILE *fpw)
{
	int ret;
	if (NULL == phead) {
		fprintf(fpw, "It's empty.\n");
	}
	else {
		while (NULL != phead) {
			ret = fprintf(fpw, "%d\t%s\t%c\t%5.2f\t%5.2f\t%5.2f\n",
				phead->ID, phead->name, phead->gender,
				phead->chinese, phead->math, phead->english);

			phead = phead->pnext;
		}
	}
}

int main()
{
	//pStu *parr;
	//parr = (pStu*)calloc(PARR_MAXSIEZ, sizeof(pStu));
	FILE *fp;
	fp = fopen("student.txt", "r+");
	if (NULL == fp) {
		perror("fopen");
		return -1;
	}
	pStu phead, ptail;
	phead = ptail = NULL;
	Stu tmp_stu;
	int ret;
	while ((ret = fscanf(fp, "%d\t%s\t%c\t%f\t%f\t%f\n", &tmp_stu.ID, tmp_stu.name,
		&tmp_stu.gender, &tmp_stu.chinese, &tmp_stu.math, &tmp_stu.english)) != EOF) {
		headInsert(&phead, &ptail, &tmp_stu);
	}
	FILE *fpw;
	fpw = fopen("output.txt", "w+");
	if (NULL == fpw) {
		perror("fopen");
		return -1;
	}
	sort(&phead, &ptail);
	print(phead, fpw);
	fclose(fp);
	fclose(fpw);

	//system("pause");
	return 0;
}