#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include "DataFormat.h" // 調用教務管理系統數據格式頭文件
#include "DataStorage.h" // 調用用戶數據頭文件
#include "HiEasyX.h"
#define _CRT_SECURE_NO_WARNINGS
#include "Login.h"


Login::Login() {
    int count = 0, checkrole = 0;
    time_t start_time = 0, now_time = 0;

    //hiex::SetCustomIcon(MAKEINTRESOURCE(IDI_ICON1), MAKEINTRESOURCE(IDI_ICON1));
    LoginScreen.Create(WindowWidth, WindowHeight, EX_NOMINIMIZE, L"登錄");
    LoginCanva.InIt(WindowWidth, WindowHeight, WHITE);// 設置畫布相關參數
    LoginScreen.BindCanvas(&LoginCanva);// 將窗口和畫布綁定
    putimage(0, 0, &LoginCanva);// 將畫布內容輸出到窗口
    CreateEdit();
    CreatButton();
    LoginGIF();

    int i = 0;
    while (IfAlive()) {
        LoginCanva.PutImageIn_Alpha(0, 0, &LoginGIFImg[i]);
        LoginScreen.Redraw();// 重繪窗口
        Sleep(100);
        i++;
        if (i == GIFFramesNum) {
            i = 0;
        }
        if (LoginButton.IsClicked()) {
            UserName = UserNameEdit.GetText();
            int len1 = WideCharToMultiByte(CP_UTF8, 0, UserName.c_str(), -1, NULL, 0, NULL, NULL);
            char* buffer1 = new char[len1];
            WideCharToMultiByte(CP_UTF8, 0, UserName.c_str(), -1, buffer1, len1, NULL, NULL);
            strcpy(current_username, buffer1);
            delete[] buffer1;
            Password = PasswordEdit.GetText();
            int len2 = WideCharToMultiByte(CP_UTF8, 0, Password.c_str(), -1, NULL, 0, NULL, NULL);
            char* buffer2 = new char[len2];
            WideCharToMultiByte(CP_UTF8, 0, Password.c_str(), -1, buffer2, len2, NULL, NULL);
            strcpy(current_password, buffer2);
            delete[] buffer2;
            for (int i = 0; i < user_count; i++) {
                if (strcmp(current_username, users[i].username) == 0 && strcmp(current_password, users[i].password) == 0) {
                    checkrole = users[i].role;
                }
            }
            if (checkrole != 0) {
                IfLoginSuccess = true;
                MessageBox(GetHandle(), L"登錄成功！", L"提示", MB_OK | MB_ICONASTERISK);
                LoginScreen.CloseWindow();
                break;
            }
            else {
                MessageBox(GetHandle(), L"密碼錯誤！", L"提示", MB_OK | MB_ICONERROR);
                count++;
                if (count == 3) {
                    start_time = time(NULL);
                    LoginScreen.CloseWindow();
                    printf("帳號或密碼錯誤3次，已鎖定5分鐘，請稍後再試。\n");
                }
                // 判斷是否鎖定
                if (start_time > 0) {
                    while ((now_time = time(NULL)) - start_time < 300) { // 5分鐘
                        printf("帳號已鎖定，請等待 %lld 秒後再試。\n", start_time + 300 - now_time);
                        Sleep(1);
                    }
                    system("cls");
                    Login();
                }
            }
        }
    }
    if (!IfAlive() && !IfLoginSuccess) {
        exit(0);
    }
}

HWND Login::GetHandle() {
    return LoginScreen.GetHandle();
}

bool Login::IfAlive() {
    return LoginScreen.IsAlive();
}

Login::~Login() {

}


