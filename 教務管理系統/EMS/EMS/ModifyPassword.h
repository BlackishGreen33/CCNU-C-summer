#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataFormat.h" // �եαаȺ޲z�t�μƾڮ榡�Y���
#include "DataStorage.h" // �եΥΤ�ƾ��Y���

void modify_password() {
    char new_password[20];
    printf("�п�J�s�K�X�G");
    scanf("%s", new_password);
    int index = -1; // ��l�Ƨ�쪺�Τ�U�Ь�-1
    // �b�Τ�Ʋդ��d���e�Τ᪺�U��
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, current_username) == 0) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        // ���Τ�íק�K�X
        strcpy(users[index].password, new_password);
        printf("�K�X�ק令�\\n");
    }
    else {
        printf("�Τᤣ�s�b\n");
    }
}