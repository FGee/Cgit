#include "sims.h"

void system_init(const char* config_file_name, pUSR_ACCOUNT  *ppUsr_Acount_head, pUSR_INFOR *ppUsr_Infor_head)
{
	FILE *fp_config;
	FILE *fp_usr_account;
	FILE *fp_usr_infor;
	char usr_account[30];
	char usr_infor[30];
	int ret;
	fp_config = fopen(config_file_name, "r");
	if (NULL == fp_config) {
		perror("fopen");
		return -2;
	}
	ret = fscanf(fp_config, "%s\n%s\n", usr_account, usr_infor);

	fp_usr_account = fopen(usr_account, "r");
	if (NULL == fp_usr_account) {
		perror("fopen");
		return -3;
	}
	USR_ACCOUNT tmp_usr_account;
	while ((ret = fscanf(fp_usr_account, "%s\t%s\t%d\n", tmp_usr_account.usr_name, tmp_usr_account.usr_pwd,
		&tmp_usr_account.usr_role)) != EOF) {
		headInsert_account(ppUsr_Acount_head, &tmp_usr_account);
	}

	fp_usr_infor = fopen(usr_infor, "r");
	if (NULL == fp_usr_infor) {
		perror("fopen");
		return -4;
	}
	USR_INFOR tmp_usr_infor;
	while ((ret = fscanf(fp_usr_infor, "%d\t%s\t%c\t%f\t%f\t%f\n", &tmp_usr_infor.usr_id, tmp_usr_infor.usr_name,
		&tmp_usr_infor.sex, &tmp_usr_infor.chinese_score, &tmp_usr_infor.math_score, &tmp_usr_infor.english_score)) != EOF) {
		headInsert_infor(ppUsr_Infor_head, &tmp_usr_infor);
	}

	fclose(fp_usr_account);
	fclose(fp_usr_infor);
	fclose(fp_config);
}

void headInsert_account(pUSR_ACCOUNT *ppUsr_Acount_head, pUSR_ACCOUNT ptmp_usr_acount)
{
	pUSR_ACCOUNT pnew;
	pnew = (pUSR_ACCOUNT)calloc(1, sizeof(USR_ACCOUNT));
	strcpy(pnew->usr_name, ptmp_usr_acount->usr_name);
	strcpy(pnew->usr_pwd, ptmp_usr_acount->usr_pwd);
	pnew->usr_role = ptmp_usr_acount->usr_role;

	if (NULL == *ppUsr_Acount_head) {
		*ppUsr_Acount_head = pnew;
	}
	else {
		pnew->pNext_Usr_Account = *ppUsr_Acount_head;
		*ppUsr_Acount_head = pnew;
	}
}

void headInsert_infor(pUSR_INFOR *ppUsr_Infor_head, pUSR_INFOR ptmp_usr_infor)
{
	pUSR_INFOR pnew;
	pnew = (pUSR_INFOR)calloc(1, sizeof(USR_INFOR));
	pnew->usr_id = ptmp_usr_infor->usr_id;
	strcpy(pnew->usr_name, ptmp_usr_infor->usr_name);
	pnew->sex = ptmp_usr_infor->sex;
	pnew->chinese_score = ptmp_usr_infor->chinese_score;
	pnew->math_score = ptmp_usr_infor->math_score;
	pnew->english_score = ptmp_usr_infor->english_score;

	if (NULL == *ppUsr_Infor_head) {
		*ppUsr_Infor_head = pnew;
	}
	else {
		pnew->pNext_Usr_Infor = *ppUsr_Infor_head;
		*ppUsr_Infor_head = pnew;
	}
}

void print_login(pUSR_ACCOUNT pUsr_account)
{
	memset(pUsr_account, 0, sizeof(USR_ACCOUNT));//清零初始化，防止回退回来的时候，读取未定义的信息
	char ch;
	int i = 0;
again:
	system("cls");
	printf("Enter user_name: ");
	gets(pUsr_account->usr_name);
	if ('\0' == pUsr_account->usr_name[0]) {
		goto again;
	}
	system("cls");
	printf("Enter usr_password: ");
	while (ch = getch()) {
		if (ch == '\r') {
			if (i != 0) {
				pUsr_account->usr_pwd[i] = '\0';
				break;
			}
		}
		else if (ch == '\b') {
			if (i != 0) {
				printf("\b \b");
				--i;
			}
		}
		else {
			printf("*");
			pUsr_account->usr_pwd[i] = ch;
			++i;
		}
	}
	system("cls");
}

