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
    system("cls");
    printf("============�ǥͬɭ�============\n");
    printf("\t1. �ק�Τ�K�X\n");
    printf("\t2. �ҵ{�H���d��\n");
    printf("\t3. �½ҫH���d��\n");
    printf("\t4. ��ҫH���d��\n");
    printf("\t5. ��^�D���\n");
    printf("\t�п�ܾާ@�G");
}

void student_interface() {
    int choice;
    do {
        student_menu();
        scanf("%d", &choice);
        switch (choice) {
        case STUDENT_MODIFY_PASSWORD:
            modify_password();
            system("pause");
            break;
        case STUDENT_QUERY_COURSE_INFO:
            query_student_selection_info();
            system("pause");
            break;
        case STUDENT_QUERY_TEACHING_INFO:
            query_student_teachers_info();
            system("pause");
            break;
        case STUDENT_QUERY_SELECTION_INFO:
            student_query_selection();
            system("pause");
            break;
        case STUDENT_RETURN:
            printf("�A���I\n");
            system("pause");
            exit(0);
        default:
            printf("�L�Ŀﶵ�A�Э��s��J\n");
            system("pause");
            break;
        }
    } while (choice != STUDENT_RETURN);
}