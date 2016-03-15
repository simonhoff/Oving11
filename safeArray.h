#pragma once

template<class type>
	class safeArray{
	private:
		type *data;
		int currentSize;
		int totalSize;
	public:
		safeArray(){
			currentSize = 0;
			totalSize = 100000000;
			data = NULL;
		}
		int size() { return currentSize }
		type& operator[](int i){
			return *(data + i);
		}

		void operator[](int i, type &rhs){
			if (i<currentSize){
				*(data+i) = rhs;
			}else{
				type *temp = new type[i+1];
				for (int index = 0; index < currentSize; index++){
					*(temp + index) = *(data + index);
				}
				for (; index < i-1; index++){
					*(temp + index) = 0;
				}
				*(temp + i - 1) = rhs;
				currentSize = i;
			}
		}
	}