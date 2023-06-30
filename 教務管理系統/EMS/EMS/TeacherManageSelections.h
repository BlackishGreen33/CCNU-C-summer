#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataFormat.h" // �եαаȺ޲z�t�μƾڮ榡�Y���
#include "DataStorage.h" // �եΥΤ�ƾ��Y���

typedef enum {
    QUERY_SELECTIONS = 1,
    MODIFY_SCORE,
    RETURN_MAIN_MENU
} SelectionsOption;

// ��Һ޲z���
void teacher_selection_management_menu() {
    printf("��Һ޲z\n");
    printf("1. �d�߿�ҫH��\n");
    printf("2. �ק�ǥͦ��Z\n");
    printf("3. ��^�D���\n");
    printf("�п�ܾާ@�G");
}

// �d�߿�ҫH��
void query_selections(Teaching teachings[], int teaching_count, Selection selections[], int selection_count, char teacher_id[], char course_id[]) {
    int teaching_index = -1; // ��l�Ƨ�쪺�½ҤU�Ь�-1
    // �b�½ҫH���Ʋդ��d��ӱЮv�������½ҫH�����U��
    for (int i = 0; i < teaching_count; i++) {
        if (strcmp(teachings[i].teacher.teacher_id, teacher_id) == 0 && strcmp(teachings[i].course.course_id, course_id) == 0) {
            teaching_index = i;
            break;
        }
    }
    if (teaching_index != -1) { // ���½ҫH��
        printf("���%s�ҵ{���ǥͫH���G\n", course_id);
        printf("�ǥͽs��\t�ǥͩm�W\t�ǥͩʧO\t�Ҧb�Z��\t�ǥͦ��Z\n");
        // �M����ҫH���ƲաA���L�ӽҵ{���Ҧ���ҾǥͫH��
        for (int i = 0; i < selection_count; i++) {
            if (strcmp(selections[i].course.course_id, course_id) == 0) {
                printf("%s\t%s\t%s\t%s\t%.1f\n", selections[i].student.student_id, selections[i].student.name, selections[i].student.gender, selections[i].student.classroom, selections[i].score);
            }
        }
    }
    else {
        printf("�z���б¸ӽҵ{�θӽҵ{���s�b\n");
    }
}

// �ק�ǥͦ��Z
void modify_score(Selection selections[], int selection_count, char student_id[], char course_id[], float score) {
    int selection_index = -1; // ��l�Ƨ�쪺��ҤU�Ь�-1
    // �b��ҫH���Ʋդ��d��ӾǥͿ�ҫH�����U��
    for (int i = 0; i < selection_count; i++) {
        if (strcmp(selections[i].student.student_id, student_id) == 0 && strcmp(selections[i].course.course_id, course_id) == 0) {
            selection_index = i;
            break;
        }
    }
    if (selection_index != -1) { // ����ҫH��
        selections[selection_index].score = score;
        printf("�ǥͦ��Z�ק令�\\n");
    }
    else {
        printf("�Ӿǥͥ���׸ӽҵ{�θӽҵ{���s�b\n");
    }
}

// ��Һ޲z
void teacher_selection_management() {
    int user_index = -1; // ��l�Ƨ�쪺�Τ�U�Ь�-1
    // �b�Τ�Ʋդ��d���e�Τ᪺�U��
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, current_username) == 0) {
            user_index = i;
            break;
        }
    }
    if (user_index != -1 && users[user_index].role == 2) { // ��e�Τᬰ�Юv
        int option = 0; // ��l�ƿﶵ��0
        do {
            teacher_selection_management_menu();
            scanf("%d", &option);
            switch (option) {
            case QUERY_SELECTIONS: // �d�߿�ҫH��
            {
                char course_id[20]; // �ҵ{�s��
                printf("�п�J�ҵ{�s���G");
                scanf("%s", course_id);
                query_selections(teachings, teaching_count, selections, selection_count, users[user_index].user_id, course_id);
            }
            break;
            case MODIFY_SCORE: // �ק�ǥͦ��Z
            {
                char student_id[20]; // �ǥͽs��
                char course_id[20]; // �ҵ{�s��
                float score; // �ǥͦ��Z
                printf("�п�J�ǥͽs���G");
                scanf("%s", student_id);
                printf("�п�J�ҵ{�s���G");
                scanf("%s", course_id);
                printf("�п�J�ǥͦ��Z�G");
                scanf("%f", &score);
                modify_score(selections, selection_count, student_id, course_id, score);
            }
            break;
            case RETURN_MAIN_MENU: // ��^�D���
                printf("��^�D���\n");
                break;
            default:
                printf("�L�Ŀﶵ�A�Э��s��J\n");
                break;
            }
        } while (option != RETURN_MAIN_MENU);
    }
    else {
        printf("�Τᤣ�s�b�Τ��O�Юv\n");
    }
}