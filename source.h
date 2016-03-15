#pragma once

#include "person.h"

#ifndef ASD_H
#define ASD_H

#include <iostream>
#include <string>

void insertSorted(std::list<Person> &list, Person x);

template <class T>
	void shuffle(T array[], int size){
		for (int lap = 0; lap < 5; lap++){
			for (int index = 0; index < size; index++){
				int swapIndex = rand() % size;
				T temp = *(array + index);
				*(array + index) = *(array + swapIndex);
				*(array + swapIndex) = temp;
			}
		}
	}

// <, > operators need to be implemented for a class for this function to work
template <class type>
	type maximum(type var1, type var2){
		if (var1 < var2){
			return var2;
		}else{
			return var1;
		}
	}

#endif