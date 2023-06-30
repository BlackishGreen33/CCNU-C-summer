#pragma once
#include "DataFormat.h"

char current_username[20], current_password[20];

// �Τ�ƾ�
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

// �Юv�H��
Teacher teachers[] = {
    {"T001", "�i�T", "�k", "�Ӥh", "���v"},
    {"T002", "���|", "�k", "�դh", "�Ʊб�"},
    {"T003", "����", "�k", "�Ǥh", "�U�z�б�"}
};
int teacher_count = sizeof(teachers) / sizeof(teachers[0]);

// �ǥͫH��
Student students[] = {
    {"S001", "�p��", "�k", "1�Z"},
    {"S002", "�p��", "�k", "2�Z"},
    {"S003", "�p��", "�k", "1�Z"}
};
int student_count = sizeof(students) / sizeof(students[0]);

// �ҵ{�H��
Course courses[] = {
    {"C001", "�����ƾ�", "����", 64, 4, "2022-2023��u�Ǵ�", 0, 0},
    {"C002", "�^�y", "����", 96, 6, "2022-2023��u�Ǵ�", 0, 0},
    {"C003", "�ƾڵ��c", "���", 48, 3, "2022-2023�K�u�Ǵ�", 0, 0}
};
int course_count = sizeof(courses) / sizeof(courses[0]);

// �½ҫH��
Teaching teachings[] = {
    {1, courses[0], teachers[0]},
    {2, courses[1], teachers[1]},
    {3, courses[2], teachers[2]}
};
int teaching_count = sizeof(teachings) / sizeof(teachings[0]);

// ��ҫH��
Selection selections[] = {
    {1, courses[0], students[0], 85},
    {2, courses[1], students[1], 92},
    {3, courses[2], students[2], 78}
};
int selection_count = sizeof(selections) / sizeof(selections[0]);