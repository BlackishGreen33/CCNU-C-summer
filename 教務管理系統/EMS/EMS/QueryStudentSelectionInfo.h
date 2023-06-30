#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataFormat.h" // 調用教務管理系統數據格式頭文件
#include "DataStorage.h" // 調用用戶數據頭文件

void query_student_selection_info() {
    int user_index = -1; // 初始化找到的用戶下標為-1
    // 在用戶數組中查找當前用戶的下標
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, current_username) == 0) {
            user_index = i;
            break;
        }
    }
    if (user_index != -1 && users[user_index].role == 3) { // 當前用戶為學生
        int student_index = -1; // 初始化找到的學生下標為-1
        // 在學生數組中查找當前學生的下標
        for (int i = 0; i < student_count; i++) {
            if (strcmp(students[i].student_id, users[user_index].user_id) == 0) {
                student_index = i;
                break;
            }
        }
        if (student_index != -1) { // 找到學生
            printf("%s課程信息：\n", students[student_index].name);
            // 遍歷授課信息數組，打印該教師的所有授課信息
            for (int i = 0; i < selection_count; i++) {
                if (strcmp(selections[i].student.student_id, students[student_index].student_id) == 0) {
                    printf("選課ID：%d\n", selections[i].select_id);
                    printf("課程編號：%s\n", selections[i].course.course_id);
                    printf("課程名稱：%s\n", selections[i].course.name);
                    printf("課程性質：%s\n", selections[i].course.nature);
                    printf("課程學時：%d\n", selections[i].course.hours);
                    printf("課程學分：%f\n", selections[i].course.credit);
                    printf("開課學期：%s\n", selections[i].course.term);
                    printf("學生編號：%s\n", selections[i].student.student_id);
                    printf("學生姓名：%s\n", selections[i].student.name);
                    printf("學生性別：%s\n", selections[i].student.gender);
                    printf("學生班級：%s\n", selections[i].student.classroom);
                    printf("成績：%f\n", selections[i].score);
                    printf("\n");
                }
            }
        }
        else {
            printf("用戶不存在或不是學生\n");
        }
    }
    else {
        printf("用戶不存在或不是學生\n");
    }
}