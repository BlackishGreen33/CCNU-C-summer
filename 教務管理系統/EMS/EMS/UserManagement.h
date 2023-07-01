#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataFormat.h" // 調用教務管理系統數據格式頭文件
#include "DataStorage.h" // 調用用戶數據頭文件

// 用戶管理菜單選項
enum UserManagementOption {
	USER_MANAGEMENT_QUERY_ALL_USERS = 1,
	USER_MANAGEMENT_ADD_USER,
	USER_MANAGEMENT_MODIFY_USER,
	USER_MANAGEMENT_DELETE_USER,
	USER_MANAGEMENT_RETURN
};

// 用戶管理菜單
void user_management_menu() {
	system("cls");
	printf("============用戶管理============\n");
	printf("\t1. 查詢所有用戶信息\n");
	printf("\t2. 新增用戶\n");
	printf("\t3. 修改用戶信息\n");
	printf("\t4. 刪除用戶\n");
	printf("\t5. 返回\n");
	printf("\t請選擇操作：");
}

// 查詢所有用戶信息
void query_all_users() {
	printf("\n所有用戶信息如下：\n");
	printf("用戶ID\t用戶名\t\t角色\n");
	printf("================================\n");
	for (int i = 0; i < user_count; i++) {
		printf("%s\t%s\t", users[i].user_id, users[i].username);
		switch (users[i].role) {
		case 1:
			printf("\t管理員\n");
			break;
		case 2:
			printf("教師\n");
			break;
		case 3:
			printf("學生\n");
			break;
		default:
			printf("未知角色\n");
			break;
		}
	}
}

// 新增用戶
void add_user() {
	User user;
	printf("\n請輸入新用戶信息：\n");
	printf("用戶ID：");
	scanf("%s", user.user_id);
	printf("用戶名：");
	scanf("%s", user.username);
	printf("密碼：");
	scanf("%s", user.password);
	printf("用戶角色（1.管理員，2.教師，3.學生）：");
	scanf("%d", &user.role);
	users[user_count++] = user;
	printf("添加成功！\n");
}

// 修改用戶信息
void modify_user() {
	char user_id[20];
	printf("\n請輸入要修改的用戶ID：");
	scanf("%s", user_id);
	int index = -1;
	for (int i = 0; i < user_count; i++) {
		if (strcmp(users[i].user_id, user_id) == 0) {
			index = i;
			break;
		}
	}
	if (index == -1) {
		printf("未找到該用戶\n");
	}
	else {
		printf("請輸入新的用戶名：");
		scanf("%s", users[index].username);
		printf("請輸入新的密碼：");
		scanf("%s", users[index].password);
		printf("請輸入新的用戶角色（1.管理員，2.教師，3.學生）：");
		scanf("%d", &users[index].role);
		printf("修改成功！\n");
	}
}

// 刪除用戶
void delete_user() {
	char user_id[20];
	printf("\n請輸入要刪除的用戶ID：");
	scanf("%s", user_id);
	int index = -1;
	for (int i = 0; i < user_count; i++) {
		if (strcmp(users[i].user_id, user_id) == 0) {
			index = i;
			break;
		}
	}
	if (index == -1) {
		printf("未找到該用戶\n");
	}
	else {
		// 刪除用戶
		for (int i = index; i < user_count - 1; i++) {
			users[i] = users[i + 1];
		}
		user_count--;
		printf("刪除成功！\n");
	}
}

// 用戶管理功能
void user_management() {
	while (1) {
		user_management_menu();
		int option;
		scanf("%d", &option);
		switch (option) {
		case USER_MANAGEMENT_QUERY_ALL_USERS:
			query_all_users();
			system("pause");
			break;
		case USER_MANAGEMENT_ADD_USER:
			add_user();
			system("pause");
			break;
		case USER_MANAGEMENT_MODIFY_USER:
			modify_user();
			system("pause");
			break;
		case USER_MANAGEMENT_DELETE_USER:
			delete_user();
			system("pause");
			break;
		case USER_MANAGEMENT_RETURN:
			return;
		default:
			printf("\n無效選項，請重新輸入\n");
			system("pause");
			break;
		}
	}
}