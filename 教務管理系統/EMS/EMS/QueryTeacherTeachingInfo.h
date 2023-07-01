#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataFormat.h" // 調用教務管理系統數據格式頭文件
#include "DataStorage.h" // 調用用戶數據頭文件

void query_teacher_teaching_info() {
    int user_index = -1; // 初始化找到的用戶下標為-1
    // 在用戶數組中查找當前用戶的下標
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, current_username) == 0) {
            user_index = i;
            break;
        }
    }
    if (user_index != -1 && users[user_index].role == 2) { // 當前用戶為教師
        int teacher_index = -1; // 初始化找到的教師下標為-1
        // 在教師數組中查找當前教師的下標
        for (int i = 0; i < teacher_count; i++) {
            if (strcmp(teachers[i].teacher_id, users[user_index].user_id) == 0) {
                teacher_index = i;
                break;
            }
        }
        if (teacher_index != -1) { // 找到教師
            printf("\n%s授課信息：\n", teachers[teacher_index].name);
            printf("================================\n");
            printf("授課ID\t課程編號\t課程名稱\t任課教師\n");
            // 遍歷授課信息數組，打印該教師的所有授課信息
            for (int i = 0; i < teaching_count; i++) {
                if (strcmp(teachings[i].teacher.teacher_id, teachers[teacher_index].teacher_id) == 0) {
                    printf("%d\t%s\t%s\t%s\n", teachings[i].teach_id, teachings[i].course.course_id, teachings[i].course.name, teachings[i].teacher.name);
                }
            }
        }
        else {
            printf("用戶不存在或不是教師\n");
        }
    }
    else {
        printf("\n用戶不存在或不是教師\n");
    }
}