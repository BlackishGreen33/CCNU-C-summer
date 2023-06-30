#include "UserLogin.h"
#include "AdministratorInterface.h"
#include "TeacherInterface.h"
#include "StudentInterface.h"

int main() {
    int role = user_login(); // 調用用戶登錄函數

    // 根據權限進入不同界面
    if (role == 1) {
        printf("歡迎進入學院教務系統管理界面！\n");
        administrator_interface();
    }
    else if (role == 2) {
        printf("歡迎進入教師系統界面！\n");
        teacher_interface();
    }
    else if (role == 3) {
        printf("歡迎進入學生系統界面！\n");
        student_interface();
    }
    else {
        printf("賬號或密碼錯誤，請重新運行程序。\n");
    }

    return 0;
}