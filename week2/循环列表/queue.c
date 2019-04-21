#include "queue.h"

void initQueue(SqQue* psq)
{
	psq->front = psq->rear = 0;
}

int enQueue(SqQue* psq, Elem elem)
{
	if ((psq->rear + 1) % Maxsize == psq->front) {
		printf("It's full.\n");
			return 0;
	}
	else {
		psq->data[psq->rear] = elem;
		psq->rear = psq->rear++ % Maxsize;
		return 1;
	}
}

int deQueue(SqQue* psq, Elem * elem)
{
	if (psq->rear % Maxsize == psq->front) {
		printf("It's empty.\n");
		return 0;
	}
	else {
		*elem = psq->data[psq->front];
		psq->front = psq->front++ % Maxsize;
		return 1;
	}
}

int empty(SqQue* psq)
{
	if (psq->front == psq->rear) {
		return 1;
	}
	else {
		return 0;
	}
}