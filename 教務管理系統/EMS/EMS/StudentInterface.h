#pragma once
#include "ModifyPassword.h"
#include "QueryStudentSelectionInfo.h"
#include "QueryStudentTeachersInfo.h"
#include "StudentQuerySelection.h"

// 學生界面菜單選項
enum StudentMenuOption {
    STUDENT_MODIFY_PASSWORD = 1,
    STUDENT_QUERY_COURSE_INFO,
    STUDENT_QUERY_TEACHING_INFO,
    STUDENT_QUERY_SELECTION_INFO,
    STUDENT_RETURN
};

void student_menu() {
    printf("學生界面\n");
    printf("1. 修改用戶密碼\n");
    printf("2. 課程信息查詢\n");
    printf("3. 授課信息查詢\n");
    printf("4. 選課信息查詢\n");
    printf("5. 返回主菜單\n");
    printf("請選擇操作：");
}

void student_interface() {
    int choice;
    do {
        student_menu();
        scanf("%d", &choice);
        switch (choice) {
        case STUDENT_MODIFY_PASSWORD:
            modify_password();
            break;
        case STUDENT_QUERY_COURSE_INFO:
            query_student_selection_info();
            break;
        case STUDENT_QUERY_TEACHING_INFO:
            query_student_teachers_info();
            break;
        case STUDENT_QUERY_SELECTION_INFO:
            student_query_selection();
            break;
        case STUDENT_RETURN:
            printf("再見！\n");
            exit(0);
        default:
            printf("無效選項，請重新輸入\n");
            break;
        }
    } while (choice != STUDENT_RETURN);
}