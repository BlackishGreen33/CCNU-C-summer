#pragma once
#include "DataFormat.h"

char current_username[20], current_password[20];

// 用戶數據
User users[200] = {
    /*{"jw0001", "jw0001", "admin001", 1},
    {"T001", "teacher001", "123456", 2},
    {"T002", "teacher002", "123456", 2},
    {"T003", "teacher003", "123456", 2},
    {"S001", "2022214001", "214001", 3},
    {"S002", "2022214002", "214002", 3},
    {"S003", "2022214003", "214003", 3},*/
};
int user_count = 0;

// 教師信息
Teacher teachers[50] = {
    //{"T001", "張三", "男", "碩士", "講師"},
    //{"T002", "李四", "女", "博士", "副教授"},
    //{"T003", "王五", "男", "學士", "助理教授"}
};
int teacher_count = 0;

// 學生信息
Student students[50] = {
    /*{"S001", "小明", "男", "1班"},
    {"S002", "小紅", "女", "2班"},
    {"S003", "小剛", "男", "1班"}*/
};
int student_count = 0;

// 課程信息
Course courses[100] = {
    /*{"C001", "高等數學", "必修", 64, 4, "2022-2023秋季學期", 0, 0},
    {"C002", "英語", "必修", 96, 6, "2022-2023秋季學期", 0, 0},
    {"C003", "數據結構", "選修", 48, 3, "2022-2023春季學期", 0, 0}*/
};
int course_count = 0;

// 授課信息
Teaching teachings[100] = {
    /*{1, courses[0], teachers[0]},
    {2, courses[1], teachers[1]},
    {3, courses[2], teachers[2]}*/
};
int teaching_count = 0;

// 選課信息
Selection selections[100] = {
    /*{1, courses[0], students[0], 85},
    {2, courses[1], students[1], 92},
    {3, courses[2], students[2], 78}*/
};
int selection_count = 0;

//读取用户信息
void read_user() {
    // 用戶數據
    FILE* fpr = fopen("user.txt", "r");//以只写的形式打开文本文件
    int count = 0;
    while (fscanf(fpr, "%s %s %s %d", users[count].user_id, users[count].username, users[count].password, &users[count].role) != EOF) {
        count++;
    }
    user_count = count;
    fclose(fpr);//关闭文件指针
}

//读取教师信息
void read_teacher() {
    // 教師信息
    FILE * fpr = fopen("teacher.txt", "r");
    int count = 0;
    while (fscanf(fpr, "%s %s %s %s %s", teachers[count].teacher_id, teachers[count].name, teachers[count].gender, teachers[count].education, teachers[count].title) != EOF) {
        count++;
    }
    teacher_count = count;
    fclose(fpr);
}

//读取学生信息
void read_student() {
    // 學生信息
    FILE * fpr = fopen("student.txt", "r");
    int count = 0;
    while (fscanf(fpr, "%s %s %s %s", students[count].student_id, students[count].name, students[count].gender, students[count].classroom) != EOF) {
        count++;
    }
    student_count = count;
    fclose(fpr);
}

//读取课程信息
void read_course() {
    // 課程信息
    FILE * fpr = fopen("course.txt", "r");
    int count = 0;
    while (fscanf(fpr, "%s %s %s %d %f %s %d %d", courses[count].course_id, courses[count].name, courses[count].nature, &courses[count].hours, &courses[count].credit, courses[count].term, &courses[count].is_teaching, &courses[count].is_selected) != EOF) {
        count++;
    }
    course_count = count;
    fclose(fpr);
}

//读取授课信息
void read_teaching() {
    // 授课信息
    FILE* fpr = fopen("teaching.txt", "r");
    int count = 0;
    while (fscanf(fpr, "%d %s %s %s %d %f %s %d %d %s %s %s %s %s", &teachings[count].teach_id, 
    teachings[count].course.course_id, teachings[count].course.name, 
    teachings[count].course.nature, &teachings[count].course.hours, 
    &teachings[count].course.credit, teachings[count].course.term, 
    &teachings[count].course.is_teaching, &teachings[count].course.is_selected,
    teachings[count].teacher.teacher_id, teachings[count].teacher.name, 
    teachings[count].teacher.gender, teachings[count].teacher.education, 
    teachings[count].teacher.title) != EOF) {
        count++;
    }
    teaching_count = count;
    fclose(fpr);
}

