#pragma once
#include "ModifyPassword.h"
#include "QueryStudentSelectionInfo.h"
#include "QueryStudentTeachersInfo.h"
#include "StudentQuerySelection.h"

// �ǥͬɭ����ﶵ
enum StudentMenuOption {
    STUDENT_MODIFY_PASSWORD = 1,
    STUDENT_QUERY_COURSE_INFO,
    STUDENT_QUERY_TEACHING_INFO,
    STUDENT_QUERY_SELECTION_INFO,
    STUDENT_RETURN
};

void student_menu() {
    printf("�ǥͬɭ�\n");
    printf("1. �ק�Τ�K�X\n");
    printf("2. �ҵ{�H���d��\n");
    printf("3. �½ҫH���d��\n");
    printf("4. ��ҫH���d��\n");
    printf("5. ��^�D���\n");
    printf("�п�ܾާ@�G");
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
            printf("�A���I\n");
            exit(0);
        default:
            printf("�L�Ŀﶵ�A�Э��s��J\n");
            break;
        }
    } while (choice != STUDENT_RETURN);
}