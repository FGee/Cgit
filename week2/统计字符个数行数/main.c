#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define N 128
#define M 128

void count(unsigned *arr, char ch) 
{
	++arr[ch];
}

void printchar(unsigned *arr)
{
	for (int i = 'a'; i <= 'z'; ++i) {
		printf("%c:%8d\n", i, arr[i]);
	}
	for (int i = '0'; i <= '9'; ++i) {
		printf("%c:%8d\n", i, arr[i]);
	}
	printf("\\n:%8d\n", arr['\n']);
	printf(" :%8d\n", arr[' ']);
}

int wrdnum_of_str(const char *ps)
{
	int wrd_cnt = 0;
	int pre_is_space = true;
	for (int i = 0; ps[i] != '\0'; ++i) {
		if (pre_is_space && ps[i] != ' ') {
			pre_is_space = false;
			++wrd_cnt;
		}
		else if (ps[i] == ' ')
		{
			pre_is_space = true;
		}
	}
	return wrd_cnt;
}

int main(int argc, char* argv)
{
	unsigned arr[M] = { 0 };
	FILE *fprd;
	/*if (argc != 2) {
		perro("errror args\n");
		return -1;
		system("pause");
	}*/
	fprd = fopen("The_Holy_Bible_Res.txt", "r");
	if (NULL == fprd) {
		perror("fopen");
		return -1;
	}
	char c;
	while ((c = fgetc(fprd)) != EOF) {
		count(arr, c);
	}
	printchar(arr);
	fclose(fprd);

	system("pause");
	return 0;
}