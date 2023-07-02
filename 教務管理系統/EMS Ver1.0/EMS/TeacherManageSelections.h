#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataFormat.h" // 調用教務管理系統數據格式頭文件
#include "DataStorage.h" // 調用用戶數據頭文件

typedef enum {
    QUERY_SELECTIONS = 1,
    MODIFY_SCORE,
    RETURN_MAIN_MENU
} SelectionsOption;

// 選課管理菜單
void teacher_selection_management_menu() {
    system("cls");
    printf("============選課管理============\n");
    printf("\t1. 查詢選課信息\n");
    printf("\t2. 修改學生成績\n");
    printf("\t3. 返回\n");
    printf("\t請選擇操作：");
}

// 查詢選課信息
void query_selections(Teaching teachings[], int teaching_count, Selection selections[], int selection_count, char teacher_id[], char course_id[]) {
    int teaching_index = -1; // 初始化找到的授課下標為-1
    // 在授課信息數組中查找該教師對應的授課信息的下標
    for (int i = 0; i < teaching_count; i++) {
        if (strcmp(teachings[i].teacher.teacher_id, teacher_id) == 0 && strcmp(teachings[i].course.course_id, course_id) == 0) {
            teaching_index = i;
            break;
        }
    }
    if (teaching_index != -1) { // 找到授課信息
        printf("\n選修%s課程的學生信息：\n", course_id);
        printf("================================\n");
        printf("學生編號\t學生姓名\t學生性別\t所在班級\t學生成績\n");
        // 遍歷選課信息數組，打印該課程的所有選課學生信息
        for (int i = 0; i < selection_count; i++) {
            if (strcmp(selections[i].course.course_id, course_id) == 0) {
                printf("%s\t%s\t%s\t%s\t%.1f\n", selections[i].student.student_id, selections[i].student.name, selections[i].student.gender, selections[i].student.classroom, selections[i].score);
            }
        }
    }
    else {
        printf("\n您未教授該課程或該課程不存在\n");
    }
}

// 修改學生成績
void modify_score(Selection selections[], int selection_count, char student_id[], char course_id[], float score) {
    int selection_index = -1; // 初始化找到的選課下標為-1
    // 在選課信息數組中查找該學生選課信息的下標
    for (int i = 0; i < selection_count; i++) {
        if (strcmp(selections[i].student.student_id, student_id) == 0 && strcmp(selections[i].course.course_id, course_id) == 0) {
            selection_index = i;
            break;
        }
    }
    if (selection_index != -1) { // 找到選課信息
        selections[selection_index].score = score;
        printf("學生成績修改成功\n");

        // 文件讀寫
        write_selection();
        read_selection();
    }
    else {
        printf("\n該學生未選修該課程或該課程不存在\n");
    }
}

// 選課管理
void teacher_selection_management() {
    int user_index = -1; // 初始化找到的用戶下標為-1
    // 在用戶數組中查找當前用戶的下標
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, current_username) == 0) {
            user_index = i;
            break;
        }
    }
    if (user_index != -1 && users[user_index].role == 2) { // 當前用戶為教師
        int option = 0; // 初始化選項為0
        while (1) {
            teacher_selection_management_menu();
            scanf("%d", &option);
            switch (option) {
            case QUERY_SELECTIONS:
                {
                    char course_id[20]; // 課程編號
                    printf("\n請輸入課程編號：");
                    scanf("%s", course_id);
                    query_selections(teachings, teaching_count, selections, selection_count, users[user_index].user_id, course_id);
                }
                system("pause");
                break;
            case MODIFY_SCORE:
                {
                    char student_id[20];
                    char course_id[20];
                    float score;
                    printf("\n請輸入學生編號：");
                    scanf("%s", student_id);
                    printf("請輸入課程編號：");
                    scanf("%s", course_id);
                    printf("請輸入學生成績：");
                    scanf("%f", &score);
                    modify_score(selections, selection_count, student_id, course_id, score);
                }
                system("pause");
                break;
            case RETURN_MAIN_MENU:
                return;
            default:
                printf("\n無效選項，請重新輸入\n");
                system("pause");
                break;
            }
        }
    }
    else {
        printf("\n用戶不存在或不是教師\n");
    }
}