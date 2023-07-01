#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataFormat.h" // 調用教務管理系統數據格式頭文件
#include "DataStorage.h" // 調用用戶數據頭文件

void query_student_teachers_info() {
    int user_index = -1; // 初始化找到的用戶下標為-1
    // 在用戶數組中查找當前用戶的下標
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, current_username) == 0) {
            user_index = i;
            break;
        }
    }
    if (user_index != -1 && users[user_index].role == 3) { // 當前用戶為學生
        char teacher_id[20]; // 教師編號
        printf("\n請輸入教師編號：");
        scanf("%s", teacher_id);
        int selection_index = -1; // 初始化找到的選課下標為-1
        // 在選課信息數組中查找該學生對應的選課信息的下標
        for (int i = 0; i < selection_count; i++) {
            if (strcmp(selections[i].student.student_id, users[user_index].user_id) == 0) {
                // 在該選課信息中查找該教師是否授課
                for (int j = 0; j < teaching_count; j++) {
                    if (strcmp(teachings[j].course.course_id, selections[i].course.course_id) == 0 && strcmp(teachings[j].teacher.teacher_id, teacher_id) == 0) {
                        selection_index = i;
                        break;
                    }
                }
            }
            if (selection_index != -1) {
                break;
            }
        }
        if (selection_index != -1) { // 找到選課信息
            // 遍歷選課信息數組，打印該教師已授的該學生的所有課程信息
            for (int i = 0; i < teaching_count; i++) {
                if (strcmp(teachings[i].teacher.teacher_id, teacher_id) == 0 && strcmp(teachings[i].course.course_id, selections[selection_index].course.course_id) == 0) {
                    // 輸出該授課信息對應的課程信息
                    printf("課程編號：%s\n", teachings[i].course.course_id);
                    printf("課程名稱：%s\n", teachings[i].course.name);
                    printf("課程性質：%s\n", teachings[i].course.nature);
                    printf("課程學時：%d\n", teachings[i].course.hours);
                    printf("課程學分：%f\n", teachings[i].course.credit);
                    printf("開課學期：%s\n", teachings[i].course.term);
                    printf("教師編號：%s\n", teachings[i].teacher.teacher_id);
                    printf("教師姓名：%s\n", teachings[i].teacher.name);
                    printf("教師性別：%s\n", teachings[i].teacher.gender);
                    printf("教師學歷：%s\n", teachings[i].teacher.education);
                    printf("教師職稱：%s\n", teachings[i].teacher.title);
                    printf("\n");
                }
            }
        }
        else {
            printf("該教師未教授您的課程\n");
        }
    }
    else {
        printf("\n用戶不存在或不是學生\n");
    }
}