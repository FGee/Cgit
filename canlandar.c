//输出年历
#include <stdio.h>
#include <stdlib.h>
#define leaps (year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)
#define base_yr 1990
#define base_mn 1
#define base_dy 1
#define true 1
#define false 0

int day_of_year(int year, int month, int day)//日期转换为在这年对应的天数
{
	switch (month - 1) {
	case 11:
		day += 30;
	case 10:
		day += 31;
	case 9:
		day += 30;
	case 8:
		day += 31;
	case 7:
		day += 31;
	case 6:
		day += 30;
	case 5:
		day += 31;
	case 4:
		day += 30;
	case 3:
		day += 31;
	case 2:
		day += (leaps) ? 29 : 28;
		//printf("%d\n", leaps);
	case 1:
		day += 31;
	case 0:
		break;
	default:
		printf("error!\n");
	}
	return day;
}

int day_dif_year(int year, int year2)//两年之间的天数差
{
	int days = 0;
	for (; year < year2; ++year) {
		days += (leaps) ? 366 : 365;
	}
	return days;
}

int daytowk(int year, int month, int day)//日期对应的星期
{
	int diff = day_dif_year(base_yr, year)
		- day_of_year(base_yr, base_mn, base_dy)
		+ day_of_year(year, month, day);
	int week[7] = { 1,2,3,4,5,6,7 };
	return week[diff % 7];
}

int day_of_month(int year, int month)//一个月有几天
{
	int mnth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (leaps)
		mnth[1] = 29;
	return mnth[month - 1];
}

void prnt(int wk_of_fsrt)//打印一行的月份中1号之前的空白
{
	switch (wk_of_fsrt) {
	case 7:
		printf("    ");
		break;
	case 1: case 2: case 3: case 4: case 5: case 6:
		for (int i = 0; i <= wk_of_fsrt; ++i) {
			printf("    ");
		}
	}
}

void printline(int ln, int year)//输出一行的两个月份
{
	int lmonth = ln;
	int rmonth = ln + 6;
	printf("|%-2d  SUN MON TUE WED THU FRI SAT  ", lmonth);//第一行
	printf("%2d  SUN MON TUE WED THU FRI SAT |\n", rmonth);

	int lmondys = day_of_month(year, lmonth);
	int lwk_of_fsrt = daytowk(year, lmonth, 1);
	int rmondys = day_of_month(year, rmonth);
	int rwk_of_fsrt = daytowk(year, rmonth, 1);
	int ctl = 1; int ctr = 1;//对应月份天数的控制量
	int lenough = false; int renough = false;//对应循环的控制量
	int teml = false; int temr = false;//确保左右月份已经打印完

	while (!lenough || !renough) {
		printf("|");
		int ltab = 0;
		if (ctl == 1) {
			prnt(lwk_of_fsrt);

			ltab = lwk_of_fsrt % 7;
		}
		else if (ctl != 1)
		{
			printf("    ");
		}
		for (; ctl <= lmondys; ++ctl, ++ltab) {
			printf("%3d ", ctl);
			if (ctl == lmondys) {
				lenough = true;
				teml = true;
				++ctl;
				++ltab;
				break;
			}
			if (ctl != lmondys && ltab == 6) {
				//++ltab;
				++ctl;
				break;
			}
		}

		if (lenough && !renough) {
			if (teml) {//在左边天数已经全部打印出来的且右边还没打印完的情况下
				for (; ltab <= 6; ++ltab)
					printf("    ");
			}
		}
		if (!lenough && renough) {
			for (; ltab <= 6; ++ltab)
				printf("    ");
		}
		if (lenough && renough) {
			for (; ltab <= 6; ++ltab)
				printf("    ");
		}

		printf(" ");

		int rtab = 0;
		if (ctr == 1) {
			prnt(rwk_of_fsrt);

			rtab = rwk_of_fsrt % 7;
		}
		else if (ctr != 1)
		{
			printf("    ");
		}
		for (; ctr <= rmondys; ++ctr, ++rtab) {
			printf("%3d ", ctr);
			if (ctr == rmondys) {
				renough = true;
				temr = true;
				++ctr;
				++rtab;
				break;
			}
			if (ctr != rmondys && rtab == 6) {
				//++rtab;
				++ctr;
				break;
			}
		}

		if (lenough && !renough) {
			if (temr) {
				for (; rtab <= 6; ++rtab)
					printf("    ");
			}
		}
		if (!lenough && renough) {
			for (; rtab <= 6; ++rtab)
				printf("    ");
		}
		if (lenough && renough) {
			for (; rtab <= 6; ++rtab)
				printf("    ");
		}
		printf("|");
		printf("\n");
	}
}

void printyear(int year)
{
	//printline(4, year);
	printf("|------------------The Calendar of Year %4d ---------------------|\n", year);
	for (int line = 1; line <= 6; ++line) {
		printline(line, year);
	}
	printf("|-----------------------------------------------------------------|\n", year);
}

int main()
{
	int yr;
	printf("Please input the year whose calendar you want to know: ");
	while (scanf_s("%d", &yr)) {
		printyear(yr);
		rewind(stdin);
		printf("Please input the year whose calendar you want to know: ");
	}

	system("pause");
	return 0;
}




