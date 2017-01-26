//klepple 250836229
#pragma once
#include <iostream>
using namespace std;
//Header File

class SimpleVector {
private:
	int* _array;
	int* _tempArray;
	int _numElements;
	int _capacity;
	void extend();
public:
	int& operator[](int i) {
		if (i < 0 || i >= _numElements) {
			cout << "Index out of bounds" << endl;
			return _array[0];
		}
		return _array[i];
	}
	SimpleVector() {//default Constructor
		_capacity = 10;
		_numElements = 0;
		_array = new int[_capacity];//create array
	}
	SimpleVector(int size) {
		_capacity = size;
		_numElements = 0;
		_array = new int[_capacity];//create array
	}
	~SimpleVector() {//Destructor
		delete[]_array;
	}
	//Function initializions
	void print();
	int size();
	int empty();
	void push_back(int x);
	void pop_back();
	void clear();
	void set(int x, int i);
	int insert(int x, int i);
	void reverse();
};