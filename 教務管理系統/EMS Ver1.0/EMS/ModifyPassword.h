#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataFormat.h" // 調用教務管理系統數據格式頭文件
#include "DataStorage.h" // 調用用戶數據頭文件

void modify_password() {
    char new_password[20];
    printf("\n請輸入新密碼：");
    scanf("%s", new_password);
    int index = -1; // 初始化找到的用戶下標為-1
    // 在用戶數組中查找當前用戶的下標
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, current_username) == 0) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        // 找到用戶並修改密碼
        strcpy(users[index].password, new_password);
        printf("密碼修改成功\n");

        // 文件讀寫
        write_user();
        read_user();
    }
    else {
        printf("用戶不存在\n");
    }
}