USR_ROLE role_confirm(pUSR_ACCOUNT pUsr_Account, pUSR_ACCOUNT pUsr_Account_List)
{
	pUSR_ACCOUNT pReturn_Usr_Account = NULL;//必须初始化，作为是否找到的判定条件
	pReturn_Usr_Account = search_usr_account(pUsr_Account_List, pUsr_Account->usr_name);
	system("cls");
	if (NULL == pReturn_Usr_Account) {
		printf("THE ACCOUT IS'T EXISTED!!!\n");
		system("pause");
		return -1;//账户不存在，返回错误判定值-1至main函数
	}
	else {
		if (0 != strcmp(pReturn_Usr_Account->usr_pwd, pUsr_Account->usr_pwd)) {
			printf("THE KEYWORD IS FALSE!!!\n");
			system("pause");
			return -1;//由于密码问题，返回错误判定值-1至main函数
		}
		else {
			printf("LOGIN SUCCESS!!!\n");
			return pReturn_Usr_Account->usr_role;
		}
	}
}

pUSR_ACCOUNT search_usr_account(pUSR_ACCOUNT pUsr_Account_List, char* search_name)
{
	if (NULL == pUsr_Account_List) {
		return NULL;
	}
	else {
		while (NULL != pUsr_Account_List) {
			if (0 == strcmp(search_name, pUsr_Account_List->usr_name)) {
				return pUsr_Account_List;
			}
			else {
				pUsr_Account_List = pUsr_Account_List->pNext_Usr_Account;
			}
		}
	}
	if (NULL == pUsr_Account_List) {
		return NULL;
	}
}

void print_Acount(pUSR_ACCOUNT pUsr_Acount_head, FILE *fp)
{
	int ret;
	if (NULL == pUsr_Acount_head) {
		fprintf(fp, "It's empty.\n");
	}
	else {
		while (NULL != pUsr_Acount_head) {
			ret = fprintf(fp, "%s\t%s\t%d\n", pUsr_Acount_head->usr_name, 
				pUsr_Acount_head->usr_pwd, pUsr_Acount_head->usr_role);
			pUsr_Acount_head = pUsr_Acount_head->pNext_Usr_Account;
		}
	}
}

void print_Infor(pUSR_INFOR pUsr_Infor_head, FILE *fp)
{
	int ret;
	if (NULL == pUsr_Infor_head) {
		fprintf(fp, "It's empty.\n");
	}
	else {
		while (NULL != pUsr_Infor_head) {
			ret = fprintf(fp, "%d\t%s\t%c\t%f\t%f\t%f\n", pUsr_Infor_head->usr_id, pUsr_Infor_head->usr_name, pUsr_Infor_head->sex, 
				pUsr_Infor_head->chinese_score, pUsr_Infor_head->math_score, pUsr_Infor_head->english_score);
			pUsr_Infor_head = pUsr_Infor_head->pNext_Usr_Infor;
		}
	}
}

void save_data_to_file(char * config_file_name, pUSR_ACCOUNT pUsr_Acount_head, pUSR_INFOR pUsr_Infor_head)
{
	FILE *fp_config;
	FILE *fp_usr_account;
	FILE *fp_usr_infor;
	char usr_account[30];
	char usr_infor[30];
	int ret;
	fp_config = fopen(config_file_name, "r");
	if (NULL == fp_config) {
		perror("fopen");
		return -2;
	}
	ret = fscanf(fp_config, "%s\n%s\n", usr_account, usr_infor);

	fp_usr_account = fopen(usr_account, "w+");
	if (NULL == fp_usr_account) {
		perror("fopen");
		return -3;
	}
	print_Acount(pUsr_Acount_head, fp_usr_account);

	fp_usr_infor = fopen(usr_infor, "w+");
	if (NULL == fp_usr_infor) {
		perror("fopen");
		return -4;
	}
	print_Infor(pUsr_Infor_head, fp_usr_infor);

	fclose(fp_usr_account);
	fclose(fp_usr_infor);
	fclose(fp_config);
}

