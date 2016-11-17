#include <process.h>
#include <iostream>
#include "KeyEvent.h"

using namespace std;


unsigned int __stdcall mythread(void*) {
	int i = 0;
	while (1) {
		cout << GetCurrentThreadId() << ": " << i++ << endl;
		Sleep(500);
	}
	return 0;
}

unsigned int __stdcall keyEvent(void*) {
	KeyEvent k;
	int i;
	while (1) {
		i = k.getkey();
		switch (i) {
		case 37: cout << "Left key" << endl; break;
		case 38: cout << "up key" << endl; break;
		case 39: cout << "right key" << endl; break;
		case 40: cout << "down key" << endl; break;
		}
			
	}
	return 0;
}

int main() {
	HANDLE handleA, handleB;

	handleA = (HANDLE)_beginthreadex(0, 0, &mythread, (void*)0, 0, 0);
	handleB = (HANDLE)_beginthreadex(0, 0, &keyEvent, (void*)0, 0, 0);

	WaitForSingleObject(handleA, INFINITE);
	WaitForSingleObject(handleB, INFINITE);

	CloseHandle(handleA);
	CloseHandle(handleB);

	return 0;
}