#pragma once
#include <Windows.h>
#include "UserManagement.h"
#include "TeacherManagement.h"
#include "StudentManagement.h"
#include "CourseManagement.h"
#include "TeachingManagement.h"
#include "SelectionManagement.h"

// 菜單選項
enum MenuOption {
	MENU_USER_MANAGEMENT = 1,
	MENU_TEACHER_MANAGEMENT,
	MENU_STUDENT_MANAGEMENT,
	MENU_COURSE_MANAGEMENT,
	MENU_TEACHING_MANAGEMENT,
	MENU_SELECTION_MANAGEMENT,
	MENU_EXIT
};

// 顯示菜單
void show_menu() {
	system("cls");
	printf("==========管理員界面==========\n");
	printf("\t1. 用戶管理\n");
	printf("\t2. 教師管理\n");
	printf("\t3. 學生管理\n");
	printf("\t4. 課程管理\n");
	printf("\t5. 授課管理\n");
	printf("\t6. 選課管理\n");
	printf("\t7. 退出\n");
	printf("\t請選擇操作：");
}

// 管理員介面
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
			printf("\n再見！\n");
			system("pause");
			exit(0);
		default:
			printf("\n無效選項，請重新輸入\n");
			system("pause");
			break;
		}
	}
}