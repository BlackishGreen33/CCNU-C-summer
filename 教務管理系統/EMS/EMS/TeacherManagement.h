#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataFormat.h" // �եαаȺ޲z�t�μƾڮ榡�Y���
#include "DataStorage.h" // �եΥΤ�ƾ��Y���

// �Юv�޲z���ﶵ
enum TeacherManagementOption {
	TEACHER_MANAGEMENT_QUERY_ALL_TEACHERS = 1,
	TEACHER_MANAGEMENT_ADD_TEACHER,
	TEACHER_MANAGEMENT_MODIFY_TEACHER,
	TEACHER_MANAGEMENT_DELETE_TEACHER,
	TEACHER_MANAGEMENT_RETURN
};

// �Юv�޲z���
void teacher_management_menu() {
	system("cls");
	printf("============�Юv�޲z============\n");
	printf("\t1. �d�ߩҦ��Юv�H��\n");
	printf("\t2. �s�W�Юv\n");
	printf("\t3. �ק�Юv�H��\n");
	printf("\t4. �R���Юv\n");
	printf("\t5. ��^\n");
	printf("\t�п�ܾާ@�G");
}

// �d�ߩҦ��Юv�H��
void query_all_teachers() {
	printf("\n�Ҧ��Юv�H���p�U�G\n");
	printf("================================\n");
	printf("�ЮvID\t�Юv�m�W\t�Юv�ʧO\t�Юv�Ǿ�\t�Юv¾��\n");
	for (int i = 0; i < teacher_count; i++) {
		printf("%s\t%s\t%s\t%s\t%s\n", teachers[i].teacher_id, teachers[i].name, teachers[i].gender, teachers[i].education, teachers[i].title);
	}
}

// �s�W�Юv
void add_teacher() {
	Teacher teacher;
	printf("\n�п�J�s�Юv�H���G\n");
	printf("�ЮvID�G");
	scanf("%s", teacher.teacher_id);
	printf("�Юv�m�W�G");
	scanf("%s", teacher.name);
	printf("�Юv�ʧO�G");
	scanf("%s", teacher.gender);
	printf("�Юv�Ǿ��G");
	scanf("%s", teacher.education);
	printf("�Юv¾�١G");
	scanf("%s", teacher.title);
	teachers[teacher_count++] = teacher;
	printf("�K�[���\�I\n");
}

// �ק�Юv�H��
void modify_teacher() {
	char teacher_id[20];
	printf("\n�п�J�n�ק諸�ЮvID�G");
	scanf("%s", teacher_id);
	int index = -1;
	for (int i = 0; i < teacher_count; i++) {
		if (strcmp(teachers[i].teacher_id, teacher_id) == 0) {
			index = i;
			break;
		}
	}
	if (index == -1) {
		printf("�����ӱЮv\n");
	}
	else {
		printf("�п�J�s���Юv�m�W�G");
		scanf("%s", teachers[index].name);
		printf("�п�J�s���Юv�ʧO�G");
		scanf("%s", teachers[index].gender);
		printf("�п�J�s���Юv�Ǿ��G");
		scanf("%s", teachers[index].education);
		printf("�п�J�s���Юv¾�١G");
		scanf("%s", teachers[index].title);
		printf("�ק令�\�I\n");
	}
}

// �R���Юv
void delete_teacher() {
	char teacher_id[20];
	printf("\n�п�J�n�R�����ЮvID�G");
	scanf("%s", teacher_id);
	int index = -1;
	for (int i = 0; i < teacher_count; i++) {
		if (strcmp(teachers[i].teacher_id, teacher_id) == 0) {
			index = i;
			break;
		}
	}
	if (index == -1) {
		printf("�����ӱЮv\n");
	}
	else {
		// �R���Юv
		for (int i = index; i < teacher_count - 1; i++) {
			teachers[i] = teachers[i + 1];
		}
		teacher_count--;
		printf("�R�����\�I\n");
	}
}

// �Юv�޲z�\��
void teacher_management() {
	while (1) {
		teacher_management_menu();
		int option;
		scanf("%d", &option);
		switch (option) {
		case TEACHER_MANAGEMENT_QUERY_ALL_TEACHERS:
			query_all_teachers();
			system("pause");
			break;
		case TEACHER_MANAGEMENT_ADD_TEACHER:
			add_teacher();
			system("pause");
			break;
		case TEACHER_MANAGEMENT_MODIFY_TEACHER:
			modify_teacher();
			system("pause");
			break;
		case TEACHER_MANAGEMENT_DELETE_TEACHER:
			delete_teacher();
			system("pause");
			break;
		case TEACHER_MANAGEMENT_RETURN:
			return;
		default:
			printf("\n�L�Ŀﶵ�A�Э��s��J\n");
			system("pause");
			break;
		}
	}
}