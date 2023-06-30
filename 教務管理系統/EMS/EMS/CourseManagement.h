#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataFormat.h" // �եαаȺ޲z�t�μƾڮ榡�Y���
#include "DataStorage.h" // �եΥΤ�ƾ��Y���

// �ҵ{�޲z���ﶵ
enum CourseManagementOption {
    COURSE_MANAGEMENT_QUERY_ALL_COURSES = 1,
    COURSE_MANAGEMENT_ADD_COURSE,
    COURSE_MANAGEMENT_MODIFY_COURSE,
    COURSE_MANAGEMENT_DELETE_COURSE,
    COURSE_MANAGEMENT_RETURN
};

// �ҵ{�޲z���
void course_management_menu() {
    printf("�ҵ{�޲z\n");
    printf("1. �d�ߩҦ��ҵ{�H��\n");
    printf("2. �s�W�ҵ{\n");
    printf("3. �ק�ҵ{�H��\n");
    printf("4. �R���ҵ{\n");
    printf("5. ��^\n");
    printf("�п�ܾާ@�G");
}

// �d�ߩҦ��ҵ{�H��
void query_all_courses() {
    printf("�Ҧ��ҵ{�H���p�U�G\n");
    printf("�ҵ{�s��\t�ҵ{�W��\t�ҵ{�ʽ�\t�ҵ{�Ǯ�\t�ҵ{�Ǥ�\t�}�ҾǴ�\n");
    for (int i = 0; i < course_count; i++) {
        printf("%s\t%s\t%s\t%d\t%.1f\t%s\n", courses[i].course_id, courses[i].name, courses[i].nature, courses[i].hours, courses[i].credit, courses[i].term);
    }
}

// �s�W�ҵ{
void add_course() {
    Course course;
    printf("�п�J�s�ҵ{�H���G\n");
    printf("�ҵ{�s���G");
    scanf("%s", course.course_id);
    printf("�ҵ{�W�١G");
    scanf("%s", course.name);
    printf("�ҵ{�ʽ�G");
    scanf("%s", course.nature);
    printf("�ҵ{�ǮɡG");
    scanf("%d", &course.hours);
    printf("�ҵ{�Ǥ��G");
    scanf("%f", &course.credit);
    printf("�}�ҾǴ��G");
    scanf("%s", course.term);
    course.is_teaching = 0;
    course.is_selected = 0;
    courses[course_count++] = course;
    printf("�K�[���\�I\n");
}

// �ק�ҵ{�H��
void modify_course() {
    char course_id[20];
    printf("�п�J�n�ק諸�ҵ{�s���G");
    scanf("%s", course_id);
    int index = -1;
    for (int i = 0; i < course_count; i++) {
        if (strcmp(courses[i].course_id, course_id) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("�����ӽҵ{\n");
    }
    else if (courses[index].is_teaching || courses[index].is_selected) {
        printf("�ӽҵ{���b�Q���©Ϊ̾ǥͿ�סA�L�k�ק�\n");
    }
    else {
        printf("�п�J�s���ҵ{�W�١G");
        scanf("%s", courses[index].name);
        printf("�п�J�s���ҵ{�ʽ�G");
        scanf("%s", courses[index].nature);
        printf("�п�J�s���ҵ{�ǮɡG");
        scanf("%d", &courses[index].hours);
        printf("�п�J�s���ҵ{�Ǥ��G");
        scanf("%f", &courses[index].credit);
        printf("�п�J�s���}�ҾǴ��G");
        scanf("%s", courses[index].term);
        printf("�ק令�\�I\n");
    }
}

// �R���ҵ{
void delete_course() {
    char course_id[20];
    printf("�п�J�n�R�����ҵ{�s���G");
    scanf("%s", course_id);
    int index = -1;
    for (int i = 0; i < course_count; i++) {
        if (strcmp(courses[i].course_id, course_id) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("�����ӽҵ{\n");
    }
    else if (courses[index].is_teaching || courses[index].is_selected) {
        printf("�ӽҵ{���b�Q���©Ϊ̾ǥͿ�סA�L�k�R��\n");
    }
    else {
        for (int i = index; i < course_count - 1; i++) {
            courses[i] = courses[i + 1];
        }
        course_count--;
        printf("�R�����\�I\n");
    }
}

// �ҵ{�޲z
void course_management() {
    while (1) {
        course_management_menu();
        int option;
        printf("�п�ܾާ@�G");
        scanf("%d", &option);
        switch (option) {
        case COURSE_MANAGEMENT_QUERY_ALL_COURSES:
            query_all_courses();
            break;
        case COURSE_MANAGEMENT_ADD_COURSE:
            add_course();
            break;
        case COURSE_MANAGEMENT_MODIFY_COURSE:
            modify_course();
            break;
        case COURSE_MANAGEMENT_DELETE_COURSE:
            delete_course();
            break;
        case COURSE_MANAGEMENT_RETURN:
            return;
        default:
            printf("�L�Ī��ﶵ�A�Э��s���\n");
            break;
        }
    }
}