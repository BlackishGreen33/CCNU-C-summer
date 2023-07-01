#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataFormat.h" // �եαаȺ޲z�t�μƾڮ榡�Y���
#include "DataStorage.h" // �եΥΤ�ƾ��Y���

void query_teacher_teaching_info() {
    int user_index = -1; // ��l�Ƨ�쪺�Τ�U�Ь�-1
    // �b�Τ�Ʋդ��d���e�Τ᪺�U��
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, current_username) == 0) {
            user_index = i;
            break;
        }
    }
    if (user_index != -1 && users[user_index].role == 2) { // ��e�Τᬰ�Юv
        int teacher_index = -1; // ��l�Ƨ�쪺�Юv�U�Ь�-1
        // �b�Юv�Ʋդ��d���e�Юv���U��
        for (int i = 0; i < teacher_count; i++) {
            if (strcmp(teachers[i].teacher_id, users[user_index].user_id) == 0) {
                teacher_index = i;
                break;
            }
        }
        if (teacher_index != -1) { // ���Юv
            printf("\n%s�½ҫH���G\n", teachers[teacher_index].name);
            printf("================================\n");
            printf("�½�ID\t�ҵ{�s��\t�ҵ{�W��\t���ұЮv\n");
            // �M���½ҫH���ƲաA���L�ӱЮv���Ҧ��½ҫH��
            for (int i = 0; i < teaching_count; i++) {
                if (strcmp(teachings[i].teacher.teacher_id, teachers[teacher_index].teacher_id) == 0) {
                    printf("%d\t%s\t%s\t%s\n", teachings[i].teach_id, teachings[i].course.course_id, teachings[i].course.name, teachings[i].teacher.name);
                }
            }
        }
        else {
            printf("�Τᤣ�s�b�Τ��O�Юv\n");
        }
    }
    else {
        printf("\n�Τᤣ�s�b�Τ��O�Юv\n");
    }
}