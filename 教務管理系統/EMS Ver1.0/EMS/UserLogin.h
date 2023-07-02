#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include "DataFormat.h" // 調用教務管理系統數據格式頭文件
#include "DataStorage.h" // 調用用戶數據頭文件

int check_user(char* username, char* password) {
    int i;
    for (i = 0; i < user_count; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            return users[i].role; // 返回用戶權限
        }
    }
    return 0; // 返回0表示帳號或密碼錯誤
}

int user_login() {
    int i, role, count = 0;
    time_t start_time = 0, now_time = 0;

    // 輸入帳號密碼
    printf("請輸入帳號：");
    scanf("%s", current_username);
    printf("請輸入密碼：");
    scanf("%s", current_password);

    // 判斷帳號密碼是否正確，錯誤3次則鎖定5分鐘
    while ((role = check_user(current_username, current_password)) == 0) {
        count++;
        if (count == 3) {
            start_time = time(NULL);
            printf("帳號或密碼錯誤3次，已鎖定5分鐘，請稍後再試。\n");
            break;
        }
        printf("帳號或密碼錯誤，請重新輸入：\n");
        printf("請輸入帳號：");
        scanf("%s", current_username);
        printf("請輸入密碼：");
        scanf("%s", current_password);
    }

    // 判斷是否鎖定
    if (start_time > 0) {
        while ((now_time = time(NULL)) - start_time < 300) { // 5分鐘
            printf("帳號已鎖定，請等待 %ld 秒後再試。\n", start_time + 300 - now_time);
            Sleep(1);
        }
    }

    return role;
}