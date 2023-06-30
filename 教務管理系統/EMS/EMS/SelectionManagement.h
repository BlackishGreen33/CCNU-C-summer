#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataFormat.h" // 調用教務管理系統數據格式頭文件
#include "DataStorage.h" // 調用用戶數據頭文件

// 選課管理菜單選項
enum SelectionManagementOption {
    SELECTION_MANAGEMENT_QUERY_ALL_SELECTION = 1,
    SELECTION_MANAGEMENT_ADD_SELECTION,
    SELECTION_MANAGEMENT_MODIFY_SELECTION,
    SELECTION_MANAGEMENT_DELETE_SELECTION,
    SELECTION_MANAGEMENT_RETURN
};

// 選課管理菜單
void selection_management_menu() {
    printf("選課管理\n");
    printf("1. 查詢所有選課信息\n");
    printf("2. 新增選課\n");
    printf("3. 修改選課信息\n");
    printf("4. 刪除選課\n");
    printf("5. 返回主菜單\n");
    printf("請選擇操作：");
}

// 查詢所有選課信息
void query_all_selection() {
    printf("選課信息列表：\n");
    printf("選課ID\t課程名稱\t學生姓名\t學生成績\n");
    for (int i = 0; i < selection_count; i++) {
        printf("%d\t%s\t%s\t%.2f\n", selections[i].select_id, selections[i].course.name, selections[i].student.name, selections[i].score);
    }
}

// 新增選課
void add_selection() {
    Selection selection;
    printf("請輸入選課ID：");
    scanf("%d", &selection.select_id);
    printf("請輸入課程編號：");
    scanf("%s", selection.course.course_id);
    printf("請輸入學生編號：");
    scanf("%s", selection.student.student_id);
    printf("請輸入學生成績：");
    scanf("%f", &selection.score);
    // 查找課程信息和學生信息
    int course_found = 0;
    int student_found = 0;
    for (int i = 0; i < course_count; i++) {
        if (strcmp(courses[i].course_id, selection.course.course_id) == 0) {
            selection.course = courses[i];
            course_found = 1;
            break;
        }
    }
    for (int i = 0; i < student_count; i++) {
        if (strcmp(students[i].student_id, selection.student.student_id) == 0) {
            selection.student = students[i];
            student_found = 1;
            break;
        }
    }
    if (course_found && student_found) {
        // 判斷該選課是否已存在
        int exists = 0;
        for (int i = 0; i < selection_count; i++) {
            if (selections[i].select_id == selection.select_id) {
                exists = 1;
                break;
            }
        }
        if (exists) {
            printf("該選課已存在\n");
        }
        else {
            // 添加選課信息
            selections[selection_count] = selection;
            selection_count++;
            printf("新增選課成功\n");
        }
    }
    else {
        printf("課程或學生信息不存在\n");
    }
}

// 修改選課信息
void modify_selection() {
    int select_id;
    printf("請輸入要修改的選課ID：");
    scanf("%d", &select_id);
    // 查找選課信息
    int index = -1;
    for (int i = 0; i < selection_count; i++) {
        if (selections[i].select_id == select_id) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        printf("選課ID\t課程名稱\t學生姓名\t學生成績\n");
        printf("%d\t%s\t%s\t%.2f\n", selections[index].select_id, selections[index].course.name, selections[index].student.name, selections[index].score);
        printf("請輸入新的學生成績：");
        scanf("%f", &selections[index].score);
        printf("修改選課成功\n");
    }
    else {
        printf("選課信息不存在\n");
    }
}

// 刪除選課
void delete_selection() {
    int select_id;
    printf("請輸入要刪除的選課ID：");
    scanf("%d", &select_id);
    // 查找選課信息
    int index = -1;
    for (int i = 0; i < selection_count; i++) {
        if (selections[i].select_id == select_id) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        // 刪除選課信息
        for (int i = index; i < selection_count - 1; i++) {
            selections[i] = selections[i + 1];
        }
        selection_count--;
        printf("刪除選課成功\n");
    }
    else {
        printf("選課信息不存在\n");
    }
}

// 選課管理
void selection_management() {
    int choice;
    do {
        selection_management_menu();
        scanf("%d", &choice);
        switch (choice) {
        case SELECTION_MANAGEMENT_QUERY_ALL_SELECTION:
            query_all_selection();
            break;
        case SELECTION_MANAGEMENT_ADD_SELECTION:
            add_selection();
            break;
        case SELECTION_MANAGEMENT_MODIFY_SELECTION:
            modify_selection();
            break;
        case SELECTION_MANAGEMENT_DELETE_SELECTION:
            delete_selection();
            break;
        case SELECTION_MANAGEMENT_RETURN:
            printf("返回主菜單\n");
            break;
        default:
            printf("無效選項，請重新輸入\n");
            break;
        }
    } while (choice != SELECTION_MANAGEMENT_RETURN);
}