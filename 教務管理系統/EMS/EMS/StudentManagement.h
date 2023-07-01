#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataFormat.h" // 調用教務管理系統數據格式頭文件
#include "DataStorage.h" // 調用用戶數據頭文件

// 學生管理菜單選項
enum StudentManagementOption {
    STUDENT_MANAGEMENT_QUERY_ALL_STUDENTS = 1,
    STUDENT_MANAGEMENT_ADD_STUDENT,
    STUDENT_MANAGEMENT_MODIFY_STUDENT,
    STUDENT_MANAGEMENT_DELETE_STUDENT,
    STUDENT_MANAGEMENT_RETURN
};

// 學生管理菜單
void student_management_menu() {
    system("cls");
    printf("============學生管理============\n");
    printf("\t1. 查詢所有學生信息\n");
    printf("\t2. 新增學生\n");
    printf("\t3. 修改學生信息\n");
    printf("\t4. 刪除學生\n");
    printf("\t5. 返回\n");
    printf("\t請選擇操作：");
}

// 查詢所有學生信息
void query_all_students() {
    printf("所有學生信息如下：\n");
    printf("================================\n");
    printf("學生編號\t學生姓名\t學生性別\t學生班級\n");
    for (int i = 0; i < student_count; i++) {
        printf("%s\t%s\t%s\t%s\n", students[i].student_id, students[i].name, students[i].gender, students[i].classroom);
    }
}

// 新增學生
void add_student() {
    Student student;
    printf("\n請輸入新學生信息：\n");
    printf("學生編號：");
    scanf("%s", student.student_id);
    printf("學生姓名：");
    scanf("%s", student.name);
    printf("學生性別：");
    scanf("%s", student.gender);
    printf("學生班級：");
    scanf("%s", student.classroom);
    students[student_count++] = student;
    printf("添加成功！\n");
}

// 修改學生信息
void modify_student() {
    char student_id[20];
    printf("\n請輸入要修改的學生編號：");
    scanf("%s", student_id);
    int index = -1;
    for (int i = 0; i < student_count; i++) {
        if (strcmp(students[i].student_id, student_id) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("未找到該學生\n");
    }
    else {
        printf("請輸入新的學生姓名：");
        scanf("%s", students[index].name);
        printf("請輸入新的學生性別：");
        scanf("%s", students[index].gender);
        printf("請輸入新的學生班級：");
        scanf("%s", students[index].classroom);
        printf("修改成功！\n");
    }
}

// 刪除學生
void delete_student() {
    char student_id[20];
    printf("\n請輸入要刪除的學生編號：");
    scanf("%s", student_id);
    int index = -1;
    for (int i = 0; i < student_count; i++) {
        if (strcmp(students[i].student_id, student_id) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("未找到該學生\n");
    }
    else {
        // 刪除學生
        for (int i = index; i < student_count - 1; i++) {
            students[i] = students[i + 1];
        }
        student_count--;
        printf("刪除成功！\n");
    }
}

// 學生管理功能
void student_management() {
    while (1) {
        student_management_menu();
        int option;
        scanf("%d", &option);
        switch (option) {
        case STUDENT_MANAGEMENT_QUERY_ALL_STUDENTS:
            query_all_students();
            system("pause");
            break;
        case STUDENT_MANAGEMENT_ADD_STUDENT:
            add_student();
            system("pause");
            break;
        case STUDENT_MANAGEMENT_MODIFY_STUDENT:
            modify_student();
            system("pause");
            break;
        case STUDENT_MANAGEMENT_DELETE_STUDENT:
            delete_student();
            system("pause");
            break;
        case STUDENT_MANAGEMENT_RETURN:
            return;
        default:
            printf("無效選項，請重新輸入\n");
            system("pause");
            break;
        }
    }
}