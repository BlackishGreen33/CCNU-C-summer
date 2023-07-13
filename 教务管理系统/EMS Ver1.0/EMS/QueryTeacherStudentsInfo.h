#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataFormat.h" // 調用教務管理系統數據格式頭文件
#include "DataStorage.h" // 調用用戶數據頭文件

void query_teacher_students_info() {
    int user_index = -1; // 初始化找到的用戶下標為-1
    // 在用戶數組中查找當前用戶的下標
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, current_username) == 0) {
            user_index = i;
            break;
        }
    }
    if (user_index != -1 && users[user_index].role == 2) { // 當前用戶為教師
        char student_id[20]; // 學生編號
        printf("\n請輸入學生編號：");
        scanf("%s", student_id);
        int teaching_index = -1; // 初始化找到的授課下標為-1
        // 在授課信息數組中查找該教師對應的授課信息的下標
        for (int i = 0; i < teaching_count; i++) {
            if (strcmp(teachings[i].teacher.teacher_id, users[user_index].user_id) == 0) {
                // 在該授課信息中查找該學生是否選課
                for (int j = 0; j < selection_count; j++) {
                    if (strcmp(selections[j].course.course_id, teachings[i].course.course_id) == 0 && strcmp(selections[j].student.student_id, student_id) == 0) {
                        teaching_index = i;
                        break;
                    }
                }
            }
            if (teaching_index != -1) {
                break;
            }
        }
        if (teaching_index != -1) { // 找到授課信息
            printf("學生%s選擇的課程：\n", student_id);
            printf("================================\n");
            printf("課程編號\t課程名稱\t課程性質\t學時\t學分\t開課學期\t是否正在講授\t是否被選修\n");
            // 遍歷選課信息數組，打印該學生已選的該教師的所有課程信息
            for (int i = 0; i < selection_count; i++) {
                if (strcmp(selections[i].student.student_id, student_id) == 0 && strcmp(selections[i].course.course_id, teachings[teaching_index].course.course_id) == 0) {
                    printf("%s\t%s\t%s\t%d\t%.1f\t%s\t%s\t%s\n", selections[i].course.course_id, selections[i].course.name, selections[i].course.nature, selections[i].course.hours, selections[i].course.credit, selections[i].course.term, selections[i].course.is_teaching == 1 ? "是" : "否", selections[i].course.is_selected == 1 ? "是" : "否");
                }
            }
        }
        else {
            printf("\n該學生未選修您的課程\n");
        }
    }
    else {
        printf("用戶不存在或不是教師\n");
    }
}