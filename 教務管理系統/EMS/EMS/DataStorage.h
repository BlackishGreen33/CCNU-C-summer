#pragma once
#include "DataFormat.h"

char current_username[20], current_password[20];

// 用戶數據
User users[] = {
    {"jw0001", "jw0001", "admin001", 1},
    {"T001", "teacher001", "123456", 2},
    {"T002", "teacher002", "123456", 2},
    {"T003", "teacher003", "123456", 2},
    {"S001", "2022214001", "214001", 3},
    {"S002", "2022214002", "214002", 3},
    {"S003", "2022214003", "214003", 3},
};
int user_count = sizeof(users) / sizeof(users[0]);

// 教師信息
Teacher teachers[] = {
    {"T001", "張三", "男", "碩士", "講師"},
    {"T002", "李四", "女", "博士", "副教授"},
    {"T003", "王五", "男", "學士", "助理教授"}
};
int teacher_count = sizeof(teachers) / sizeof(teachers[0]);

// 學生信息
Student students[] = {
    {"S001", "小明", "男", "1班"},
    {"S002", "小紅", "女", "2班"},
    {"S003", "小剛", "男", "1班"}
};
int student_count = sizeof(students) / sizeof(students[0]);

// 課程信息
Course courses[] = {
    {"C001", "高等數學", "必修", 64, 4, "2022-2023秋季學期", 0, 0},
    {"C002", "英語", "必修", 96, 6, "2022-2023秋季學期", 0, 0},
    {"C003", "數據結構", "選修", 48, 3, "2022-2023春季學期", 0, 0}
};
int course_count = sizeof(courses) / sizeof(courses[0]);

// 授課信息
Teaching teachings[] = {
    {1, courses[0], teachers[0]},
    {2, courses[1], teachers[1]},
    {3, courses[2], teachers[2]}
};
int teaching_count = sizeof(teachings) / sizeof(teachings[0]);

// 選課信息
Selection selections[] = {
    {1, courses[0], students[0], 85},
    {2, courses[1], students[1], 92},
    {3, courses[2], students[2], 78}
};
int selection_count = sizeof(selections) / sizeof(selections[0]);