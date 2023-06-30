#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataFormat.h" // �եαаȺ޲z�t�μƾڮ榡�Y���
#include "DataStorage.h" // �եΥΤ�ƾ��Y���

void query_student_teachers_info() {
    int user_index = -1; // ��l�Ƨ�쪺�Τ�U�Ь�-1
    // �b�Τ�Ʋդ��d���e�Τ᪺�U��
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, current_username) == 0) {
            user_index = i;
            break;
        }
    }
    if (user_index != -1 && users[user_index].role == 3) { // ��e�Τᬰ�ǥ�
        char teacher_id[20]; // �Юv�s��
        printf("�п�J�Юv�s���G");
        scanf("%s", teacher_id);
        int selection_index = -1; // ��l�Ƨ�쪺��ҤU�Ь�-1
        // �b��ҫH���Ʋդ��d��Ӿǥ͹�������ҫH�����U��
        for (int i = 0; i < selection_count; i++) {
            if (strcmp(selections[i].student.student_id, users[user_index].user_id) == 0) {
                // �b�ӿ�ҫH�����d��ӱЮv�O�_�½�
                for (int j = 0; j < teaching_count; j++) {
                    if (strcmp(teachings[j].course.course_id, selections[i].course.course_id) == 0 && strcmp(teachings[j].teacher.teacher_id, teacher_id) == 0) {
                        selection_index = i;
                        break;
                    }
                }
            }
            if (selection_index != -1) {
                break;
            }
        }
        if (selection_index != -1) { // ����ҫH��
            // �M����ҫH���ƲաA���L�ӱЮv�w�ª��Ӿǥͪ��Ҧ��ҵ{�H��
            for (int i = 0; i < teaching_count; i++) {
                if (strcmp(teachings[i].teacher.teacher_id, teacher_id) == 0 && strcmp(teachings[i].course.course_id, selections[selection_index].course.course_id) == 0) {
                    // ��X�ӱ½ҫH���������ҵ{�H��
                    printf("�ҵ{�s���G%s\n", teachings[i].course.course_id);
                    printf("�ҵ{�W�١G%s\n", teachings[i].course.name);
                    printf("�ҵ{�ʽ�G%s\n", teachings[i].course.nature);
                    printf("�ҵ{�ǮɡG%d\n", teachings[i].course.hours);
                    printf("�ҵ{�Ǥ��G%f\n", teachings[i].course.credit);
                    printf("�}�ҾǴ��G%s\n", teachings[i].course.term);
                    printf("�Юv�s���G%s\n", teachings[i].teacher.teacher_id);
                    printf("�Юv�m�W�G%s\n", teachings[i].teacher.name);
                    printf("�Юv�ʧO�G%s\n", teachings[i].teacher.gender);
                    printf("�Юv�Ǿ��G%s\n", teachings[i].teacher.education);
                    printf("�Юv¾�١G%s\n", teachings[i].teacher.title);
                    printf("\n");
                }
            }
        }
        else {
            printf("�ӱЮv���б±z���ҵ{\n");
        }
    }
    else {
        printf("�Τᤣ�s�b�Τ��O�ǥ�\n");
    }
}