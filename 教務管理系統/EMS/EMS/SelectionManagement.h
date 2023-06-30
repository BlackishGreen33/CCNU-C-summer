#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataFormat.h" // �եαаȺ޲z�t�μƾڮ榡�Y���
#include "DataStorage.h" // �եΥΤ�ƾ��Y���

// ��Һ޲z���ﶵ
enum SelectionManagementOption {
    SELECTION_MANAGEMENT_QUERY_ALL_SELECTION = 1,
    SELECTION_MANAGEMENT_ADD_SELECTION,
    SELECTION_MANAGEMENT_MODIFY_SELECTION,
    SELECTION_MANAGEMENT_DELETE_SELECTION,
    SELECTION_MANAGEMENT_RETURN
};

// ��Һ޲z���
void selection_management_menu() {
    printf("��Һ޲z\n");
    printf("1. �d�ߩҦ���ҫH��\n");
    printf("2. �s�W���\n");
    printf("3. �ק��ҫH��\n");
    printf("4. �R�����\n");
    printf("5. ��^�D���\n");
    printf("�п�ܾާ@�G");
}

// �d�ߩҦ���ҫH��
void query_all_selection() {
    printf("��ҫH���C��G\n");
    printf("���ID\t�ҵ{�W��\t�ǥͩm�W\t�ǥͦ��Z\n");
    for (int i = 0; i < selection_count; i++) {
        printf("%d\t%s\t%s\t%.2f\n", selections[i].select_id, selections[i].course.name, selections[i].student.name, selections[i].score);
    }
}

// �s�W���
void add_selection() {
    Selection selection;
    printf("�п�J���ID�G");
    scanf("%d", &selection.select_id);
    printf("�п�J�ҵ{�s���G");
    scanf("%s", selection.course.course_id);
    printf("�п�J�ǥͽs���G");
    scanf("%s", selection.student.student_id);
    printf("�п�J�ǥͦ��Z�G");
    scanf("%f", &selection.score);
    // �d��ҵ{�H���M�ǥͫH��
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
        // �P�_�ӿ�ҬO�_�w�s�b
        int exists = 0;
        for (int i = 0; i < selection_count; i++) {
            if (selections[i].select_id == selection.select_id) {
                exists = 1;
                break;
            }
        }
        if (exists) {
            printf("�ӿ�Ҥw�s�b\n");
        }
        else {
            // �K�[��ҫH��
            selections[selection_count] = selection;
            selection_count++;
            printf("�s�W��Ҧ��\\n");
        }
    }
    else {
        printf("�ҵ{�ξǥͫH�����s�b\n");
    }
}

// �ק��ҫH��
void modify_selection() {
    int select_id;
    printf("�п�J�n�ק諸���ID�G");
    scanf("%d", &select_id);
    // �d���ҫH��
    int index = -1;
    for (int i = 0; i < selection_count; i++) {
        if (selections[i].select_id == select_id) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        printf("���ID\t�ҵ{�W��\t�ǥͩm�W\t�ǥͦ��Z\n");
        printf("%d\t%s\t%s\t%.2f\n", selections[index].select_id, selections[index].course.name, selections[index].student.name, selections[index].score);
        printf("�п�J�s���ǥͦ��Z�G");
        scanf("%f", &selections[index].score);
        printf("�ק��Ҧ��\\n");
    }
    else {
        printf("��ҫH�����s�b\n");
    }
}

// �R�����
void delete_selection() {
    int select_id;
    printf("�п�J�n�R�������ID�G");
    scanf("%d", &select_id);
    // �d���ҫH��
    int index = -1;
    for (int i = 0; i < selection_count; i++) {
        if (selections[i].select_id == select_id) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        // �R����ҫH��
        for (int i = index; i < selection_count - 1; i++) {
            selections[i] = selections[i + 1];
        }
        selection_count--;
        printf("�R����Ҧ��\\n");
    }
    else {
        printf("��ҫH�����s�b\n");
    }
}

// ��Һ޲z
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
            printf("��^�D���\n");
            break;
        default:
            printf("�L�Ŀﶵ�A�Э��s��J\n");
            break;
        }
    } while (choice != SELECTION_MANAGEMENT_RETURN);
}