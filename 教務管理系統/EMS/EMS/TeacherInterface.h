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
    system("cls");
    printf("===========�Юv�ɭ�===========\n");
    printf("\t1. �ק�Τ�K�X\n");
    printf("\t2. �Юv�H���d��\n");
    printf("\t3. �ҵ{�H���d��\n");
    printf("\t4. �ǥͫH���d��\n");
    printf("\t5. ��Һ޲z\n");
    printf("\t6. ��^�D���\n");
    printf("\t�п�ܾާ@�G");
}

void teacher_interface() {
    int choice;
    do {
        teacher_menu();
        scanf("%d", &choice);
        switch (choice) {
        case TEACHER_MODIFY_PASSWORD:
            modify_password();
            system("pause");
            break;
        case TEACHER_QUERY_TEACHER_INFO:
            query_user_info();
            system("pause");
            break;
        case TEACHER_QUERY_COURSE_INFO:
            query_teacher_teaching_info();
            system("pause");
            break;
        case TEACHER_QUERY_STUDENT_INFO:
            query_teacher_students_info();
            system("pause");
            break;
        case TEACHER_SELECTION_MANAGEMENT:
            teacher_selection_management();
            system("pause");
            break;
        case TEACHER_RETURN:
            printf("�A���I\n");
            system("pause");
            exit(0);
        default:
            printf("�L�Ŀﶵ�A�Э��s��J\n");
            system("pause");
            break;
        }
    } while (choice != TEACHER_RETURN);
}