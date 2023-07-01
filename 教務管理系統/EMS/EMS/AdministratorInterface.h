#pragma once
#include <Windows.h>
#include "UserManagement.h"
#include "TeacherManagement.h"
#include "StudentManagement.h"
#include "CourseManagement.h"
#include "TeachingManagement.h"
#include "SelectionManagement.h"

// ���ﶵ
enum MenuOption {
	MENU_USER_MANAGEMENT = 1,
	MENU_TEACHER_MANAGEMENT,
	MENU_STUDENT_MANAGEMENT,
	MENU_COURSE_MANAGEMENT,
	MENU_TEACHING_MANAGEMENT,
	MENU_SELECTION_MANAGEMENT,
	MENU_EXIT
};

// ��ܵ��
void show_menu() {
	system("cls");
	printf("==========�޲z���ɭ�==========\n");
	printf("\t1. �Τ�޲z\n");
	printf("\t2. �Юv�޲z\n");
	printf("\t3. �ǥͺ޲z\n");
	printf("\t4. �ҵ{�޲z\n");
	printf("\t5. �½Һ޲z\n");
	printf("\t6. ��Һ޲z\n");
	printf("\t7. �h�X\n");
	printf("\t�п�ܾާ@�G");
}

// �޲z������
void administrator_interface() {
	while (1) {
		show_menu();
		int option;
		scanf("%d", &option);
		switch (option) {
		case MENU_USER_MANAGEMENT:
			user_management();
			system("pause");
			break;
		case MENU_TEACHER_MANAGEMENT:
			teacher_management();
			system("pause");
			break;
		case MENU_STUDENT_MANAGEMENT:
			student_management();
			system("pause");
			break;
		case MENU_COURSE_MANAGEMENT:
			course_management();
			system("pause");
			break;
		case MENU_TEACHING_MANAGEMENT:
			teaching_management();
			system("pause");
			break;
		case MENU_SELECTION_MANAGEMENT:
			selection_management();
			system("pause");
			break;
		case MENU_EXIT:
			printf("\n�A���I\n");
			system("pause");
			exit(0);
		default:
			printf("\n�L�Ŀﶵ�A�Э��s��J\n");
			system("pause");
			break;
		}
	}
}