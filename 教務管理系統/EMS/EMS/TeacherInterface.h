#pragma once
#include "ModifyPassword.h"
#include "QueryUserInfo.h"
#include "QueryTeacherTeachingInfo.h"
#include "QueryTeacherStudentsInfo.h"
#include "TeacherManageSelections.h"

// 教師界面菜單選項
enum TeacherMenuOption {
    TEACHER_MODIFY_PASSWORD = 1,
    TEACHER_QUERY_TEACHER_INFO,
    TEACHER_QUERY_COURSE_INFO,
    TEACHER_QUERY_STUDENT_INFO,
    TEACHER_SELECTION_MANAGEMENT,
    TEACHER_RETURN
};

void teacher_menu() {
    printf("教師界面\n");
    printf("1. 修改用戶密碼\n");
    printf("2. 教師信息查詢\n");
    printf("3. 課程信息查詢\n");
    printf("4. 學生信息查詢\n");
    printf("5. 選課管理\n");
    printf("6. 返回主菜單\n");
    printf("請選擇操作：");
}

void teacher_interface() {
    int choice;
    do {
        teacher_menu();
        scanf("%d", &choice);
        switch (choice) {
        case TEACHER_MODIFY_PASSWORD:
            modify_password();
            break;
        case TEACHER_QUERY_TEACHER_INFO:
            query_user_info();
            break;
        case TEACHER_QUERY_COURSE_INFO:
            query_teacher_teaching_info();
            break;
        case TEACHER_QUERY_STUDENT_INFO:
            query_teacher_students_info();
            break;
        case TEACHER_SELECTION_MANAGEMENT:
            teacher_selection_management();
            break;
        case TEACHER_RETURN:
            printf("再見！\n");
            exit(0);
        default:
            printf("無效選項，請重新輸入\n");
            break;
        }
    } while (choice != TEACHER_RETURN);
}