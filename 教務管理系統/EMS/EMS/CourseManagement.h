#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataFormat.h" // 調用教務管理系統數據格式頭文件
#include "DataStorage.h" // 調用用戶數據頭文件

// 課程管理菜單選項
enum CourseManagementOption {
    COURSE_MANAGEMENT_QUERY_ALL_COURSES = 1,
    COURSE_MANAGEMENT_ADD_COURSE,
    COURSE_MANAGEMENT_MODIFY_COURSE,
    COURSE_MANAGEMENT_DELETE_COURSE,
    COURSE_MANAGEMENT_RETURN
};

// 課程管理菜單
void course_management_menu() {
    printf("課程管理\n");
    printf("1. 查詢所有課程信息\n");
    printf("2. 新增課程\n");
    printf("3. 修改課程信息\n");
    printf("4. 刪除課程\n");
    printf("5. 返回\n");
    printf("請選擇操作：");
}

// 查詢所有課程信息
void query_all_courses() {
    printf("所有課程信息如下：\n");
    printf("課程編號\t課程名稱\t課程性質\t課程學時\t課程學分\t開課學期\n");
    for (int i = 0; i < course_count; i++) {
        printf("%s\t%s\t%s\t%d\t%.1f\t%s\n", courses[i].course_id, courses[i].name, courses[i].nature, courses[i].hours, courses[i].credit, courses[i].term);
    }
}

// 新增課程
void add_course() {
    Course course;
    printf("請輸入新課程信息：\n");
    printf("課程編號：");
    scanf("%s", course.course_id);
    printf("課程名稱：");
    scanf("%s", course.name);
    printf("課程性質：");
    scanf("%s", course.nature);
    printf("課程學時：");
    scanf("%d", &course.hours);
    printf("課程學分：");
    scanf("%f", &course.credit);
    printf("開課學期：");
    scanf("%s", course.term);
    course.is_teaching = 0;
    course.is_selected = 0;
    courses[course_count++] = course;
    printf("添加成功！\n");
}

// 修改課程信息
void modify_course() {
    char course_id[20];
    printf("請輸入要修改的課程編號：");
    scanf("%s", course_id);
    int index = -1;
    for (int i = 0; i < course_count; i++) {
        if (strcmp(courses[i].course_id, course_id) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("未找到該課程\n");
    }
    else if (courses[index].is_teaching || courses[index].is_selected) {
        printf("該課程正在被講授或者學生選修，無法修改\n");
    }
    else {
        printf("請輸入新的課程名稱：");
        scanf("%s", courses[index].name);
        printf("請輸入新的課程性質：");
        scanf("%s", courses[index].nature);
        printf("請輸入新的課程學時：");
        scanf("%d", &courses[index].hours);
        printf("請輸入新的課程學分：");
        scanf("%f", &courses[index].credit);
        printf("請輸入新的開課學期：");
        scanf("%s", courses[index].term);
        printf("修改成功！\n");
    }
}

// 刪除課程
void delete_course() {
    char course_id[20];
    printf("請輸入要刪除的課程編號：");
    scanf("%s", course_id);
    int index = -1;
    for (int i = 0; i < course_count; i++) {
        if (strcmp(courses[i].course_id, course_id) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("未找到該課程\n");
    }
    else if (courses[index].is_teaching || courses[index].is_selected) {
        printf("該課程正在被講授或者學生選修，無法刪除\n");
    }
    else {
        for (int i = index; i < course_count - 1; i++) {
            courses[i] = courses[i + 1];
        }
        course_count--;
        printf("刪除成功！\n");
    }
}

// 課程管理
void course_management() {
    while (1) {
        course_management_menu();
        int option;
        printf("請選擇操作：");
        scanf("%d", &option);
        switch (option) {
        case COURSE_MANAGEMENT_QUERY_ALL_COURSES:
            query_all_courses();
            break;
        case COURSE_MANAGEMENT_ADD_COURSE:
            add_course();
            break;
        case COURSE_MANAGEMENT_MODIFY_COURSE:
            modify_course();
            break;
        case COURSE_MANAGEMENT_DELETE_COURSE:
            delete_course();
            break;
        case COURSE_MANAGEMENT_RETURN:
            return;
        default:
            printf("無效的選項，請重新選擇\n");
            break;
        }
    }
}