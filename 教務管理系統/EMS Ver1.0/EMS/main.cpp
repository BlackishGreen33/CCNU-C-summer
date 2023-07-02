#include "UserLogin.h"
#include "AdministratorInterface.h"
#include "TeacherInterface.h"
#include "StudentInterface.h"

int main() {
    Read();
    int role = user_login(); // 調用用戶登錄函數

    // 根據權限進入不同界面
    if (role == 1) {
        printf("\n歡迎進入學院教務系統管理界面！\n");
        system("pause");
        administrator_interface();
    }
    else if (role == 2) {
        printf("\n歡迎進入教師系統界面！\n");
        system("pause");
        teacher_interface();
    }
    else if (role == 3) {
        printf("\n歡迎進入學生系統界面！\n");
        system("pause");
        student_interface();
    }
    else {
        printf("\n賬號或密碼錯誤，請重新運行程序。\n");
        system("pause");
    }

    return 0;
}