SYSTEM_MENU_TYPE show_system_menu(USR_ROLE role)
{
	SYSTEM_MENU_TYPE system_menu_type = 'd';
	system("cls");
	printf("*************************Student Information Management System***********************************\n");
	for (int i = 0; i < 3; ++i) {
		printf("                                                                                                 \n");
	}
	if (1 == role) {
		printf("                          1. search sturdent information                                         \n");
		printf("                          2. add student information                                             \n");
		printf("                          3. update student information                                          \n");
		printf("                          4. delete student information                                          \n");
		printf("                          5. search user account                                                 \n");
		printf("                          6. add user account                                                    \n");
		printf("                          7. update user account                                                 \n");
		printf("                          8. delete user account                                                 \n");
	}
	else {
		printf("                          1. search sturdent information                                         \n");
	}
	printf("                          e. exit login                                                          \n");
	for (int i = 0; i < 6; ++i) {
		printf("                                                                                                 \n");
	Input_agagin:
		printf("Please input your select: ");
		scanf("%c", &system_menu_type);
		while (getchar() != '\n');//清空输入缓冲区
		switch (system_menu_type) {
		case '1': case '2': case '3': case'4': case '5': case '6': case '7': case '8': case '9': case 'e':
			return system_menu_type;
		default:
			printf("                       THE INPUT INVALID!!!                                                      \n");
			goto Input_agagin;
		}
	}
}

SYSTEM_MENU_TYPE show_info_search_menu(USR_ROLE role)
{
	SYSTEM_MENU_TYPE system_menu_type = 'd';
	system("cls");
	if (1 == role) {
		printf("0. search all\n");
	}
	printf("1. search by name\n");
	printf("2. search by id\n");
	printf("e. return\n");
	for (int i = 0; i < 3; ++i) {
		printf("                                                                                                 \n");
	}
Input_agagin:
	printf("Please input your select: ");
	scanf("%c", &system_menu_type);
	while (getchar() != '\n');//清空输入缓冲区
	switch (system_menu_type) {
	case '0': case '1': case '2': case 'e':
		return system_menu_type;
	default:
		printf("                       THE INPUT INVALID!!!                                                      \n");
		goto Input_agagin;
	}
}

int compare(const void *pleft, const void *pright)
{
	USR_INFOR pl = **(pUSR_INFOR*)pleft;
	USR_INFOR pr = **(pUSR_INFOR*)pright;
	if (pl.usr_id > pr.usr_id) {
		return 1;
	}
	if (pl.usr_id < pr.usr_id) {
		return -1;
	}
	if (pl.usr_id == pr.usr_id) {
		return 0;
	}
}

void search_all_sort(pUSR_INFOR pUsr_Infor_List)
{
	size_t num = 0;
	pUSR_INFOR *ppUsr_Infor_head;
	//pUSR_INFOR ppUsr_Infor_head[POINT_ARRAY_SIZE];
	ppUsr_Infor_head = (pUSR_INFOR*)calloc(POINT_ARRAY_SIZE, sizeof(pUSR_INFOR));

	while (NULL != pUsr_Infor_List) {
		ppUsr_Infor_head[num] = pUsr_Infor_List;//不够用可以使用relloc再增加空间
		pUsr_Infor_List = pUsr_Infor_List->pNext_Usr_Infor;
		++num;
	}
	qsort(ppUsr_Infor_head, num, sizeof(pUSR_INFOR), compare);
	//void qsort(void *buf, size_t num, size_t size, int(*compare)(const void *, const void *));
	print_Infor_by_point(ppUsr_Infor_head, num, stdout);
}

