#pragma once
#include "ModifyPassword.h"
#include "QueryUserInfo.h"
#include "QueryTeacherTeachingInfo.h"
#include "QueryTeacherStudentsInfo.h"
#include "TeacherManageSelections.h"

// �Юv�ɭ����ﶵ
enum TeacherMenuOption {
    TEACHER_MODIFY_PASSWORD = 1,
    TEACHER_QUERY_TEACHER_INFO,
    TEACHER_QUERY_COURSE_INFO,
    TEACHER_QUERY_STUDENT_INFO,
    TEACHER_SELECTION_MANAGEMENT,
    TEACHER_RETURN
};

void teacher_menu() {
    printf("�Юv�ɭ�\n");
    printf("1. �ק�Τ�K�X\n");
    printf("2. �Юv�H���d��\n");
    printf("3. �ҵ{�H���d��\n");
    printf("4. �ǥͫH���d��\n");
    printf("5. ��Һ޲z\n");
    printf("6. ��^�D���\n");
    printf("�п�ܾާ@�G");
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
            printf("�A���I\n");
            exit(0);
        default:
            printf("�L�Ŀﶵ�A�Э��s��J\n");
            break;
        }
    } while (choice != TEACHER_RETURN);
}