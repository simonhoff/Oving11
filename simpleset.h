#pragma once

#ifndef SIMPLESET_H
#define SIMPLESET_H

//type must have implemented comparison operators (at least operator==)
//There may be issues with objects containing dynamic memory, but it should be fine
template <class type>
	class SimpleSet{
	public:
		/** Construct empty set **/
		SimpleSet(){
			maxSize = 100000;
			data = NULL;
			currentSize = 0;
		}
		/** Insert i into set, return true if the element was inserted, else false **/
		bool insert(type i){
			if (!this->exists(i)){
				resize(currentSize + 1);
				*(data + currentSize) = i;
				return true;
			}else return false;
		}
	/** Returns true if i is in the set **/
		bool exists(type i){
			for (int index = 0; index < currentSize; index++){
				if ( *(data + index) == i) return true;
			}
			return false;
		}
		/** Removes i from the set, return true if an element was removed **/
		//needs operator== to be implemented for type
		bool remove(type i){
			if (this->exists(i)){
				type temp[currentSize];
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
		private:
		/** Dynamic array containing set elements **/
		type *data;
		/** Current number of elements **/
		int currentSize;
		/** Max capasity of data **/
		int maxSize;
		/** Returns the index where i may be found, else an invalid index. **/
		int find(int i){
			for (int index = 0; index < currentSize; index++){
				if (*(data + index) == i) return index;
			}
			return -1;
		}
		/** Resizes data, superflous elements are dropped. **/
		void resize(int n){
			if (n > maxSize){
				std::cout << "maxSize exceeded" << std::endl; exit(1);
			}
			int oldSize = currentSize;
			type temp[currentSize];
			for (int i = 0; i < currentSize; i++){
				temp[i] = *(data + i);
			}
			delete[] data;
			currentSize = n;
			data = new type[currentSize];
			for (int i = 0; i < std::min(oldSize, currentSize); i++){
				*(data + i) = temp[i];
			}
		}
	};

#endif