#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define N 1024
#define M 128
#define true 1
#define false 0
#define MAXKEY 2000

int wrdnum_of_str(const char *ps, int *cnt)
{
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
	}
	return wrd_cnt;
}

int main(int argc, char* argv)
{
	unsigned cnt[MAXKEY];
	char buf[N];
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
	int count_word = 0;
	while ((fgets(buf, sizeof(buf), fprd)) != NULL) {
		count_word = count_word + wrdnum_of_str(buf, cnt);
	}
	printf("%d\n", count_word);
	fclose(fprd);

	system("pause");
	return 0;
}