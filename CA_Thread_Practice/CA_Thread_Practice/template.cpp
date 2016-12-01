#pragma once
#include <string>
#include <vector>
#include "Frame.h"
#include "ExArray.h"

void main() {
	/*
	ExArray<int> arr1(3);
	ExArray<char> arr2(4);
	ExArray<double> arr3(5);

	arr1.addData(2);
	arr2.addData(72);
	arr3.addData(32.12);

	arr1.printData();
	arr2.printData();
	arr3.printData();

	int num1 = 10, num2 = 40;
	cout << "before : " << num1 << ", " << num2 << endl;
	mySwap<int>(num1, num2);
	cout << "after : " << num1 << ", " << num2 << endl;

	double num1d = 121.11, num2d = 10.5;
	cout << "before : " << num1d << ", " << num2d << endl;
	mySwap<double>(num1d, num2d);
	cout << "after : " << num1d << ", " << num2d << endl;

	ExArray<int> arr4(5);
	arr4.addData(10);

	mySwap<ExArray<int>>(arr1, arr4);
	arr1.printData();
	arr4.printData();
	*/
	/*2016.12.01 STL½Ç½À*/
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.insert(v.begin(), 40);
	v.insert(v.end(), 40);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}

	cout << "access index at 1 : " << v.at(1) << endl;

	v.erase(v.begin());
	v.erase(v.end() - 1);
	vector<int>::iterator iter = v.begin();
	cout << " access index at 1 with iterator : " << iter[1] << endl;
	while (iter != v.end()) {
		cout << *iter << endl;
		iter++; // iterators are handles just like pointers
	}

	return 0;
}