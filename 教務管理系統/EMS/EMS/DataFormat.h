#pragma once
// �Τ�H�����c��
typedef struct {
    char user_id[20]; // �Τ�ID
    char username[20]; // �Τ�W
    char password[20]; // �K�X
    int role; // �Τ��v���A1���޲z���A2���Юv�A3���ǥ�
} User;

// �Юv�H�����c��
typedef struct {
    char teacher_id[20]; // �Юv�s��
    char name[20]; // �Юv�m�W
    char gender[10]; // �Юv�ʧO
    char education[20]; // �Юv�Ǿ�
    char title[20]; // �Юv¾��
} Teacher;

// �ǥͫH�����c��
typedef struct {
    char student_id[20]; // �ǥͽs��
    char name[20]; // �ǥͩm�W
    char gender[10]; // �ǥͩʧO
    char classroom[20]; // �ǥͯZ��
} Student;

// �ҵ{�H�����c��
typedef struct {
    char course_id[20]; // �ҵ{�s��
    char name[20]; // �ҵ{�W��
    char nature[20]; // �ҵ{�ʽ�
    int hours; // �ҵ{�Ǯ�
    float credit; // �ҵ{�Ǥ�
    char term[30]; // �}�ҾǴ�
    int is_teaching; // �O�_���b����
    int is_selected; // �O�_�Q�ǥͿ��
} Course;

// �½ҫH�����c��
typedef struct {
    int teach_id; // �½�ID
    Course course; // �ҵ{�H��
    Teacher teacher; // �½ұЮv�H��
} Teaching;

// ��ҫH�����c��
typedef struct {
    int select_id; // ���ID
    Course course; // �ҵ{�H��
    Student student; // �ǥͫH��
    float score; // �ǥͦ��Z
} Selection;

// �Τ�ƾ�
extern User users[];
extern int user_count;

// �Юv�ƾ�
extern Teacher teachers[];
extern int teacher_count;

// �ǥͼƾ�
extern Student students[];
extern int student_count;

// �ҵ{�ƾ�
extern Course courses[];
extern int course_count;

// �½Ҽƾ�
extern Teaching teachings[];
extern int teaching_count;

// ��Ҽƾ�
extern Selection selections[];
extern int selection_count;