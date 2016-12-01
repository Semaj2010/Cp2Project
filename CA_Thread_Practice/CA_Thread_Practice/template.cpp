#pragma once
#include <string>
#include <vector>
#include "Frame.h"
#include "ExArray.h"
#include <list>
#include <map>

using namespace std;

void dump(list <string> &l) {
	list<string>::iterator iter = l.begin();
	while (iter != l.end()) {
		cout << *iter << endl;
		iter++;
	}
}
class Word {
private:
	string word;
public:
	Word(string word) {
		this->word = word;
	}
	string getWord() {
		return this->word;
	}
};
void main() {
	map<char, list<Word>> m;

	list<Word> aList;
	list<Word> bList;

	aList.push_back(Word("apple"));
	aList.push_back(Word("avoid"));
	aList.push_back(Word("appear"));

	bList.push_back(Word("bread"));
	bList.push_back(Word("bring"));
	bList.push_back(Word("bow"));
	m['a'] = aList;
	m['b'] = bList;

	map<char, list<Word>>::const_iterator iter = m.begin();

	while (iter != m.end()) {
		cout << iter->first << ":" << endl;

		list<Word> temp = iter->second;
		list<Word>::const_iterator iter_list = temp.begin();

		while (iter_list != temp.end()) {
			Word word = *iter_list;
			cout << word.getWord() << ", ";
			iter_list++;
		}
		cout << "\n===" << endl;
		iter++;
	}


}
void main_map() {
	map<string, int> m;
	m["Seoul"] = 100;
	m["daegu"] = 120;
	m["busan"] = 200;

	cout << "Train to Seoul = " << m["Seoul"] << "$" << endl;
	cout << "Train to Daegu = " << m["daegu"] << "$" << endl;
	cout << "Train to Busan = " << m["busan"] << "$" << endl;
}
void main_list() {

	list <string> names;
	names.insert(names.begin(), "Konkuk");
	names.insert(names.begin(), "University");
	names.insert(names.begin(), "SCLAB");
	names.insert(names.begin(), "CSY");
	dump(names);
	cout << "===" << endl;
	names.reverse();
	dump(names);	
}

void main2() {
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
}