//读取选课信息
void read_selection() {
    //选课信息
    FILE* fpr = fopen("selection.txt", "r");
    int count = 0;
    while (fscanf(fpr, "%d %s %s %s %d %f %s %d %d %s %s %s %s %f", &selections[count].select_id,
        selections[count].course.course_id, selections[count].course.name,
        selections[count].course.nature, &selections[count].course.hours,
        &selections[count].course.credit, selections[count].course.term,
        &selections[count].course.is_teaching, &selections[count].course.is_selected,
        selections[count].student.student_id, selections[count].student.name, 
        selections[count].student.gender, selections[count].student.classroom, &selections[count].score) != EOF) {
        count++;
    }
    selection_count = count;
    fclose(fpr);
}

//写入用户信息
void write_user() {
    FILE* fpw = fopen("user.txt", "w");
    for (int i = 0; i < user_count; i++) {
        fprintf(fpw, "%s %s %s %d\n", users[i].user_id, users[i].username, users[i].password, users[i].role);
    }
    fclose(fpw);//关闭文件指针
}

//写入教师信息
void write_teacher() {
    FILE* fpw = fopen("teacher.txt", "w");
    for (int i = 0; i < teacher_count; i++) {
        fprintf(fpw, "%s %s %s %s %s\n", teachers[i].teacher_id, teachers[i].name, teachers[i].gender, teachers[i].education, teachers[i].title);
    }
    fclose(fpw);//关闭文件指针
}

//写入学生信息
void write_student() {
    FILE* fpw = fopen("student.txt", "w");
    for (int i = 0; i < student_count; i++) {
        fprintf(fpw, "%s %s %s %s\n", students[i].student_id, students[i].name, students[i].gender, students[i].classroom);
    }
    fclose(fpw);//关闭文件指针
}

//写入课程信息
void write_course() {
    FILE* fpw = fopen("course.txt", "w");
    for (int i = 0; i < course_count; i++) {
        fprintf(fpw, "%s %s %s %d %f %s %d %d\n", courses[i].course_id, courses[i].name, courses[i].nature, courses[i].hours, courses[i].credit, courses[i].term, courses[i].is_teaching, courses[i].is_selected);
    }
    fclose(fpw);//关闭文件指针
}

//写入授课信息
void write_teaching() {
    FILE* fpw = fopen("teaching.txt", "w");
    for (int i = 0; i < teaching_count; i++) {
        fprintf(fpw, "%d %s %s %s %d %f %s %d %d %s %s %s %s %s\n", teachings[i].teach_id,
            teachings[i].course.course_id, teachings[i].course.name,
            teachings[i].course.nature, teachings[i].course.hours,
            teachings[i].course.credit, teachings[i].course.term,
            teachings[i].course.is_teaching, teachings[i].course.is_selected,
            teachings[i].teacher.teacher_id, teachings[i].teacher.name,
            teachings[i].teacher.gender, teachings[i].teacher.education,
            teachings[i].teacher.title);
    }
    fclose(fpw);//关闭文件指针
}

//写入选课信息
void write_selection() {
    FILE* fpw = fopen("selection.txt", "w");
    for (int i = 0; i < selection_count; i++) {
        fprintf(fpw, "%d %s %s %s %d %f %s %d %d %s %s %s %s %f\n", selections[i].select_id,
            selections[i].course.course_id, selections[i].course.name,
            selections[i].course.nature, selections[i].course.hours,
            selections[i].course.credit, selections[i].course.term,
            selections[i].course.is_teaching, selections[i].course.is_selected,
            selections[i].student.student_id, selections[i].student.name,
            selections[i].student.gender, selections[i].student.classroom, selections[i].score);
    }
    fclose(fpw);//关闭文件指针
}

//读取所有信息
void Read() {
    read_user();
    read_teacher();
    read_student();
    read_course();
    read_teaching();
    read_selection();
}

//写入所有信息
void Write() {
    write_user();
    write_teacher();
    write_student();
    write_course();
    write_teaching();
    write_selection();
}
