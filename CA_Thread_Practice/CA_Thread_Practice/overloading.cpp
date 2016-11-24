#pragma once
#include "Frame.h"

void main3() {
	try {
		Frame *f1 = new Frame;
		Frame *f2 = new Frame[10];

		delete f1;
		delete[] f2;
	}
	catch (string msg) {
		cout << "Error msg :" << msg << endl;
	}
}