#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataFormat.h" // �եαаȺ޲z�t�μƾڮ榡�Y���
#include "DataStorage.h" // �եΥΤ�ƾ��Y���

// �ǥͺ޲z���ﶵ
enum StudentManagementOption {
    STUDENT_MANAGEMENT_QUERY_ALL_STUDENTS = 1,
    STUDENT_MANAGEMENT_ADD_STUDENT,
    STUDENT_MANAGEMENT_MODIFY_STUDENT,
    STUDENT_MANAGEMENT_DELETE_STUDENT,
    STUDENT_MANAGEMENT_RETURN
};

// �ǥͺ޲z���
void student_management_menu() {
    system("cls");
    printf("============�ǥͺ޲z============\n");
    printf("\t1. �d�ߩҦ��ǥͫH��\n");
    printf("\t2. �s�W�ǥ�\n");
    printf("\t3. �ק�ǥͫH��\n");
    printf("\t4. �R���ǥ�\n");
    printf("\t5. ��^\n");
    printf("\t�п�ܾާ@�G");
}

// �d�ߩҦ��ǥͫH��
void query_all_students() {
    printf("�Ҧ��ǥͫH���p�U�G\n");
    printf("================================\n");
    printf("�ǥͽs��\t�ǥͩm�W\t�ǥͩʧO\t�ǥͯZ��\n");
    for (int i = 0; i < student_count; i++) {
        printf("%s\t%s\t%s\t%s\n", students[i].student_id, students[i].name, students[i].gender, students[i].classroom);
    }
}

// �s�W�ǥ�
void add_student() {
    Student student;
    printf("\n�п�J�s�ǥͫH���G\n");
    printf("�ǥͽs���G");
    scanf("%s", student.student_id);
    printf("�ǥͩm�W�G");
    scanf("%s", student.name);
    printf("�ǥͩʧO�G");
    scanf("%s", student.gender);
    printf("�ǥͯZ�šG");
    scanf("%s", student.classroom);
    students[student_count++] = student;
    printf("�K�[���\�I\n");
}

// �ק�ǥͫH��
void modify_student() {
    char student_id[20];
    printf("\n�п�J�n�ק諸�ǥͽs���G");
    scanf("%s", student_id);
    int index = -1;
    for (int i = 0; i < student_count; i++) {
        if (strcmp(students[i].student_id, student_id) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("�����Ӿǥ�\n");
    }
    else {
        printf("�п�J�s���ǥͩm�W�G");
        scanf("%s", students[index].name);
        printf("�п�J�s���ǥͩʧO�G");
        scanf("%s", students[index].gender);
        printf("�п�J�s���ǥͯZ�šG");
        scanf("%s", students[index].classroom);
        printf("�ק令�\�I\n");
    }
}

// �R���ǥ�
void delete_student() {
    char student_id[20];
    printf("\n�п�J�n�R�����ǥͽs���G");
    scanf("%s", student_id);
    int index = -1;
    for (int i = 0; i < student_count; i++) {
        if (strcmp(students[i].student_id, student_id) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("�����Ӿǥ�\n");
    }
    else {
        // �R���ǥ�
        for (int i = index; i < student_count - 1; i++) {
            students[i] = students[i + 1];
        }
        student_count--;
        printf("�R�����\�I\n");
    }
}

// �ǥͺ޲z�\��
void student_management() {
    while (1) {
        student_management_menu();
        int option;
        scanf("%d", &option);
        switch (option) {
        case STUDENT_MANAGEMENT_QUERY_ALL_STUDENTS:
            query_all_students();
            system("pause");
            break;
        case STUDENT_MANAGEMENT_ADD_STUDENT:
            add_student();
            system("pause");
            break;
        case STUDENT_MANAGEMENT_MODIFY_STUDENT:
            modify_student();
            system("pause");
            break;
        case STUDENT_MANAGEMENT_DELETE_STUDENT:
            delete_student();
            system("pause");
            break;
        case STUDENT_MANAGEMENT_RETURN:
            return;
        default:
            printf("�L�Ŀﶵ�A�Э��s��J\n");
            system("pause");
            break;
        }
    }
}