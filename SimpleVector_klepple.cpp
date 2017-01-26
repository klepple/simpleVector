//klepple 250836229
#define _SCL_SECURE_NO_WARNINGS //Was getting a warning for the copy function(line 52) so I added this and the project builds successfully
#include "SimpleVector.h"
#include <iostream>
using namespace std;

void SimpleVector::print() {//Print function provided by prof
	for (int i = 0; i < _numElements; i++) {
		cout << "Element at position " << i << " " << _array[i] << endl;
	}
}
int SimpleVector::size() {//Checks the size of the array
	return _numElements;
}
int SimpleVector::empty() {//Checks if function is empty, returns true (1) if it is
	if (_numElements == 0) {
		return 1;
	}
	else {
		return 0;
	}
}
void SimpleVector::push_back(int x) {//Add an element to the end of the array
	if (_capacity == 0) {
		cout << "no." << endl;//If the array cannot contain any elements, then you cannot add elements to the array
	}
	else if (_capacity == _numElements) {//In other words, if the array is full
		extend();//Calls extend function
		_array[_numElements] = x;
		_numElements++;
	}
	else {//If there is room in the array, add x value in next availible spot
		_array[_numElements] = x;
		_numElements++;
	}
	
}
void SimpleVector::pop_back() {//Remove the last element of the array
	if (_numElements == 0) {
		cout << "SimpleVector is empty and therefore no element can be removed" << endl;
	}
	else {
		_numElements--;
	}
}
void SimpleVector::clear() {//Removes all data from the array
	_numElements = 0;
}
void SimpleVector::extend() {//Doubles the amount of values the array can hold
	_capacity *= 2;
	_tempArray = new int[_capacity];//Temporary array to store values
	copy(_array, _array + _numElements, _tempArray);//copy over the original array to the temp one
	delete[] _array;//Delete original array
	_array = _tempArray;//set the temp array to be the main array
}
void SimpleVector::set(int x, int i) {//Set a specific location in the array to a value x
	operator[](i);//Check if out of bounds with function provided by prof
	_array[i] = x;
}
int SimpleVector::insert(int x, int i) {//Insert a value x in a location of the array
	if (i < 0 || i >= _numElements) {//Checks if out of bounds
		cout << "Out of bounds" << endl;
		return 1;
	}
	else {
		push_back(0);//Calls push back function and sets a 0 at the end of the array
		for (int j = _numElements; j > i; j--) {//Loops through and pushes each element back once
				_array[j] = _array[j - 1];
		}
		_array[i] = x;
	}
	return 0;
}
void SimpleVector::reverse() {//Reverses the array
	for (int i = 0; i <= (_numElements / 2); i++) {
		int currentVal = _array[i];
		_array[i] = _array[_numElements - i - 1];
		_array[_numElements - i - 1] = currentVal;
	}
}
