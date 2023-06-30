#pragma once
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
	printf("管理員界面\n");
	printf("1. 用戶管理\n");
	printf("2. 教師管理\n");
	printf("3. 學生管理\n");
	printf("4. 課程管理\n");
	printf("5. 授課管理\n");
	printf("6. 選課管理\n");
	printf("7. 退出\n");
	printf("請選擇操作：");
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
			printf("再見！\n");
			exit(0);
		default:
			printf("無效選項，請重新輸入\n");
			break;
		}
	}
}