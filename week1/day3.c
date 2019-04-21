1.
//mystrcpy() mystrcmp() mystrcat() mystrlen()的实现
#include <stdio.h>		
#include <stdlib.h>
#define N 100

char* mystrcpy(char *ps1, const char *ps2)
{
	for (int i = 0; ps2[i] != '\0'; ++i) {
		ps1[i] = ps2[i];
		ps1[i + 1] = '\0';
	}
	return ps1;
}

int mystrcmp(const char *ps1, const char *ps2)
{
	for (int i = 0; ; ++i) {
		if (ps1[i] == '\0' || ps2[i] == '\0') {
			if (ps1[i] == '\0' && ps2[i] != '\0') {
				return -1;
			}
			else if (ps1[i] != '\0' && ps2[i] == '\0') {
				return 1;
			}
			else if (ps1[i - 1] == ps2[i - 1]) {
				return 0;
			}
			else if (ps1[i - 1] < ps2[i - 1]) {
				return -1;
			}
			else if (ps1[i - 1] > ps2[i - 1]) {
				return 1;
			}
		}
	}
}

char* mystrcat(char *ps1, const char *ps2)
{
	for (int i = 0; ; ++i) {
		if (ps1[i] == '\0') {
			for (int j = 0; ; ++j, ++i) {
				if (ps2[j] != '\0') {
					ps1[i] = ps2[j];
				}
				else {
					ps1[i] = '\0';
					return ps1;
				}
			}
		}
	}
	return ps1;
}

int mystrlen(const char *ps)
{
	for (int i = 0; ; ++i) {
		if (ps[i] == '\0') {
			return i;
		}
	}
}

int main()
{
	char str1[N]; char str2[N];
	int i = 0;
	while (scanf_s("%c", &str1[i++], sizeof(str1[i]))) {
		if (str1[i - 1] == '\n') {
			str1[i - 1] = '\0';
			break;
		}
	}
	/*int j = 0;
	while (scanf_s("%c", &str2[j++], sizeof(str2[j]))) {
		if (str2[j - 1] == '\n') {
			str2[j - 1] = '\0';
			break;
		}
	}*/
	//mystrcpy(str1, str2);
	//printf("%s\n%s\n", str1, str2);
	//printf("%d\n", mystrcmp(str1, str2));
	//printf("%s\n", mystrcat(str1, str2));
	printf("%d\n", mystrlen(str1));

	system("pause");
	return 0;
}



2.
#include <stdio.h>		
#include <stdlib.h>
#define N 100
#define true 1
#define false 0
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

int main()
{
	char str[N];
	int i = 0;
	while (scanf_s("%c", &str[i++], sizeof(str[i]))) {
		if (str[i - 1] == '\n') {
			str[i - 1] = '\0';
			break;
		}
	}
	printf("%d\n", wrdnum_of_str(str));

	system("pause");
	return 0;
}




3.
//mystrcpy() mystrcmp() mystrcat() mystrlen()的实现
#include <stdio.h>		
#include <stdlib.h>
#define N 100
#define true 1
#define false 0

void print_wrd_str(const char *ps)
{
	int wrd_cnt = 0;
	int pre_is_space = true;
	for (int i = 0; ps[i] != '\0'; ++i) {
		if (pre_is_space && ps[i] != ' ') {
			pre_is_space = false;
			printf("%c", ps[i]);
		}
		else if (!pre_is_space && ps[i] == ' ')
		{
			printf("\n");
			pre_is_space = true;
		}
		else if (ps[i] != ' ') {
			printf("%c", ps[i]);
		}
	}
}

int main()
{
	char str[N];
	int i = 0;
	while (scanf_s("%c", &str[i++], sizeof(str[i]))) {
		if (str[i - 1] == '\n') {
			str[i - 1] = '\0';
			break;
		}
	}
	print_wrd_str(str);

	system("pause");
	return 0;
}



4.
#include <stdio.h>		
#include <stdlib.h>
#define N 100
#define true 1
#define false 0

char* mystrcpy(char *ps1, const char *ps2)
{
	for (int i = 0; ps2[i] != '\0'; ++i) {
		ps1[i] = ps2[i];
		ps1[i + 1] = '\0';
	}
	return ps1;
}

int mystrlen(const char *ps)
{
	for (int i = 0; ; ++i) {
		if (ps[i] == '\0') {
			return i;
		}
	}
}

void evert(char *ps)
{
	char tmp_s[N], *tps = tmp_s;
	mystrcpy(tmp_s, ps);
	int len = mystrlen(tmp_s);
	for (int i = 0; len > 0; ++i, --len) {
		ps[i] = tmp_s[len - 1];
	}
}

