#include "sims.h"	

int main(int argc, char** argv)
{
	int ret;
	if (argc != 2) {
		printf("argc error.\n");
		system("pause");
		return -1;
	}
	//-----------------------------预处理模块------------------------------
	pUSR_ACCOUNT pUsr_Account_List_head = NULL; 
	pUSR_INFOR pUsr_Infor_List_head = NULL; 
	system_init(argv[1], &pUsr_Account_List_head, &pUsr_Infor_List_head);
	//------------------------------登陆模块-------------------------------
	//print_Infor(pUsr_Infor_List_head, stdout);
	//print_Acount(pUsr_Account_List_head, stdout);
	USR_ROLE usr_role;
	USR_ACCOUNT usr_account_login;
Login_Interface:
	print_login(&usr_account_login);
	usr_role = role_confirm(&usr_account_login, pUsr_Account_List_head);
	if (-1 == usr_role) {//用户不存在，或者密码错误退出程序
		return 0;
	}
	//-------------------------系统功能菜单显示模块-------------------------
	SYSTEM_MENU_TYPE system_menu_type;
system_menu:
	system_menu_type = show_system_menu(usr_role);
	//---------------------------功能选择分支模块-----------------------------
	if ('e' == system_menu_type) {//返回上级
		goto Login_Interface;
	}
	//----------------------------学生信息查询-------------------------------
	if ('1' == system_menu_type) {
	search_info_menu:
		system_menu_type = show_info_search_menu(usr_role);
		if ('e' == system_menu_type) {//exit
			goto system_menu;
		}
		if ('0' == system_menu_type) {//show all student information
			system("cls");
			search_all_sort(pUsr_Infor_List_head);
			system("pause");
			goto search_info_menu;
		}
		if ('1' == system_menu_type) {//search by name
			pUSR_INFOR pUsr_infor;
			char name[USR_NAME_LEN];
			system("cls");
			printf("Enter user_name: ");
			gets(name);
			//while (getchar() != '\n'); 不能使用， getchar()函数从STDIN(标准输入)获取并返回下一个字符,如果到达文件尾返回EOF. 
			pUsr_infor = search_usr_infor_by_name(pUsr_Infor_List_head, name);
			if (NULL == pUsr_infor) {
				printf("NO EXIT!!! Please input again.\n");
			}
			else {
				printf("%d\t%s\t%c\t%f\t%f\t%f\n", pUsr_infor->usr_id, pUsr_infor->usr_name, pUsr_infor->sex,
					pUsr_infor->chinese_score, pUsr_infor->math_score, pUsr_infor->english_score);
			}
			system("pause");
			goto search_info_menu;
		}
		if ('2' == system_menu_type) {//search by id
			pUSR_INFOR pUsr_infor;
			USR_INFOR_NUM id = 0;
			system("cls");
			printf("Please input the id that you want to search: ");
			ret = scanf("%d", &id);
			while (getchar() != '\n');//清空输入缓冲区
			pUsr_infor = search_usr_infor_by_id(pUsr_Infor_List_head, id);
			if (NULL == pUsr_infor) {
				printf("NO EXIT!!! Please input again.\n");
			}
			else {
				printf("%d\t%s\t%c\t%f\t%f\t%f\n", pUsr_infor->usr_id, pUsr_infor->usr_name, pUsr_infor->sex,
					pUsr_infor->chinese_score, pUsr_infor->math_score, pUsr_infor->english_score);
			}
			system("pause");
			goto search_info_menu;
		}
	}
	//----------------------------学生信息增加-----------------------------------
	if ('2' == system_menu_type) {
		USR_INFOR Usr_infor;
		pUSR_INFOR pUsr_infor;
	add_info_menu:
		system("cls");
		printf("Please input the information you want to add: \n");
		printf("id name sex chinese math english\n");
		ret = scanf("%d %s %c %f %f %f", &Usr_infor.usr_id, Usr_infor.usr_name,
			&Usr_infor.sex, &Usr_infor.chinese_score, &Usr_infor.math_score,
			&Usr_infor.english_score);
		if (ret != 6) {
			printf("INPUT ERROR!!!");
			goto
				add_info_menu;
		}
		pUsr_infor = search_usr_infor_by_name(pUsr_Infor_List_head, &Usr_infor.usr_name);
		if (NULL != pUsr_infor) {
			printf("ID EXISIT!!! Please input again.\n");
		}
		else {
			headInsert_infor(&pUsr_Infor_List_head, &Usr_infor);
			save_data_to_file(argv[1], pUsr_Account_List_head, pUsr_Infor_List_head);//文件保存
			pUsr_Account_List_head = NULL;
			pUsr_Infor_List_head = NULL;
			system_init(argv[1], &pUsr_Account_List_head, &pUsr_Infor_List_head);//文件重新读取至内存
			printf("ADD SUCCESS!\n");
		}
		system("pause");
		goto system_menu;
	}
	//----------------------------学生信息更改------------------------------------
	if ('3' == system_menu_type) {
		pUSR_INFOR pUsr_infor;
		USR_INFOR_NUM id = 0;
	update_info_menu:
		system("cls"); 
		printf("Please input the id you want to update: \n");
		ret = scanf("%d", &id);
		while (getchar() != '\n');//清空输入缓冲区
		pUsr_infor = search_usr_infor_by_id(pUsr_Infor_List_head, id);
		if (NULL == pUsr_infor) {
			printf("NO EXIT!!! Please input again.\n");
			goto update_info_menu;
		}
		else {
			printf("name sex chinese math english\n");
			ret = scanf("%s %c %f %f %f", pUsr_infor->usr_name,
				&pUsr_infor->sex, &pUsr_infor->chinese_score, &pUsr_infor->math_score,
				&pUsr_infor->english_score);
			if (ret != 5) {
				printf("INPUT ERROR!!!");
				goto update_info_menu;
			}
			else {
				printf("UPDATE SUCCESS!\n");
				printf("%d\t%s\t%c\t%f\t%f\t%f\n", pUsr_infor->usr_id, pUsr_infor->usr_name, pUsr_infor->sex,
					pUsr_infor->chinese_score, pUsr_infor->math_score, pUsr_infor->english_score);
				save_data_to_file(argv[1], pUsr_Account_List_head, pUsr_Infor_List_head);//文件保存
				pUsr_Account_List_head = NULL;
				pUsr_Infor_List_head = NULL;
				system_init(argv[1], &pUsr_Account_List_head, &pUsr_Infor_List_head);//文件重新读取至内存
			}
		}
		system("pause");
		goto system_menu;
	}
	//----------------------------学生信息删除------------------------------------
	if ('4' == system_menu_type) {
		pUSR_INFOR pUsr_infor;
		USR_INFOR_NUM id = 0;
	delete_info_menu:
		system("cls");
		printf("Please input the id you want to delete: \n");
		ret = scanf("%d", &id);
		while (getchar() != '\n');//清空输入缓冲区
		pUsr_infor = search_usr_infor_by_id(pUsr_Infor_List_head, id);
		if (NULL == pUsr_infor) {
			printf("NO EXIT!!! Please input again.\n");
			goto delete_info_menu;
		}
		else {
			delete_usr_infor(&pUsr_Infor_List_head, pUsr_infor);
			save_data_to_file(argv[1], pUsr_Account_List_head, pUsr_Infor_List_head);//文件保存
			pUsr_Account_List_head = NULL;
			pUsr_Infor_List_head = NULL;
			system_init(argv[1], &pUsr_Account_List_head, &pUsr_Infor_List_head);//文件重新读取至内存
			printf("DELETE SUCCESS!\n");
		}
		system("pause");
		goto system_menu;
	}
	//---------------------------------查询账号信息------------------------------------------
	if ('5' == system_menu_type) {
	account_search_menu:
		system_menu_type = show_account_search_menu();
		if ('e' == system_menu_type) {//exit
			goto system_menu;
		}
		if ('0' == system_menu_type) {//show all account information
			system("cls"); 
			print_Acount(pUsr_Account_List_head, stdout);
			system("pause");
			goto account_search_menu;
		}
		if ('1' == system_menu_type) {//search by name
			pUSR_ACCOUNT pUsr_account;
			char name[USR_NAME_LEN];
			system("cls");
			printf("Enter user_name: ");
			gets(name);
			//while (getchar() != '\n'); 不能使用， getchar()函数从STDIN(标准输入)获取并返回下一个字符,如果到达文件尾返回EOF. 
			pUsr_account = search_usr_account(pUsr_Account_List_head, name);
			if (NULL == pUsr_account) {
				printf("NO EXIT!!! Please input again.\n");
			}
			else {
				printf("%s\t%s\t%d\n", pUsr_account->usr_name, pUsr_account->usr_pwd, pUsr_account->usr_role);
			}
			system("pause");
			goto account_search_menu;
		}
	}
	//----------------------------------增加账户信息-----------------------------
	if ('6' == system_menu_type) {
		USR_ACCOUNT Usr_accout;
		pUSR_ACCOUNT pUsr_accout;
	add_account_menu:
		system("cls");
		printf("Please input the account you want to add: \n");
		printf("name password role\n");
		ret = scanf("%s %s %d", &Usr_accout.usr_name,
			&Usr_accout.usr_pwd, &Usr_accout.usr_role);
		if (ret != 3) {
			printf("INPUT ERROR!!!");
			system("pause");
			goto add_account_menu;
		}
		pUsr_accout = search_usr_account(&pUsr_Account_List_head, &Usr_accout.usr_name);
		if (NULL != pUsr_accout) {
			printf("ACCOUNT EXISIT!!! Please input again.\n");
			system("pause");
			goto add_account_menu;
		}
		else {
			headInsert_account(&pUsr_Account_List_head, &Usr_accout);
			save_data_to_file(argv[1], pUsr_Account_List_head, pUsr_Infor_List_head);//文件保存
			pUsr_Account_List_head = NULL;
			pUsr_Infor_List_head = NULL;
			system_init(argv[1], &pUsr_Account_List_head, &pUsr_Infor_List_head);//文件重新读取至内存
			printf("ADD SUCCESS!\n");
		}
		system("pause");
		goto system_menu;
	}
	//--------------------------------更改账户信息----------------------------------
	if ('7' == system_menu_type) {
		pUSR_ACCOUNT pUsr_accout;
		char name[USR_NAME_LEN];
	update_account_menu:
		system("cls");
		printf("Please input the account name you want to update: \n");
		gets(name);
		pUsr_accout = search_usr_account(pUsr_Account_List_head, name);
		if (NULL == pUsr_accout) {
			printf("NO EXIT!!! Please input again.\n");
			system("pause");
			goto update_account_menu;
		}
		else {
			printf("password role\n");
			ret = scanf("%s %d", pUsr_accout->usr_pwd,
				&pUsr_accout->usr_role);
			if (ret != 2) {
				printf("INPUT ERROR!!!");
				system("pause");
				goto update_account_menu;
			}
			else {
				printf("UPDATE SUCCESS!\n");
				printf("%s\t%s\t%d\n", pUsr_accout->usr_name, pUsr_accout->usr_pwd, pUsr_accout->usr_role);
				save_data_to_file(argv[1], pUsr_Account_List_head, pUsr_Infor_List_head);//文件保存
				pUsr_Account_List_head = NULL;
				pUsr_Infor_List_head = NULL;
				system_init(argv[1], &pUsr_Account_List_head, &pUsr_Infor_List_head);//文件重新读取至内存
			}
		}
		system("pause");
		goto system_menu;
	}
	//----------------------------------删除账户信息--------------------------------
	if ('8' == system_menu_type) {
		pUSR_ACCOUNT pUsr_accout;
		char name[USR_NAME_LEN];
	delete_account_menu:
		system("cls");
		printf("Please input the account name you want to delete: \n");
		gets(name);
		pUsr_accout = search_usr_account(pUsr_Account_List_head, name);
		if (NULL == pUsr_accout) {
			printf("NO EXIT!!! Please input again.\n");
			system("pause");
			goto delete_account_menu;
		}
		else {
			delete_usr_account(&pUsr_Account_List_head, pUsr_accout);
			save_data_to_file(argv[1], pUsr_Account_List_head, pUsr_Infor_List_head);//文件保存
			pUsr_Account_List_head = NULL;
			pUsr_Infor_List_head = NULL;
			system_init(argv[1], &pUsr_Account_List_head, &pUsr_Infor_List_head);//文件重新读取至内存
			printf("DELETE SUCCESS!\n");
		}
		system("pause");
		goto system_menu;
	}

	system("pause");
	return -2333333;
}