#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataFormat.h" // 調用教務管理系統數據格式頭文件
#include "DataStorage.h" // 調用用戶數據頭文件

void student_query_selection() {
    // 遍歷所有選課信息，找到is_selected為0的選課信息
    for (int i = 0; i < selection_count; i++) {
        if (selections[i].course.is_selected == 0) {
            // 輸出該選課信息對應的選課ID和課程信息
            printf("\n選課ID：%d\n", selections[i].select_id);
            printf("課程編號：%s\n", selections[i].course.course_id);
            printf("課程名稱：%s\n", selections[i].course.name);
            printf("課程性質：%s\n", selections[i].course.nature);
            printf("課程學時：%d\n", selections[i].course.hours);
            printf("課程學分：%f\n", selections[i].course.credit);
            printf("開課學期：%s\n", selections[i].course.term);
            printf("\n");
        }
    }
}