int main()
{
	char str[N];
	int i = 0;
	while (scanf_s("%c", &str[i++], sizeof(str[i]))) {
		if (str[i - 1] == '\n') {
			str[i - 1] = '\0';
			break;
		}
	}
	evert(str);
	printf("%s\n", str);

	system("pause");
	return 0;
}



5.

//两个大整数相加
//方法不对，可以直接用字符数组处理
#include <stdio.h>		
#include <stdlib.h>
#include <math.h>
#define N 100
#define UNIT 8
#define true 1
#define false 0
int num1_t_p = true;//符号类型，默认为非负整数
int num2_t_p = true;
int add1 = 0;

char* mystrcpy(char *ps1, const char *ps2)
{
	for (int i = 0; ps2[i] != '\0'; ++i) {
		ps1[i] = ps2[i];
		ps1[i + 1] = '\0';
	}
	return ps1;
}

int mystrcmp(const char *ps1, const char *ps2)
{
	for (int i = 0; ; ++i) {
		if (ps1[i] == '\0' || ps2[i] == '\0') {
			if (ps1[i] == '\0' && ps2[i] != '\0') {
				return -1;
			}
			else if (ps1[i] != '\0' && ps2[i] == '\0') {
				return 1;
			}
			else if (ps1[i - 1] == ps2[i - 1]) {
				return 0;
			}
			else if (ps1[i - 1] < ps2[i - 1]) {
				return -1;
			}
			else if (ps1[i - 1] > ps2[i - 1]) {
				return 1;
			}
		}
	}
}

int mystrlen(const char *ps)
{
	for (int i = 0; ; ++i) {
		if (ps[i] == '\0') {
			return i;
		}
	}
}

//----------------------------------------------------
void evert(char *ps)
{
	char tmp_s[N], *tps = tmp_s;
	mystrcpy(tmp_s, ps);
	int len = mystrlen(tmp_s);
	for (int i = 0; len > 0; ++i, --len) {
		ps[i] = tmp_s[len - 1];
	}
}

void add_divide(char *pnm1, char *pnm2, char *ans)
{

}

void sum_to_unit_ans(char *ans, int cta, int sum) {
	sum += add1;
	if (sum < 0) {
		sum = (int)pow(10, UNIT) + sum;
		add1 = -1;
	}
	for (int i = 0; i < UNIT; ++i) {
		ans[cta + i] = sum % 10 + '0';
		sum = sum / 10;
	}
	if (sum == 1) {
		add1 = 1;
	}
	if (add1 != -1 && sum != 1) {
		add1 = 0;
	}
}

char* add_big_num(char *pnm1, char *pnm2, char *ans)
{
	if (!mystrcmp(pnm1, "0")) {
		return pnm2;
	}
	else if (!mystrcmp(pnm2, "0")) {
		return pnm1;
	}
	if (pnm1[0] == '-') {
		num1_t_p = false;
	}
	if (pnm2[0] == '-') {
		num2_t_p = false;
	}
	int ct1 = 1; int ct2 = 1; int cta = 1;
	while (pnm1[ct1] != '\0' || pnm2[ct2] != '\0') {
		int n1 = 0, n2 = 0;
		int sum = 0;
		for (int i = 0; i < UNIT; ++i) {
			if (pnm1[ct1] != '\0') {
				n1 += (pnm1[ct1] - '0') * (int)pow(10, i);
				++ct1;
			}
			if (pnm2[ct2] != '\0') {
				n2 += (pnm2[ct2] - '0') * (int)pow(10, i);
				++ct2;
			}
		}
		if (num1_t_p && num2_t_p) {
			sum = n1 + n2;
		}
		if (num1_t_p && !num2_t_p) {
			sum = n1 - n2;
		}
		if (!num1_t_p && num2_t_p) {
			sum = n1 - n2;
		}
		if (!num1_t_p && !num2_t_p) {
			sum = n1 + n2;
		}
		sum_to_unit_ans(ans, cta, sum);
		cta += 8;
		printf("sum:%d\n", sum);
	}
	if (add1 == -1) {
		ans[0] = '-';
	}
	else {
		ans[0] = '+';
	}
	ans[cta] = '\0';
	evert(ans + 1);
	return ans;
}

int main()
{
	char n1[N]; char n2[N]; char ans[N];
	int i = 0;
	while (scanf_s("%c", &n1[i++], sizeof(n1[i]))) {
		if (n1[i - 1] == '\n') {
			n1[i - 1] = '\0';
			break;
		}
	}
	i = 0;
	while (scanf_s("%c", &n2[i++], sizeof(n2[i]))) {
		if (n2[i - 1] == '\n') {
			n2[i - 1] = '\0';
			break;
		}
	}
	evert(n1 + 1);
	evert(n2 + 1);
	printf("%s\n", add_big_num(n1, n2, ans));

	system("pause");
	return 0;
}
