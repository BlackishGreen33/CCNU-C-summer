#include<easyx.h>
#include<stdio.h>
#include<windows.h>
#pragma comment(lib,"Winmm.lib")

#define PI 3.14

int main(){
	initgraph(1124, 1024);
	mciSendString(_T("open 2.mp3 alias bkmusic"), NULL, 0, NULL);
	mciSendString(_T("play bkmusic repeat"), NULL, 0, NULL);
	while(1){
		setbkcolor(WHITE);
		cleardevice();

		// head
		Sleep(1000);
		setlinecolor(BLACK);
		setlinestyle(PS_SOLID, 4);

		Sleep(1000);
		setfillcolor(BLUE);
		fillellipse(118, 125, 990, 931);

		Sleep(1000);
		setfillcolor(WHITE);
		fillellipse(189, 271, 919, 931);

		// eyes
		Sleep(1000);
		fillellipse(375, 170, 555, 420);
		fillellipse(555, 170, 735, 420);

		Sleep(1000);
		setfillcolor(BLACK);
		solidcircle(484, 333, 25);
		solidcircle(617, 333, 25);

		Sleep(1000);
		setfillcolor(WHITE);
		solidcircle(484, 333, 10);
		solidcircle(617, 333, 10);

		// nose
		Sleep(1000);
		setfillcolor(RED);
		fillcircle(554, 420, 35);

		Sleep(1000);
		line(554, 460, 554, 828);

		// mouth
		Sleep(1000);
		arc(320, 510, 789, 827, PI, 2 * PI);

		// bread
		Sleep(1000);
		line(125, 313, 296, 410);
		line(83, 444, 270, 474);
		line(83, 595, 262, 527);
		line(819, 414, 990, 320);
		line(845, 478, 1029, 448);
		line(853, 542, 1029, 660);

		Sleep(1000);
	}
	getchar();
	closegraph();
	return 0;
}