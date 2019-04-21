1.
//将包含字符数字的字符串分开,使得分开后的
//字符串前一部分是数字后一部分是字母
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 50

int main() {
	char str[N];
	gets(str);
	int len = strlen(str);
	for (int i = 0, ct = 0; i < len; ++i) {
		if (isdigit(str[i])) {
			int temp = str[ct];
			str[ct] = str[i];
			for (int j = i; j > ct + 1; --j) {
				str[j] = str[j - 1];
			}
			str[ct + 1] = temp;
			++ct;
		}
	}
	puts(str);
	printf("\n");

	system("pause");
	return 0;
}



2.
//将包含字符数字的字符串分开,使得分开后的
//字符串前一部分是数字后一部分是字母
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 50

void func1(char *str)//将包含字符数字的字符串分开,使得分开后的
//字符串前一部分是数字后一部分是字母
{
	int len = strlen(str);
	for (int i = 0, ct = 0; i < len; ++i) {
		if (isdigit(str[i])) {
			int temp = str[ct];
			str[ct] = str[i];
			for (int j = i; j > ct + 1; --j) {
				str[j] = str[j - 1];
			}
			str[ct + 1] = temp;
			++ct;
		}
	}
}

//------------------------------------------------

void func2(char *str)
{
	int len = strlen(str);
	for (int i = 0, ct = 0; i < len + ct; ++i) {
		if (str[i] == ' ') {
			int t = len + ct + 3;
			for (int j = t; j > i + 1; --j) {
				str[j] = str[j - 3];
			}
			str[i] = '%';
			str[i + 1] = '0';
			str[i + 2] = '2';
			str[i + 3] = '0';
			ct += 3;
		}
	}
}

int main() {
	char str[N];
	gets(str);
	func2(str);
	puts(str);
	printf("\n");

	system("pause");
	return 0;
}




3.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 50

void func1(char *str)//将包含字符数字的字符串分开,使得分开后的
//字符串前一部分是数字后一部分是字母
{
	int len = strlen(str);
	for (int i = 0, ct = 0; i < len; ++i) {
		if (isdigit(str[i])) {
			int temp = str[ct];
			str[ct] = str[i];
			for (int j = i; j > ct + 1; --j) {
				str[j] = str[j - 1];
			}
			str[ct + 1] = temp;
			++ct;
		}
	}
}

//------------------------------------------------

void func2(char *str)
{//将 字 符 串 中 的 空 格 替 换 成 “%020”
	int len = strlen(str);
	for (int i = 0, ct = 0; i < len + ct; ++i) {
		if (str[i] == ' ') {
			int t = len + ct + 3;
			for (int j = t; j > i + 1; --j) {
				str[j] = str[j - 3];
			}
			str[i] = '%';
			str[i + 1] = '0';
			str[i + 2] = '2';
			str[i + 3] = '0';
			ct += 3;
		}
	}
}

//--------------------------------------------------

void func3(char *str, char ch)
{//删除字符符串中指定的字
	int len = strlen(str);
	for (int i = 0, ct = 0; i < len - ct; ++i) {
		if (str[i] == ch) {
			for (int j = i; j < len - ct; ++j) {
				str[j] = str[j + 1];
			}
			++ct;
			--i;
		}
	}
}

int main() {
	char str[N]; char ch = 'h';
	getchar(ch);
	rewind(stdin);
	gets(str);
	func3(str, ch);
	puts(str);
	printf("\n");

	system("pause");
	return 0;
}



4.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 50
void func4(char *str)
{
	char pre = '\0';
	int len = strlen(str);
	for (int i = 0, ct = 0; i < len - ct; ++i) {
		if (str[i] == pre) {
			for (int j = i; j < len - ct; ++j) {//删除一个元素
				str[j] = str[j + 1];
			}
			++ct;
			--i;
		}
		else {
			pre = str[i];
		}
	}
}

int main() {
	char str[N];
	gets(str);
	func4(str);
	puts(str);
	printf("\n");

	system("pause");
	return 0;
}


5.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 50
void func5(char *str)
{//删除多余空格
	char pre = '\0';
	int len = strlen(str);
	for (int i = 0, ct = 0; i < len - ct; ++i) {
		if (pre == ' ' && str[i] == ' ') {
			for (int j = i; j < len - ct; ++j) {//删除一个元素
				str[j] = str[j + 1];
			}
			++ct;
			--i;
		}
		else if (str[i] == ' ') {
			pre = ' ';
		}
		else if (str[i] != ' ') {
			pre = str[i];
		}
	}
}

int main() {
	char str[N];
	gets(str);
	func5(str);
	puts(str);
	printf("\n");

	system("pause");
	return 0;
}



6.
//求一个字符串数组的最大值和次大值  
//big(char *arr[], int size, char** big1, char** big2)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 20
#define M 5

void big(char *arr[], int size, char** big1, char** big2)
{
	for (int i = 0; i < 2; ++i) {
		for (int j = i + 1; j < size; ++j) {
			if (strcmp(arr[i], arr[j]) < 0) {
				char* tp = arr[i];
				arr[i] = arr[j];
				arr[j] = tp;
			}
		}
	}
	*big1 = arr[0];
	*big2 = arr[1];
}

int main() {
	char str_arr[M][N];
	for (int i = 0; i < M; ++i) {
		gets(str_arr[i]);
	}
	char* pts[5];
	for (int i = 0; i < M; ++i) {
		pts[i] = str_arr[i];
	}
	char * ptbig1 = pts[0];
	char * ptbig2 = pts[1];
	big(pts, M, &ptbig1, &ptbig2);
	printf("%s\n%s\n", ptbig1, ptbig2);

	system("pause");
	return 0;
}



