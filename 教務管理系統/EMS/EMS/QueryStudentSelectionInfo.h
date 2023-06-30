#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataFormat.h" // �եαаȺ޲z�t�μƾڮ榡�Y���
#include "DataStorage.h" // �եΥΤ�ƾ��Y���

void query_student_selection_info() {
    int user_index = -1; // ��l�Ƨ�쪺�Τ�U�Ь�-1
    // �b�Τ�Ʋդ��d���e�Τ᪺�U��
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, current_username) == 0) {
            user_index = i;
            break;
        }
    }
    if (user_index != -1 && users[user_index].role == 3) { // ��e�Τᬰ�ǥ�
        int student_index = -1; // ��l�Ƨ�쪺�ǥͤU�Ь�-1
        // �b�ǥͼƲդ��d���e�ǥͪ��U��
        for (int i = 0; i < student_count; i++) {
            if (strcmp(students[i].student_id, users[user_index].user_id) == 0) {
                student_index = i;
                break;
            }
        }
        if (student_index != -1) { // ���ǥ�
            printf("%s�ҵ{�H���G\n", students[student_index].name);
            // �M���½ҫH���ƲաA���L�ӱЮv���Ҧ��½ҫH��
            for (int i = 0; i < selection_count; i++) {
                if (strcmp(selections[i].student.student_id, students[student_index].student_id) == 0) {
                    printf("���ID�G%d\n", selections[i].select_id);
                    printf("�ҵ{�s���G%s\n", selections[i].course.course_id);
                    printf("�ҵ{�W�١G%s\n", selections[i].course.name);
                    printf("�ҵ{�ʽ�G%s\n", selections[i].course.nature);
                    printf("�ҵ{�ǮɡG%d\n", selections[i].course.hours);
                    printf("�ҵ{�Ǥ��G%f\n", selections[i].course.credit);
                    printf("�}�ҾǴ��G%s\n", selections[i].course.term);
                    printf("�ǥͽs���G%s\n", selections[i].student.student_id);
                    printf("�ǥͩm�W�G%s\n", selections[i].student.name);
                    printf("�ǥͩʧO�G%s\n", selections[i].student.gender);
                    printf("�ǥͯZ�šG%s\n", selections[i].student.classroom);
                    printf("���Z�G%f\n", selections[i].score);
                    printf("\n");
                }
            }
        }
        else {
            printf("�Τᤣ�s�b�Τ��O�ǥ�\n");
        }
    }
    else {
        printf("�Τᤣ�s�b�Τ��O�ǥ�\n");
    }
}