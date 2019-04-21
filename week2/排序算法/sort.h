#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10000
#define R 10000
#define SWAP(a,b) {int tmp;tmp=a;a=b;b=tmp;}

void merge(int* ar, int low, int mid, int high);
void  mergeSort(int* ar, int low, int high);
void arrCount(int* arr);