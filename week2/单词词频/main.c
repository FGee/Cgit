#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define N 1024
#define M 128
#define true 1
#define false 0
#define MAXKEY 2000
#define R 2000

typedef struct word {
	int num;
	char wrd[50];
}Word, *pWord;

int deleteNull(pWord *ar, pWord *parnew, int sz) {//����û�ж�Ӧ��ϣֵ�Ŀ�ָ��
	int a = 0, b = 0;
	for (int i = 0; i < sz; ++i) {
		if (NULL != ar[i]) {
			parnew[a] = ar[i];
			++a;
		}
	}
	return a;
}

void  shellSort(pWord *ar, int sz)//ϣ������
{
	int cn = (double)log(sz - 1) / (double)log(2);
	int paSt = cn - 0; //P&S����
	for (int x = 0; paSt > 0; ++x) {
		for (int m = 0; m < sz; ) {
			int i, j;//��������
			pWord temp;
			for (i = m + paSt; i < sz; ++i) {
				temp = ar[i];
				j = i - paSt;
				while (j >= m && temp->num < ar[j]->num) {
					ar[j + paSt] = ar[j];
					j = j - paSt;
				}
				ar[j + paSt] = temp;
				i += paSt;
			}
			m = m + paSt;
		}
		paSt = cn - x;
	}
}

int elf_hash(char *key)//��ϣ��ʽ
{
	int h = 0, g;
	while (*key)
	{
		h = (h << 4) + *key++;
		g = h & 0xf0000000;
		if (g)
			h ^= g >> 24;
		h &= ~g;
	}
	return h % MAXKEY;
}

void wrdnum_of_str(const char *ps, pWord *parr)//ͳ�Ʊ����Ƶ
{
	char word[50];
	int n = 0;
	int wrd_cnt = 0;
	int pre_is_space = true;
	for (int i = 0; ps[i] != '\n'; ++i) {
		if (pre_is_space && ps[i] != ' ') {
			pre_is_space = false;
			++wrd_cnt;
		}
		else if (ps[i] == ' ')
		{
			pre_is_space = true;
		}
		if (ps[i] != ' ') {
			word[n++] = ps[i];
		}
		else if (pre_is_space == 1 && ps[i-1] != ' ') {
			word[n] = '\0';
			//printf("%s\n", word);
			int hash;//��������ͬ
			hash = elf_hash(word);
			if (NULL == parr[hash]) {
				parr[hash] = (pWord)calloc(1, sizeof(Word));
				strcpy(parr[hash]->wrd, word);
			}
			++parr[hash]->num;
			n = 0;
			//puts(parr[hash]->wrd);
		}
	}
	if (pre_is_space == 0) {//���Ի��з������ĵ�����ͳ��
		word[n] = '\0';
		int hash;
		hash = elf_hash(word);
		if (NULL == parr[hash]) {
			parr[hash] = (pWord)calloc(1, sizeof(Word));
			strcpy(parr[hash]->wrd, word);
		}
		++parr[hash]->num;
		n = 0;
	}
}

int main(int argc, char* argv)
{
	//char *pArr[10];
	pWord parr[MAXKEY] = { 0 };//û�й��˿�ָ��
	char buf[N];
	FILE *fprd;
	pWord parrnew[MAXKEY] = { 0 };//�����˿�ָ�룬����ָ���word�ṹ��

	fprd = fopen("The_Holy_Bible_Res.txt", "r"); 
	//fprd = fopen("test_res1.txt", "r");
	if (NULL == fprd) {
		perror("fopen");
		return -1;
	}
	//printf("%d\n", cnt[MAXKEY - 1]);
	while ((fgets(buf, sizeof(buf), fprd)) != NULL) {
		wrdnum_of_str(buf, parr);
	}
	int newSize = deleteNull(parr, parrnew, MAXKEY);
	shellSort(parrnew, newSize);

	fclose(fprd);
	for (int i = newSize - 1; i > newSize - 11; --i) {
		printf("word:%-20s    count:%-10d\n", parrnew[i]->wrd, parrnew[i]->num);
	}

	system("pause");
	return 0;
}