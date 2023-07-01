#pragma once
// 用戶信息結構體
typedef struct {
    char user_id[20]; // 用戶ID
    char username[20]; // 用戶名
    char password[20]; // 密碼
    int role; // 用戶權限，1為管理員，2為教師，3為學生
} User;

// 教師信息結構體
typedef struct {
    char teacher_id[20]; // 教師編號
    char name[20]; // 教師姓名
    char gender[10]; // 教師性別
    char education[20]; // 教師學歷
    char title[20]; // 教師職稱
} Teacher;

// 學生信息結構體
typedef struct {
    char student_id[20]; // 學生編號
    char name[20]; // 學生姓名
    char gender[10]; // 學生性別
    char classroom[20]; // 學生班級
} Student;

// 課程信息結構體
typedef struct {
    char course_id[20]; // 課程編號
    char name[20]; // 課程名稱
    char nature[20]; // 課程性質
    int hours; // 課程學時
    float credit; // 課程學分
    char term[30]; // 開課學期
    int is_teaching; // 是否正在講授
    int is_selected; // 是否被學生選修
} Course;

// 授課信息結構體
typedef struct {
    int teach_id; // 授課ID
    Course course; // 課程信息
    Teacher teacher; // 授課教師信息
} Teaching;

// 選課信息結構體
typedef struct {
    int select_id; // 選課ID
    Course course; // 課程信息
    Student student; // 學生信息
    float score; // 學生成績
} Selection;

// 用戶數據
extern User users[];
extern int user_count;

// 教師數據
extern Teacher teachers[];
extern int teacher_count;

// 學生數據
extern Student students[];
extern int student_count;

// 課程數據
extern Course courses[];
extern int course_count;

// 授課數據
extern Teaching teachings[];
extern int teaching_count;

// 選課數據
extern Selection selections[];
extern int selection_count;