#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataFormat.h" // �եαаȺ޲z�t�μƾڮ榡�Y���
#include "DataStorage.h" // �եΥΤ�ƾ��Y���

void student_query_selection() {
    // �M���Ҧ���ҫH���A���is_selected��0����ҫH��
    for (int i = 0; i < selection_count; i++) {
        if (selections[i].course.is_selected == 0) {
            // ��X�ӿ�ҫH�����������ID�M�ҵ{�H��
            printf("\n���ID�G%d\n", selections[i].select_id);
            printf("�ҵ{�s���G%s\n", selections[i].course.course_id);
            printf("�ҵ{�W�١G%s\n", selections[i].course.name);
            printf("�ҵ{�ʽ�G%s\n", selections[i].course.nature);
            printf("�ҵ{�ǮɡG%d\n", selections[i].course.hours);
            printf("�ҵ{�Ǥ��G%f\n", selections[i].course.credit);
            printf("�}�ҾǴ��G%s\n", selections[i].course.term);
            printf("\n");
        }
    }
}