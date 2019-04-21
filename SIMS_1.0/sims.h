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

//ϵͳ��ʼ����������ʼ���ڴ��е�ѧ����Ϣ������˺��б�
void system_init(const char* config_file_name, pUSR_ACCOUNT  *pUsr_Acount, pUSR_INFOR *pUsr_Infor);

void headInsert_account(pUSR_ACCOUNT *ppUsr_Acount_head, pUSR_ACCOUNT ptmp_usr_acount);

void headInsert_infor(pUSR_INFOR *ppUsr_Infor_head, pUSR_INFOR ptmp_usr_infor);

//��½���漰�����˻����룬����role_confirm����
void print_login();

//����������û������������Ƿ�Ϸ���ȷ�ϵ�ǰ�˺ŵ�Ȩ�ޣ�����Ա����ͨ�û���
USR_ROLE role_confirm(pUSR_ACCOUNT pUsr_Account, pUSR_ACCOUNT pUsr_Account_List);

//���ݵ�ǰ�˺�������˺�����ѯ��Ӧ���˺���Ϣ��
pUSR_ACCOUNT search_usr_account(pUSR_ACCOUNT pUsr_Account_List, char* search_name);

void print_Acount(pUSR_ACCOUNT pUsr_Acount_head, FILE *fp);

void print_Infor(pUSR_INFOR pUsr_Infor_head, FILE *fp);

//��ѧ����Ϣ���˺���Ϣ���浽�ļ���ȥ
void save_data_to_file(char * config_file_name, pUSR_ACCOUNT pUsr_Account_List, pUSR_INFOR pUsr_Infor_List);

//��ʾϵͳ�˵������ص�ǰ�û���ѡ��Ĳ˵�
SYSTEM_MENU_TYPE show_system_menu(USR_ROLE role);

//��ǰ�û�ѡ���ѯ����ʱ����Ȩ����ʾ���в�ͬ���ܵĲ�ѯ���ܵĲ˵�
SYSTEM_MENU_TYPE show_info_search_menu(USR_ROLE role);

void search_all_sort(pUSR_INFOR pUsr_Infor_List);

int compare(const void *pleft, const void *pright);

void print_Infor_by_point(pUSR_INFOR *ppUsr_Infor_head, size_t num, FILE *fp);

//���ݵ�ǰ�û������������ѯ��Ӧ��ѧ����Ϣ
pUSR_INFOR search_usr_infor_by_name(pUSR_INFOR pUsr_Infor_List, char* search_name);

//���ݵ�ǰ�û������ѧ�Ų�ѯ��Ӧ��ѧ����Ϣ
pUSR_INFOR search_usr_infor_by_id(pUSR_INFOR pUsr_Infor_List, USR_INFOR_NUM search_id);

//ɾ��ѧ������Ϣ�� �Ƿ�����ɾ����ѧ������һ��ѧ����ָ��
pUSR_INFOR delete_usr_infor(pUSR_INFOR *ppUsr_Infor_List, USR_INFOR_NUM id);

SYSTEM_MENU_TYPE show_account_search_menu();

//ɾ���˺���Ϣ������ָ����һ���˺ŵ�ָ��
pUSR_ACCOUNT delete_usr_account(pUSR_ACCOUNT *ppUsr_Account_List, pUSR_ACCOUNT pUsr_account);






