#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataFormat.h" // �եαаȺ޲z�t�μƾڮ榡�Y���
#include "DataStorage.h" // �եΥΤ�ƾ��Y���

void query_user_info() {
    int index = -1; // ��l�Ƨ�쪺�Τ�U�Ь�-1
    // �b�Τ�Ʋդ��d���e�Τ᪺�U��
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, current_username) == 0) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        // ���Τ�å��L�Τ�H��
        printf("\n�Τ�ID�G%s\n", users[index].user_id);
        printf("�Τ�W�G%s\n", users[index].username);
        printf("�Τ�K�X�G%s\n", users[index].password);
        printf("�Τ��v���G%d\n", users[index].role);
    }
    else {
        printf("\n�Τᤣ�s�b\n");
    }
}