#pragma once
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
	printf("�޲z���ɭ�\n");
	printf("1. �Τ�޲z\n");
	printf("2. �Юv�޲z\n");
	printf("3. �ǥͺ޲z\n");
	printf("4. �ҵ{�޲z\n");
	printf("5. �½Һ޲z\n");
	printf("6. ��Һ޲z\n");
	printf("7. �h�X\n");
	printf("�п�ܾާ@�G");
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
			break;
		case MENU_TEACHER_MANAGEMENT:
			teacher_management();
			break;
		case MENU_STUDENT_MANAGEMENT:
			student_management();
			break;
		case MENU_COURSE_MANAGEMENT:
			course_management();
			break;
		case MENU_TEACHING_MANAGEMENT:
			teaching_management();
			break;
		case MENU_SELECTION_MANAGEMENT:
			selection_management();
			break;
		case MENU_EXIT:
			printf("�A���I\n");
			exit(0);
		default:
			printf("�L�Ŀﶵ�A�Э��s��J\n");
			break;
		}
	}
}