void print_Infor_by_point(pUSR_INFOR *ppUsr_Infor_head, size_t num, FILE *fp)
{
	int ret;
	for (int i = 0; i < num; ++i) {
		ret = fprintf(fp, "%d\t%s\t%c\t%f\t%f\t%f\n", ppUsr_Infor_head[i]->usr_id, ppUsr_Infor_head[i]->usr_name, ppUsr_Infor_head[i]->sex,
			ppUsr_Infor_head[i]->chinese_score, ppUsr_Infor_head[i]->math_score, ppUsr_Infor_head[i]->english_score);
	}
}

pUSR_INFOR search_usr_infor_by_name(pUSR_INFOR pUsr_Infor_List, char* search_name)
{
	if (NULL == pUsr_Infor_List) {
		return NULL;
	}
	else {
		while (NULL != pUsr_Infor_List) {
			if (0 == strcmp(search_name, pUsr_Infor_List->usr_name)) {
				return pUsr_Infor_List;
			}
			else {
				pUsr_Infor_List = pUsr_Infor_List->pNext_Usr_Infor;
			}
		}
	}
	if (NULL == pUsr_Infor_List) {
		return NULL;
	}
}

pUSR_INFOR search_usr_infor_by_id(pUSR_INFOR pUsr_Infor_List, USR_INFOR_NUM search_id)
{
	if (NULL == pUsr_Infor_List) {
		return NULL;
	}
	else {
		while (NULL != pUsr_Infor_List) {
			if (search_id == pUsr_Infor_List->usr_id) {
				return pUsr_Infor_List;
			}
			else {
				pUsr_Infor_List = pUsr_Infor_List->pNext_Usr_Infor;
			}
		}
	}
	if (NULL == pUsr_Infor_List) {
		return NULL;
	}
}

pUSR_INFOR delete_usr_infor(pUSR_INFOR *ppUsr_Infor_List, pUSR_INFOR pUsr_infor)
{
	pUSR_INFOR ppre, pcur;
	ppre = pcur = *ppUsr_Infor_List;
	if (pUsr_infor == *ppUsr_Infor_List) {
		pcur = pcur->pNext_Usr_Infor;
		*ppUsr_Infor_List = pcur;
		free(ppre);
		return pcur;
	}
	else {
		while (pcur) {
			if (pUsr_infor == pcur) {
				ppre->pNext_Usr_Infor = pcur->pNext_Usr_Infor;
				free(pcur);
				return pcur->pNext_Usr_Infor;
				break;
			}
			else {
				ppre = pcur;
				pcur = pcur->pNext_Usr_Infor;
			}
		}
	}
}

SYSTEM_MENU_TYPE show_account_search_menu()
{
	SYSTEM_MENU_TYPE system_menu_type = 'd';
	system("cls");
	printf("0. search all\n");
	printf("1. search by name\n");
	printf("e. return\n");
	for (int i = 0; i < 3; ++i) {
		printf("                                                                                                 \n");
	}
Input_agagin:
	printf("Please input your select: ");
	scanf("%c", &system_menu_type);
	while (getchar() != '\n');//清空输入缓冲区
	switch (system_menu_type) {
	case '0': case '1': case 'e':
		return system_menu_type;
	default:
		printf("                       THE INPUT INVALID!!!                                                      \n");
		goto Input_agagin;
	}
}

pUSR_ACCOUNT delete_usr_account(pUSR_ACCOUNT *ppUsr_Account_List, pUSR_ACCOUNT pUsr_account)
{
	pUSR_ACCOUNT ppre, pcur;
	ppre = pcur = *ppUsr_Account_List;
	if (pUsr_account == *ppUsr_Account_List) {
		pcur = pcur->pNext_Usr_Account;
		*ppUsr_Account_List = pcur;
		free(ppre);
		return pcur;
	}
	else {
		while (pcur) {
			if (pUsr_account == pcur) {
				ppre->pNext_Usr_Account = pcur->pNext_Usr_Account;
				free(pcur);
				return pcur->pNext_Usr_Account;
				break;
			}
			else {
				ppre = pcur;
				pcur = pcur->pNext_Usr_Account;
			}
		}
	}
}









