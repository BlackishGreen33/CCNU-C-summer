#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataFormat.h" // 調用教務管理系統數據格式頭文件
#include "DataStorage.h" // 調用用戶數據頭文件

void query_user_info() {
    int index = -1; // 初始化找到的用戶下標為-1
    // 在用戶數組中查找當前用戶的下標
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, current_username) == 0) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        // 找到用戶並打印用戶信息
        printf("\n用戶ID：%s\n", users[index].user_id);
        printf("用戶名：%s\n", users[index].username);
        printf("用戶密碼：%s\n", users[index].password);
        printf("用戶權限：%d\n", users[index].role);
    }
    else {
        printf("\n用戶不存在\n");
    }
}