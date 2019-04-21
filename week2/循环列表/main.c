#include "queue.h"

int main()
{
	SqQue sq;
	Elem elem;
	initQueue(&sq);
	enQueue(&sq, 5);
	enQueue(&sq, 6);
	enQueue(&sq, 7);
	enQueue(&sq, 8);
	enQueue(&sq, 9);

	printf("empty :%s\n", (empty(&sq)) ? "yes" : "no");

	deQueue(&sq, &elem);
	printf("%d\n", elem);
	deQueue(&sq, &elem);
	printf("%d\n", elem);
	deQueue(&sq, &elem);
	printf("%d\n", elem);
	deQueue(&sq, &elem);
	printf("%d\n", elem);
	deQueue(&sq, &elem);
	printf("empty :%s\n", (empty(&sq)) ? "yes" : "no");

	system("pause");
	return 0;
}