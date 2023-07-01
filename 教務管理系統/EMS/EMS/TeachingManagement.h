#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataFormat.h" // �եαаȺ޲z�t�μƾڮ榡�Y���
#include "DataStorage.h" // �եΥΤ�ƾ��Y���

// �½Һ޲z���ﶵ
enum TeachingManagementOption {
    TEACHING_MANAGEMENT_QUERY_ALL_TEACHING = 1,
    TEACHING_MANAGEMENT_ADD_TEACHING,
    TEACHING_MANAGEMENT_MODIFY_TEACHING,
    TEACHING_MANAGEMENT_DELETE_TEACHING,
    TEACHING_MANAGEMENT_RETURN
};

// �½Һ޲z���
void teaching_management_menu() {
    system("cls");
    printf("===========�ҵ{�޲z===========\n");
    printf("\t1. �d�ߩҦ��½ҫH��\n");
    printf("\t2. �s�W�½�\n");
    printf("\t3. �ק�½ҫH��\n");
    printf("\t4. �R���½�\n");
    printf("\t5. ��^\n");
    printf("\t�п�ܾާ@�G");
}

// �d�ߩҦ��½ҫH��
void query_all_teaching() {
    printf("�Ҧ��½ҫH���p�U�G\n");
    printf("================================\n");
    printf("�½�ID\t�ҵ{�s��\t�ҵ{�W��\t�Юv�s��\t�Юv�m�W\n");
    for (int i = 0; i < teaching_count; i++) {
        printf("%d\t%s\t%s\t%s\t%s\n",
            teachings[i].teach_id,
            teachings[i].course.course_id,
            teachings[i].course.name,
            teachings[i].teacher.teacher_id,
            teachings[i].teacher.name);
    }
}

// �s�W�½�
void add_teaching() {
    printf("\n�п�J�½ҫH���G\n");
    Teaching new_teaching;

    // �q�L��J�ҵ{�s���M�Юv�s���A�d��ҵ{�M�Юv�H��
    char course_id[20], teacher_id[20];
    printf("�п�J�ҵ{�s���G");
    scanf("%s", course_id);
    printf("�п�J�Юv�s���G");
    scanf("%s", teacher_id);

    Course course;
    Teacher teacher;
    int course_found = 0, teacher_found = 0;

    for (int i = 0; i < teaching_count; i++) {
        if (strcmp(teachings[i].course.course_id, course_id) == 0) {
            course = teachings[i].course;
            course_found = 1;
        }
        if (strcmp(teachings[i].teacher.teacher_id, teacher_id) == 0) {
            teacher = teachings[i].teacher;
            teacher_found = 1;
        }
        if (course_found && teacher_found) {
            break;
        }
    }

    if (!course_found) {
        printf("�����ӽҵ{�H���A�ݭn���K�[�ӽҵ{\n");
        return;
    }
    if (!teacher_found) {
        printf("�����ӱЮv�H���A�ݭn���K�[�ӱЮv\n");
        return;
    }

    // �]�m�½ҫH��
    new_teaching.course = course;
    new_teaching.teacher = teacher;
    new_teaching.teach_id = teaching_count + 1;

    // �N�s�½ҫH���K�[��C��
    teachings[teaching_count] = new_teaching;
    teaching_count++;

    printf("�½ҫH���K�[���\�I\n");
}

// �ק�½ҫH��
void modify_teaching() {
    printf("\n�п�J�n�ק諸�½�ID�G");
    int teach_id;
    scanf("%d", &teach_id);

    // �d��n�ק諸�½ҫH��
    int found_index = -1;
    for (int i = 0; i < teaching_count; i++) {
        if (teachings[i].teach_id == teach_id) {
            found_index = i;
            break;
        }
    }

    if (found_index == -1) {
        printf("�����ӱ½ҫH���I\n");
        return;
    }

    // �P�_�ӽҵ{�O�_���b�Q���
    if (teachings[found_index].course.is_selected) {
        printf("�ӽҵ{���b�Q��סA�L�k�ק�I\n");
        return;
    }

    // �q�L��J�ҵ{�s���M�Юv�s���A�d��ҵ{�M�Юv�H��
    char course_id[20], teacher_id[20];
    printf("�п�J�s���ҵ{�s���G");
    scanf("%s", course_id);
    printf("�п�J�s���Юv�s���G");
    scanf("%s", teacher_id);

    Course course;
    Teacher teacher;
    int course_found = 0, teacher_found = 0;

    for (int i = 0; i < teaching_count; i++) {
        if (strcmp(teachings[i].course.course_id, course_id) == 0) {
            course = teachings[i].course;
            course_found = 1;
        }
        if (strcmp(teachings[i].teacher.teacher_id, teacher_id) == 0) {
            teacher = teachings[i].teacher;
            teacher_found = 1;
        }
        if (course_found && teacher_found) {
            break;
        }
    }

    if (!course_found) {
        printf("�����ӽҵ{�H���A�ݭn���K�[�ӽҵ{\n");
        return;
    }
    if (!teacher_found) {
        printf("�����ӱЮv�H���A�ݭn���K�[�ӱЮv\n");
        return;
    }

    // �ק�½ҫH��
    teachings[found_index].course = course;
    teachings[found_index].teacher = teacher;

    printf("�½ҫH���ק令�\�I\n");
}

// �R���½�
void delete_teaching() {
    printf("\n�п�J�n�R�����½�ID�G");
    int teach_id;
    scanf("%d", &teach_id);

    // �d��n�R�����½ҫH��
    int found_index = -1;
    for (int i = 0; i < teaching_count; i++) {
        if (teachings[i].teach_id == teach_id) {
            found_index = i;
            break;
        }
    }

    if (found_index == -1) {
        printf("�����ӱ½ҫH���I\n");
        return;
    }

    // �P�_�ӽҵ{�O�_���b�Q���
    if (teachings[found_index].course.is_selected) {
        printf("�ӽҵ{���b�Q��סA�L�k�R���I\n");
        return;
    }

    // �N�ӱ½ҫH���q�C���R��
    for (int i = found_index; i < teaching_count - 1; i++) {
        teachings[i] = teachings[i + 1];
    }
    teaching_count--;

    printf("�½ҫH���R�����\�I\n");
}

// �½Һ޲z
void teaching_management() {
    while (1) {
        teaching_management_menu();
        int option;
        scanf("%d", &option);
        switch (option) {
        case TEACHING_MANAGEMENT_QUERY_ALL_TEACHING:
            query_all_teaching();
            system("pause");
            break;
        case TEACHING_MANAGEMENT_ADD_TEACHING:
            add_teaching();
            system("pause");
            break;
        case TEACHING_MANAGEMENT_MODIFY_TEACHING:
            modify_teaching();
            system("pause");
            break;
        case TEACHING_MANAGEMENT_DELETE_TEACHING:
            delete_teaching();
            system("pause");
            break;
        case TEACHING_MANAGEMENT_RETURN:
            return;
        default:
            printf("\n�L�Ŀﶵ�A�Э��s��J\n");
            system("pause");
            break;
        }
    }
}