#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataFormat.h" // 調用教務管理系統數據格式頭文件
#include "DataStorage.h" // 調用用戶數據頭文件

// 授課管理菜單選項
enum TeachingManagementOption {
    TEACHING_MANAGEMENT_QUERY_ALL_TEACHING = 1,
    TEACHING_MANAGEMENT_ADD_TEACHING,
    TEACHING_MANAGEMENT_MODIFY_TEACHING,
    TEACHING_MANAGEMENT_DELETE_TEACHING,
    TEACHING_MANAGEMENT_RETURN
};

// 授課管理菜單
void teaching_management_menu() {
    system("cls");
    printf("===========課程管理===========\n");
    printf("\t1. 查詢所有授課信息\n");
    printf("\t2. 新增授課\n");
    printf("\t3. 修改授課信息\n");
    printf("\t4. 刪除授課\n");
    printf("\t5. 返回\n");
    printf("\t請選擇操作：");
}

// 查詢所有授課信息
void query_all_teaching() {
    printf("所有授課信息如下：\n");
    printf("================================\n");
    printf("授課ID\t課程編號\t課程名稱\t教師編號\t教師姓名\n");
    for (int i = 0; i < teaching_count; i++) {
        printf("%d\t%s\t%s\t%s\t%s\n",
            teachings[i].teach_id,
            teachings[i].course.course_id,
            teachings[i].course.name,
            teachings[i].teacher.teacher_id,
            teachings[i].teacher.name);
    }
}

// 新增授課
void add_teaching() {
    printf("\n請輸入授課信息：\n");
    Teaching new_teaching;

    // 通過輸入課程編號和教師編號，查找課程和教師信息
    char course_id[20], teacher_id[20];
    printf("請輸入課程編號：");
    scanf("%s", course_id);
    printf("請輸入教師編號：");
    scanf("%s", teacher_id);

    Course course;
    Teacher teacher;
    int course_found = 0, teacher_found = 0;

    for (int i = 0; i < teaching_count; i++) {
        if (strcmp(teachings[i].course.course_id, course_id) == 0) {
            course = teachings[i].course;
            course_found = 1;
        }
        if (strcmp(teachings[i].teacher.teacher_id, teacher_id) == 0) {
            teacher = teachings[i].teacher;
            teacher_found = 1;
        }
        if (course_found && teacher_found) {
            break;
        }
    }

    if (!course_found) {
        printf("未找到該課程信息，需要先添加該課程\n");
        return;
    }
    if (!teacher_found) {
        printf("未找到該教師信息，需要先添加該教師\n");
        return;
    }

    // 設置授課信息
    new_teaching.course = course;
    new_teaching.teacher = teacher;
    new_teaching.teach_id = teaching_count + 1;

    // 將新授課信息添加到列表中
    teachings[teaching_count] = new_teaching;
    teaching_count++;

    printf("授課信息添加成功！\n");
}

// 修改授課信息
void modify_teaching() {
    printf("\n請輸入要修改的授課ID：");
    int teach_id;
    scanf("%d", &teach_id);

    // 查找要修改的授課信息
    int found_index = -1;
    for (int i = 0; i < teaching_count; i++) {
        if (teachings[i].teach_id == teach_id) {
            found_index = i;
            break;
        }
    }

    if (found_index == -1) {
        printf("未找到該授課信息！\n");
        return;
    }

    // 判斷該課程是否正在被選修
    if (teachings[found_index].course.is_selected) {
        printf("該課程正在被選修，無法修改！\n");
        return;
    }

    // 通過輸入課程編號和教師編號，查找課程和教師信息
    char course_id[20], teacher_id[20];
    printf("請輸入新的課程編號：");
    scanf("%s", course_id);
    printf("請輸入新的教師編號：");
    scanf("%s", teacher_id);

    Course course;
    Teacher teacher;
    int course_found = 0, teacher_found = 0;

    for (int i = 0; i < teaching_count; i++) {
        if (strcmp(teachings[i].course.course_id, course_id) == 0) {
            course = teachings[i].course;
            course_found = 1;
        }
        if (strcmp(teachings[i].teacher.teacher_id, teacher_id) == 0) {
            teacher = teachings[i].teacher;
            teacher_found = 1;
        }
        if (course_found && teacher_found) {
            break;
        }
    }

    if (!course_found) {
        printf("未找到該課程信息，需要先添加該課程\n");
        return;
    }
    if (!teacher_found) {
        printf("未找到該教師信息，需要先添加該教師\n");
        return;
    }

    // 修改授課信息
    teachings[found_index].course = course;
    teachings[found_index].teacher = teacher;

    printf("授課信息修改成功！\n");
}

// 刪除授課
void delete_teaching() {
    printf("\n請輸入要刪除的授課ID：");
    int teach_id;
    scanf("%d", &teach_id);

    // 查找要刪除的授課信息
    int found_index = -1;
    for (int i = 0; i < teaching_count; i++) {
        if (teachings[i].teach_id == teach_id) {
            found_index = i;
            break;
        }
    }

    if (found_index == -1) {
        printf("未找到該授課信息！\n");
        return;
    }

    // 判斷該課程是否正在被選修
    if (teachings[found_index].course.is_selected) {
        printf("該課程正在被選修，無法刪除！\n");
        return;
    }

    // 將該授課信息從列表中刪除
    for (int i = found_index; i < teaching_count - 1; i++) {
        teachings[i] = teachings[i + 1];
    }
    teaching_count--;

    printf("授課信息刪除成功！\n");
}

// 授課管理
void teaching_management() {
    while (1) {
        teaching_management_menu();
        int option;
        scanf("%d", &option);
        switch (option) {
        case TEACHING_MANAGEMENT_QUERY_ALL_TEACHING:
            query_all_teaching();
            system("pause");
            break;
        case TEACHING_MANAGEMENT_ADD_TEACHING:
            add_teaching();
            system("pause");
            break;
        case TEACHING_MANAGEMENT_MODIFY_TEACHING:
            modify_teaching();
            system("pause");
            break;
        case TEACHING_MANAGEMENT_DELETE_TEACHING:
            delete_teaching();
            system("pause");
            break;
        case TEACHING_MANAGEMENT_RETURN:
            return;
        default:
            printf("\n無效選項，請重新輸入\n");
            system("pause");
            break;
        }
    }
}