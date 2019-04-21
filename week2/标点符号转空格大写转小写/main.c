#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define N 128
#define M 128

char punctoblank_tolower(char ch)
{
	if (isupper(ch)) {
		ch = ch - 'A' + 'a';
	}
	else if (islower(ch) || isdigit(ch) || ch == ' ' || ch == '\n') {
		ch = ch;
	}
	else {
		ch = ' ';
	}
	return ch;
}

int main(int argc, char* argv)
{
	//char buf[N];
	FILE *fprd, *fpwrt;
	/*if (argc != 2) {
		perro("errror args\n");
		return -1;
		system("pause");
	}*/
	fprd = fopen("The_Holy_Bible.txt", "r");
	if (NULL == fprd) {
		perror("fopen");
		return -1;
	}
	fpwrt = fopen("The_Holy_Bible_Res.txt", "w+");
	if (NULL == fpwrt) {
		perror("fopen");
		return -1;
	}
	char c;
	while ((c = fgetc(fprd)) != EOF) {
		fseek(fprd, 0, SEEK_CUR);
		c = punctoblank_tolower(c);
		fputc(c, fpwrt);
		count(arr, c);
		fseek(fpwrt, 0, SEEK_CUR);
	}
	fclose(fprd);
	fclose(fpwrt);

	system("pause");
	return 0;
}