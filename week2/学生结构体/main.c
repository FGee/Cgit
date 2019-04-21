#include <stdio.h>	
#include <stdlib.h>
#include <string.h>
#include "func.h"

int main()
{
	pStu phead1, phead2, ptail1, ptail2;
	phead1 = ptail1 = phead2 = ptail2 = NULL;
	scan(&phead1, &ptail1);
	print(phead1);
	scan(&phead2, &ptail2);
	print(phead2);
	list_merge(&phead1, &ptail1, &phead2, &ptail2);
	print(phead1);

	return 0;
}