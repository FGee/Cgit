#include <stdio.h>
#include <stdlib.h>
#define Maxsize 5

typedef int Elem;

typedef struct {
	Elem data[Maxsize];
	int front, rear;
} SqQue;

void initQueue(SqQue*);

int enQueue(SqQue*, Elem);

int deQueue(SqQue*, Elem);

int empty(SqQue*);