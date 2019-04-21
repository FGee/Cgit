#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define USR_NAME_LEN 20
#define USR_PWD_LEN 20
#define USR_ROLE int
#define POINT_ARRAY_SIZE 500
#define USR_ACCOUNT_NUM int
#define SYSTEM_MENU_TYPE char
#define USR_INFOR_NUM int


typedef struct usr_account_tag
{
	char usr_name[USR_NAME_LEN];
	char usr_pwd[USR_PWD_LEN];
	USR_ROLE  usr_role;
	struct usr_account_tag *pNext_Usr_Account;
}USR_ACCOUNT, *pUSR_ACCOUNT;

typedef struct usr_infor_tag
{
	int usr_id;
	char usr_name[USR_NAME_LEN];
	char sex;
	float chinese_score;
	float math_score;
	float english_score;
	struct usr_infor_tag *pNext_Usr_Infor;
}USR_INFOR, *pUSR_INFOR;

//系统初始化函数。初始化内存中的学生信息链表和账号列表
void system_init(const char* config_file_name, pUSR_ACCOUNT  *pUsr_Acount, pUSR_INFOR *pUsr_Infor);

void headInsert_account(pUSR_ACCOUNT *ppUsr_Acount_head, pUSR_ACCOUNT ptmp_usr_acount);

void headInsert_infor(pUSR_INFOR *ppUsr_Infor_head, pUSR_INFOR ptmp_usr_infor);

//登陆界面及键入账户密码，交至role_confirm函数
void print_login();

//根据输入的用户名和密码检查是否合法并确认当前账号的权限（管理员或普通用户）
USR_ROLE role_confirm(pUSR_ACCOUNT pUsr_Account, pUSR_ACCOUNT pUsr_Account_List);

//根据当前账号输入的账号名查询相应的账号信息。
pUSR_ACCOUNT search_usr_account(pUSR_ACCOUNT pUsr_Account_List, char* search_name);

void print_Acount(pUSR_ACCOUNT pUsr_Acount_head, FILE *fp);

void print_Infor(pUSR_INFOR pUsr_Infor_head, FILE *fp);

//将学生信息和账号信息保存到文件里去
void save_data_to_file(char * config_file_name, pUSR_ACCOUNT pUsr_Account_List, pUSR_INFOR pUsr_Infor_List);

//显示系统菜单，返回当前用户所选择的菜单
SYSTEM_MENU_TYPE show_system_menu(USR_ROLE role);

//当前用户选择查询功能时根据权限显示具有不同功能的查询功能的菜单
SYSTEM_MENU_TYPE show_info_search_menu(USR_ROLE role);

void search_all_sort(pUSR_INFOR pUsr_Infor_List);

int compare(const void *pleft, const void *pright);

void print_Infor_by_point(pUSR_INFOR *ppUsr_Infor_head, size_t num, FILE *fp);

//根据当前用户所输的姓名查询相应的学生信息
pUSR_INFOR search_usr_infor_by_name(pUSR_INFOR pUsr_Infor_List, char* search_name);

//根据当前用户所输的学号查询相应的学生信息
pUSR_INFOR search_usr_infor_by_id(pUSR_INFOR pUsr_Infor_List, USR_INFOR_NUM search_id);

//删除学生的信息， 是返回所删除的学生的下一个学生的指针
pUSR_INFOR delete_usr_infor(pUSR_INFOR *ppUsr_Infor_List, USR_INFOR_NUM id);

SYSTEM_MENU_TYPE show_account_search_menu();

//删除账号信息，返回指向下一个账号的指针
pUSR_ACCOUNT delete_usr_account(pUSR_ACCOUNT *ppUsr_Account_List, pUSR_ACCOUNT pUsr_account);






