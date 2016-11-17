#pragma once
#include <windows.h>
#include <iostream>

#define B_POS 8

using namespace std;
enum {
	BLACK, D_BLUE, D_GREEN, D_SKYBLUE, D_RED,
	D_VIOLET, D_YELLOW, GRAY, D_GRAY, BLUE, GREEN,
	SKYBLUE, RED, VIOLET, YELLO, WHITE,
};
enum {
	KEY_UP = 38, KEY_DOWN = 40, KEY_ENTER = 13,
};

void gotoXY(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void setColor(char color, char background)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (background << 4) + color);
}

void clearConsole() {
	system("cls");
}
class KeyEvent {
private:
	HANDLE hln;
	COORD KeyWere;
	DWORD EventCount;
	INPUT_RECORD InRec;
	DWORD NumRead;
	int downKey;
public:
	KeyEvent() {
		hln = GetStdHandle(STD_INPUT_HANDLE);
		EventCount = 1;
	}
	int getkey() {
		ReadConsoleInput(hln, &InRec, 1, &NumRead);
		if (InRec.EventType == KEY_EVENT) {
			if (InRec.Event.KeyEvent.bKeyDown) {
				downKey = InRec.Event.KeyEvent.wVirtualKeyCode;
				return downKey;
			}
			else {
				return -1;
			}
		}
		return -1;
	}
}; 
