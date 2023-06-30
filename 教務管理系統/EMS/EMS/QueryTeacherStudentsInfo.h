#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataFormat.h" // �եαаȺ޲z�t�μƾڮ榡�Y���
#include "DataStorage.h" // �եΥΤ�ƾ��Y���

void query_teacher_students_info() {
    int user_index = -1; // ��l�Ƨ�쪺�Τ�U�Ь�-1
    // �b�Τ�Ʋդ��d���e�Τ᪺�U��
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, current_username) == 0) {
            user_index = i;
            break;
        }
    }
    if (user_index != -1 && users[user_index].role == 2) { // ��e�Τᬰ�Юv
        char student_id[20]; // �ǥͽs��
        printf("�п�J�ǥͽs���G");
        scanf("%s", student_id);
        int teaching_index = -1; // ��l�Ƨ�쪺�½ҤU�Ь�-1
        // �b�½ҫH���Ʋդ��d��ӱЮv�������½ҫH�����U��
        for (int i = 0; i < teaching_count; i++) {
            if (strcmp(teachings[i].teacher.teacher_id, users[user_index].user_id) == 0) {
                // �b�ӱ½ҫH�����d��ӾǥͬO�_���
                for (int j = 0; j < selection_count; j++) {
                    if (strcmp(selections[j].course.course_id, teachings[i].course.course_id) == 0 && strcmp(selections[j].student.student_id, student_id) == 0) {
                        teaching_index = i;
                        break;
                    }
                }
            }
            if (teaching_index != -1) {
                break;
            }
        }
        if (teaching_index != -1) { // ���½ҫH��
            printf("�ǥ�%s��ܪ��ҵ{�G\n", student_id);
            printf("�ҵ{�s��\t�ҵ{�W��\t�ҵ{�ʽ�\t�Ǯ�\t�Ǥ�\t�}�ҾǴ�\t�O�_���b����\t�O�_�Q���\n");
            // �M����ҫH���ƲաA���L�Ӿǥͤw�諸�ӱЮv���Ҧ��ҵ{�H��
            for (int i = 0; i < selection_count; i++) {
                if (strcmp(selections[i].student.student_id, student_id) == 0 && strcmp(selections[i].course.course_id, teachings[teaching_index].course.course_id) == 0) {
                    printf("%s\t%s\t%s\t%d\t%.1f\t%s\t%s\t%s\n", selections[i].course.course_id, selections[i].course.name, selections[i].course.nature, selections[i].course.hours, selections[i].course.credit, selections[i].course.term, selections[i].course.is_teaching == 1 ? "�O" : "�_", selections[i].course.is_selected == 1 ? "�O" : "�_");
                }
            }
        }
        else {
            printf("�Ӿǥͥ���ױz���ҵ{\n");
        }
    }
    else {
        printf("�Τᤣ�s�b�Τ��O�Юv\n");
    }
}