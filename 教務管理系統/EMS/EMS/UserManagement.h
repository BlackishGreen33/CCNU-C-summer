#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataFormat.h" // �եαаȺ޲z�t�μƾڮ榡�Y���
#include "DataStorage.h" // �եΥΤ�ƾ��Y���

// �Τ�޲z���ﶵ
enum UserManagementOption {
	USER_MANAGEMENT_QUERY_ALL_USERS = 1,
	USER_MANAGEMENT_ADD_USER,
	USER_MANAGEMENT_MODIFY_USER,
	USER_MANAGEMENT_DELETE_USER,
	USER_MANAGEMENT_RETURN
};

// �Τ�޲z���
void user_management_menu() {
	system("cls");
	printf("============�Τ�޲z============\n");
	printf("\t1. �d�ߩҦ��Τ�H��\n");
	printf("\t2. �s�W�Τ�\n");
	printf("\t3. �ק�Τ�H��\n");
	printf("\t4. �R���Τ�\n");
	printf("\t5. ��^\n");
	printf("\t�п�ܾާ@�G");
}

// �d�ߩҦ��Τ�H��
void query_all_users() {
	printf("\n�Ҧ��Τ�H���p�U�G\n");
	printf("�Τ�ID\t�Τ�W\t\t����\n");
	printf("================================\n");
	for (int i = 0; i < user_count; i++) {
		printf("%s\t%s\t", users[i].user_id, users[i].username);
		switch (users[i].role) {
		case 1:
			printf("\t�޲z��\n");
			break;
		case 2:
			printf("�Юv\n");
			break;
		case 3:
			printf("�ǥ�\n");
			break;
		default:
			printf("��������\n");
			break;
		}
	}
}

// �s�W�Τ�
void add_user() {
	User user;
	printf("\n�п�J�s�Τ�H���G\n");
	printf("�Τ�ID�G");
	scanf("%s", user.user_id);
	printf("�Τ�W�G");
	scanf("%s", user.username);
	printf("�K�X�G");
	scanf("%s", user.password);
	printf("�Τᨤ��]1.�޲z���A2.�Юv�A3.�ǥ͡^�G");
	scanf("%d", &user.role);
	users[user_count++] = user;
	printf("�K�[���\�I\n");
}

// �ק�Τ�H��
void modify_user() {
	char user_id[20];
	printf("\n�п�J�n�ק諸�Τ�ID�G");
	scanf("%s", user_id);
	int index = -1;
	for (int i = 0; i < user_count; i++) {
		if (strcmp(users[i].user_id, user_id) == 0) {
			index = i;
			break;
		}
	}
	if (index == -1) {
		printf("�����ӥΤ�\n");
	}
	else {
		printf("�п�J�s���Τ�W�G");
		scanf("%s", users[index].username);
		printf("�п�J�s���K�X�G");
		scanf("%s", users[index].password);
		printf("�п�J�s���Τᨤ��]1.�޲z���A2.�Юv�A3.�ǥ͡^�G");
		scanf("%d", &users[index].role);
		printf("�ק令�\�I\n");
	}
}

// �R���Τ�
void delete_user() {
	char user_id[20];
	printf("\n�п�J�n�R�����Τ�ID�G");
	scanf("%s", user_id);
	int index = -1;
	for (int i = 0; i < user_count; i++) {
		if (strcmp(users[i].user_id, user_id) == 0) {
			index = i;
			break;
		}
	}
	if (index == -1) {
		printf("�����ӥΤ�\n");
	}
	else {
		// �R���Τ�
		for (int i = index; i < user_count - 1; i++) {
			users[i] = users[i + 1];
		}
		user_count--;
		printf("�R�����\�I\n");
	}
}

// �Τ�޲z�\��
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
			printf("\n�L�Ŀﶵ�A�Э��s��J\n");
			system("pause");
			break;
		}
	}
}