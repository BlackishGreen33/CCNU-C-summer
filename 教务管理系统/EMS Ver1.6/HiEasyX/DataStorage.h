#pragma once
#include "DataFormat.h"

char current_username[20], current_password[20];

// 用戶數據
User users[200] = {};
int user_count = 0;

// 教師信息
Teacher teachers[50] = {};
int teacher_count = 0;

// 學生信息
Student students[50] = {};
int student_count = 0;

// 課程信息
Course courses[100] = {};
int course_count = 0;

// 授課信息
Teaching teachings[100] = {};
int teaching_count = 0;

// 選課信息
Selection selections[100] = {};
int selection_count = 0;

// 讀取用戶信息
void read_user() {
    // 用戶數據
    FILE* fpr = fopen("user.txt", "r");
    int count = 0;
    while (fscanf(fpr, "%s %s %s %d", users[count].user_id, users[count].username, users[count].password, &users[count].role) != EOF) {
        count++;
    }
    user_count = count;
    fclose(fpr);
}

// 讀取教師信息
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

// 讀取學生信息
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

// 讀取課程信息
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

// 讀取授課信息
void read_teaching() {
    // 授課信息
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

// 讀取選課信息
void read_selection() {
    // 選課信息
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

// 寫入用戶信息
void write_user() {
    FILE* fpw = fopen("user.txt", "w");
    for (int i = 0; i < user_count; i++) {
        fprintf(fpw, "%s %s %s %d\n", users[i].user_id, users[i].username, users[i].password, users[i].role);
    }
    fclose(fpw);
}

// 寫入教師信息
void write_teacher() {
    FILE* fpw = fopen("teacher.txt", "w");
    for (int i = 0; i < teacher_count; i++) {
        fprintf(fpw, "%s %s %s %s %s\n", teachers[i].teacher_id, teachers[i].name, teachers[i].gender, teachers[i].education, teachers[i].title);
    }
    fclose(fpw);
}

// 寫入學生信息
void write_student() {
    FILE* fpw = fopen("student.txt", "w");
    for (int i = 0; i < student_count; i++) {
        fprintf(fpw, "%s %s %s %s\n", students[i].student_id, students[i].name, students[i].gender, students[i].classroom);
    }
    fclose(fpw);
}

// 寫入課程信息
void write_course() {
    FILE* fpw = fopen("course.txt", "w");
    for (int i = 0; i < course_count; i++) {
        fprintf(fpw, "%s %s %s %d %f %s %d %d\n", courses[i].course_id, courses[i].name, courses[i].nature, courses[i].hours, courses[i].credit, courses[i].term, courses[i].is_teaching, courses[i].is_selected);
    }
    fclose(fpw);
}

// 寫入授課信息
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
    fclose(fpw);
}

// 寫入選課信息
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
    fclose(fpw);
}

// 讀取所有信息
void Read() {
    read_user();
    read_teacher();
    read_student();
    read_course();
    read_teaching();
    read_selection();
}

// 寫入所有信息
void Write() {
    write_user();
    write_teacher();
    write_student();
    write_course();
    write_teaching();
    write_selection();
}