void Login::CreateEdit() {
    const int Uy = LeftTopY + EditHeight;
    const int Py = LeftTopY + (2 * EditHeight) + (EditHeight / 2);

    UserNameEdit.PreSetStyle(EditStyle);
    PasswordEdit.PreSetStyle(EditStyle);// 樣式設置

    UserNameEdit.Create(LoginScreen.GetHandle(), LeftTopX, Uy, EditWidth, EditHeight, L"");
    PasswordEdit.Create(LoginScreen.GetHandle(), LeftTopX, Py, EditWidth, EditHeight, L"");

    PasswordEdit.Password(true);// 設置為密碼框

    UserNameEdit.SetFont(FontSize, 0, Font);
    PasswordEdit.SetFont(FontSize, 0, Font);// 字號字體設置

    UserNameEdit.SetMaxTextLength(UserNameMaxLen);
    PasswordEdit.SetMaxTextLength(PasswordMaxLen);// 最大輸入長度設置
    //edit.NumberOnly(if_only_number);// 是否僅數字

    const int PromptUserNameWidth = textwidth(PromptUserName);// 用戶名提示文字寬度
    int Tx = LeftTopX - PromptUserNameWidth;

    setbkmode(TRANSPARENT);// 設置文字背景色透明
    LoginCanva.SetTextStyle(20, 0, L"微软雅黑", 0, 0, 0, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, DEFAULT_PITCH | FF_DONTCARE);

    LoginCanva.OutTextXY(Tx, Uy, PromptUserName, true, RGB(18, 183, 245));
    LoginCanva.OutTextXY(Tx, Py, PromptPassword, true, RGB(18, 183, 245));// 指定位置繪製文字
    LoginScreen.Redraw();// 重繪窗口
}

void Login::LoginGIF() {
    for (int i = 0; i < 11; i++){
        loadimage(&LoginGIFImg[i], L"PNG", MAKEINTRESOURCE(i + IDB_PNG1), WindowWidth, 130);
    }
}

void Login::CreatButton() {
    LoginButton.Create(GetHandle(), LoginButtonX, LoginButtonY, LoginButtonW, LoginButtonH);// 創建按鈕
    int LoginButtonCanvaW = LoginButtonW - 6;
    int LoginButtonCanvaH = LoginButtonH - 6;
    LoginButtonCanva.InIt(LoginButtonCanvaW, LoginButtonCanvaH, RGB(6, 187, 252));// 設置按鈕畫布相關參數

    const int LoginButtonTextW = textwidth(LoginButtonText);// 登錄按鈕提示文字寬度
    const int LoginButtonTextH = textheight(LoginButtonText);// 登錄按鈕提示文字高度
    const int Tx = (LoginButtonCanvaW - LoginButtonTextW - 10) / 2;
    const int Ty = (LoginButtonCanvaH - LoginButtonTextH - 6) / 2;

    setbkmode(TRANSPARENT);// 設置文字背景色透明
    LoginButtonCanva.SetTextStyle(25, 0, L"微软雅黑", 0, 0, 0, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, DEFAULT_PITCH | FF_DONTCARE);
    LoginButtonCanva.OutTextXY(Tx, Ty, LoginButtonText, true, WHITE);
    LoginButton.Image(true, &LoginButtonCanva, false);
}


int check_user(char* username, char* password) {
    int i;
    for (i = 0; i < user_count; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            return users[i].role; // 返回用戶權限
        }
    }
    return 0; // 返回0表示帳號或密碼錯誤
}

int user_login() {
    int role;
    //int count = 0;
	//time_t start_time = 0, now_time = 0;	

	// 輸入帳號密碼
	//printf("請輸入帳號：");
	//scanf("%s", current_username);
	//printf("請輸入密碼：");
	//scanf("%s", current_password);

	// 判斷帳號密碼是否正確，錯誤3次則鎖定5分鐘
	//while ((role = check_user(current_username, current_password)) == 0) {
		//count++;
		//if (count == 3) {
			//start_time = time(NULL);
			//printf("帳號或密碼錯誤3次，已鎖定5分鐘，請稍後再試。\n");
			//break;
		//}
		//printf("帳號或密碼錯誤，請重新輸入：\n");
		//printf("請輸入帳號：");
		//scanf("%s", current_username);
		//printf("請輸入密碼：");
		//scanf("%s", current_password);
	//}

	// 判斷是否鎖定
	//if (start_time > 0) {
		//while ((now_time = time(NULL)) - start_time < 300) { // 5分鐘
			//printf("帳號已鎖定，請等待 %lld 秒後再試。\n", start_time + 300 - now_time);
			//Sleep(1);
		//}
	//}
    Login();
    if((role = check_user(current_username, current_password)) == 0)
	    return role;
}