#pragma once
#include <process.h>
#include <iostream>
#include "KeyEvent.h"

using namespace std;


class Game {
private:
	int x;
	int y;
	int direction;
	void gotoXY(int x, int y) {
		COORD pos = { x,y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}
	void setColor(char color, char background)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (background << 4) + color);
	}
public:
	Game() {
		x = 5;
		y = 5;
		direction = 0;
	}
	void setDirection(int i) {
		direction = i;
	}
	void move() {
		if (direction == 37) {
			x--;
		}
		else if (direction == 38) {
			y--;
		}
		else if (direction == 39) {
			x++;
		}
		else if(direction == 40){
			y++;
		}
		system("cls");
		
		this->gotoXY(1, 1);
		cout << x << " " << y;
		this->gotoXY(x, y);
		cout << "��";
	}
};

Game* game = new Game();

unsigned int __stdcall mythread(void*) {
	int i = 0;
	while (1) {
		game->move();
		//cout << GetCurrentThreadId() << ": " << i++ << endl;
		Sleep(500);
	}
	return 0;
}

unsigned int __stdcall keyEvent(void*) {
	KeyEvent k;
	int i;
	while (1) {
		i = k.getkey();
		if (i != -1)
			game->setDirection(i);
	}
	return 0;
}

int __main() {
	HANDLE handleA, handleB;

	handleA = (HANDLE)_beginthreadex(0, 0, &mythread, (void*)0, 0, 0);
	handleB = (HANDLE)_beginthreadex(0, 0, &keyEvent, (void*)0, 0, 0);

	WaitForSingleObject(handleA, INFINITE);
	WaitForSingleObject(handleB, INFINITE);

	CloseHandle(handleA);
	CloseHandle(handleB);

	return 0;
}