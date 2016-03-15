#include <cstdlib>
#include <iostream>
#include "simpleset.h"

using namespace std;

SimpleSet::SimpleSet(){
	maxSize = 100 000;
	data = NULL;
	currentSize = 0;
}

bool SimpleSet::insert(int i){
	if (!this->exists(i)){
		resize(currentSize + 1);
		*(data + currentSize) = i;
		return true;
	}else return false;
}

bool SimpleSet::exists(int i){
	for (int index = 0; index < currentSize; index++){
		if ( *(data + index) == i) return true;
	}
	return false;
}

bool SimpleSet::remove(int i){
	if (this->exists(i)){
		int temp[currentSize];
		for (int index = 0; index < currentSize; currentSize++){
			temp[index] = *(data + index);
		}
		resize(currentSize - 1);
		int insertIndex = 0;
		for (int index = 0; index < currentSize; index++){
			if (temp[index] != i){
				*(data + insertIndex) = temp[index];
			}
		}
		return true;
	}else return false;
}

void SimpleSet::resize(int n){
	if (n > maxSize){
		cout << "maxSize exceeded" << endl; exit(1);
	}
	int oldSize = currentSize;
	int temp[currentSize];
	for (int i = 0; i < currentSize; i++){
		temp[i] = *(data + i);
	}
	delete[] data;
	currentSize = n;
	data = new int[currentSize];
	for (int i = 0; i < min(oldSize, currentSize); i++){
		*(data + i) = temp[i];
	}
}

int SimpleSet::find(int i){
	for (int index = 0; index < currentSize; index++){
		if (*(data + index) == i) return index;
	}
	return -1;
}