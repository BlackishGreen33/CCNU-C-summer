#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataFormat.h" // 調用教務管理系統數據格式頭文件
#include "DataStorage.h" // 調用用戶數據頭文件

// 教師管理菜單選項
enum TeacherManagementOption {
	TEACHER_MANAGEMENT_QUERY_ALL_TEACHERS = 1,
	TEACHER_MANAGEMENT_ADD_TEACHER,
	TEACHER_MANAGEMENT_MODIFY_TEACHER,
	TEACHER_MANAGEMENT_DELETE_TEACHER,
	TEACHER_MANAGEMENT_RETURN
};

// 教師管理菜單
void teacher_management_menu() {
	system("cls");
	printf("============教師管理============\n");
	printf("\t1. 查詢所有教師信息\n");
	printf("\t2. 新增教師\n");
	printf("\t3. 修改教師信息\n");
	printf("\t4. 刪除教師\n");
	printf("\t5. 返回\n");
	printf("\t請選擇操作：");
}

// 查詢所有教師信息
void query_all_teachers() {
	printf("\n所有教師信息如下：\n");
	printf("================================\n");
	printf("教師ID\t教師姓名\t教師性別\t教師學歷\t教師職稱\n");
	for (int i = 0; i < teacher_count; i++) {
		printf("%s\t%s\t%s\t%s\t%s\n", teachers[i].teacher_id, teachers[i].name, teachers[i].gender, teachers[i].education, teachers[i].title);
	}
}

// 新增教師
void add_teacher() {
	Teacher teacher;
	printf("\n請輸入新教師信息：\n");
	printf("教師ID：");
	scanf("%s", teacher.teacher_id);
	printf("教師姓名：");
	scanf("%s", teacher.name);
	printf("教師性別：");
	scanf("%s", teacher.gender);
	printf("教師學歷：");
	scanf("%s", teacher.education);
	printf("教師職稱：");
	scanf("%s", teacher.title);
	teachers[teacher_count++] = teacher;
	printf("添加成功！\n");

	//文件读写
	write_teacher();
	read_teacher();
}

// 修改教師信息
void modify_teacher() {
	char teacher_id[20];
	printf("\n請輸入要修改的教師ID：");
	scanf("%s", teacher_id);
	int index = -1;
	for (int i = 0; i < teacher_count; i++) {
		if (strcmp(teachers[i].teacher_id, teacher_id) == 0) {
			index = i;
			break;
		}
	}
	if (index == -1) {
		printf("未找到該教師\n");
	}
	else {
		printf("請輸入新的教師姓名：");
		scanf("%s", teachers[index].name);
		printf("請輸入新的教師性別：");
		scanf("%s", teachers[index].gender);
		printf("請輸入新的教師學歷：");
		scanf("%s", teachers[index].education);
		printf("請輸入新的教師職稱：");
		scanf("%s", teachers[index].title);
		printf("修改成功！\n");

		//文件读写
		write_teacher();
		read_teacher();
	}
}

// 刪除教師
void delete_teacher() {
	char teacher_id[20];
	printf("\n請輸入要刪除的教師ID：");
	scanf("%s", teacher_id);
	int index = -1;
	for (int i = 0; i < teacher_count; i++) {
		if (strcmp(teachers[i].teacher_id, teacher_id) == 0) {
			index = i;
			break;
		}
	}
	if (index == -1) {
		printf("未找到該教師\n");
	}
	else {
		// 刪除教師
		for (int i = index; i < teacher_count - 1; i++) {
			teachers[i] = teachers[i + 1];
		}
		teacher_count--;
		printf("刪除成功！\n");

		//文件读写
		write_teacher();
		read_teacher();
	}
}

// 教師管理功能
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
			printf("\n無效選項，請重新輸入\n");
			system("pause");
			break;
		}
	}
}