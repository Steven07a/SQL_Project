#ifndef Vector_H_
#define Vector_H_

#include <iostream>
#include <iomanip>
#include <initializer_list>
#include <algorithm>
#include "C:\Users\Steven_dev\Desktop\CS_Stuff\Sort-Functions\SortFunctions\SortFunctions\sort_functions.h"
using namespace std;

template <typename T>
class Vector {
public:
	Vector() {
		myCapacity = 2;
		index = 0;
		arrPtr = new T[myCapacity];
		for (int i = 0; i < myCapacity; i++) {
			arrPtr[i] = T();
		}
	}

	Vector(int size) {
		myCapacity = 2;
		index = 0;
		while (myCapacity < size) {
			myCapacity *= 2;
		}
		arrPtr = new T[myCapacity];
		for (int i = 0; i < myCapacity; i++) {
			arrPtr[i] = T();
		}
	}
	void push_back(Vector<T> list);
	void push_back(T item);
	void clear();
	int size() const;
	int capacity() const;
	void print_from_index(int index);
	void remove(T item);
	bool contains(T item);
	Vector<T>& vecmerge(Vector<T>v2);
	Vector<T>& getIntersection(Vector<T>v2);
	T& operator[](const int index);
	T operator[](const int index) const;

	Vector<T>& operator =(const Vector<T>& RHS) {
		if (arrPtr != NULL) {
			delete[] arrPtr;
		}
		
		myCapacity = RHS.myCapacity;
		index = RHS.index;
		arrPtr = new T[myCapacity];
		for (int i = 0; i < index; i++) {
			arrPtr[i] = RHS.arrPtr[i];
		}

		return *this;
	}


	Vector(initializer_list<T> list) {
		index = 0;
		myCapacity = list.size();
		arrPtr = new T[myCapacity];
		for (T element : list) {
			arrPtr[index] = element;
			index++;
		}
	}



private:
	void expand_size();
	void copy_array(T* oldArr,T* newArr);
	T* arrPtr;
	int index;
	int myCapacity;
};

template <typename T>
bool Vector<T>::contains(T item) {
	for (int i = 0; i < size(); i++) {
		if (this->arrPtr[i] == item) {
			return true;
		}
	}
	return false;
}

template<typename T>
void Vector<T>::push_back(T item) {
	arrPtr[index] = item;
	index++;
	if (index == myCapacity) {
		expand_size();
	}
}

template <typename T>
void Vector<T>::remove(T item) {
	int pos = 0;
	for (int i = 0; i < size(); i++) {
		if (arrPtr[i] == item) {
			arrPtr[i] = T();
			pos = i; 
			break;
		}
	}
	for (int i = pos; i < size(); i++) {
		arrPtr[i] = arrPtr[i + 1];
	}
	index--;
}

template<typename T>
void Vector<T>::push_back(Vector<T> list) {
	for (int i = 0; i < list.size(); i++) {		
		arrPtr[index] = list[i];
		index++;
		if (index == myCapacity) {
			expand_size();
		}
		
	}
}

template <typename T>
void Vector<T>::expand_size() {
	myCapacity *= 2;
	T* newArr = new T[myCapacity];
	copy_array(arrPtr, newArr);
	delete[] arrPtr;
	arrPtr = newArr;
}

template <typename T>
void Vector<T>::copy_array(T* oldArr,T* newArr) {
	for (int i = 0; i < size(); i++) {
		newArr[i] = oldArr[i];
	}
}

template <typename T>
int Vector<T>::size() const {
	return index;
}

template <typename T>
int Vector<T>::capacity() const {
	return myCapacity;
}

template <typename T>
T& Vector<T>::operator[](const int index) {
	return arrPtr[index];
}

template <typename T>
T Vector<T>::operator[](const int index) const {
	return arrPtr[index];
}

template<typename T>
void Vector<T>::clear() {
	for (int i = 0; i < size(); i++) {
		arrPtr[i] = T();
	}
	index = 0; 

}

template <typename T>
Vector<T>& Vector<T>::vecmerge(Vector<T>v2) {
	Vector<T> myVec;
	int index1 = 0, index2 = 0;
	bool endOf1 = false;
	if (size() > 0) {
		quick_sort(this->arrPtr, size());
	} else {
		quick_sort(v2.arrPtr, v2.size());
		for (int i = 0; i < v2.size(); i++) {
			myVec.push_back(v2.arrPtr[i]);
		}
		return myVec;
	}
	
	if (v2.size() > 0) {
		quick_sort(v2.arrPtr, v2.size());
	} else {
		quick_sort(this->arrPtr, size());
		for (int i = 0; i < size(); i++) {
			myVec.push_back(this->arrPtr[i]);
		}
		return myVec;
	}
	

	for (int i = 0; i < (this->size() + v2.size()); i++) {
		if (this->arrPtr[index1] == v2[index2]) {
			myVec.push_back(this->arrPtr[index1]);
			index1++;
			index2++;
		} else if (this->arrPtr[index1] < v2[index2]) {
			myVec.push_back(this->arrPtr[index1]);
			index1++;
		} else {
			myVec.push_back(v2[index2]);
			index2++;
		}
		if (index1 == this->size()) {
			endOf1 = true;
			break;
		} else if (index2 == v2.size()) {
			endOf1 = false;
			break;
		}
	}
	if (endOf1) {
		for (int i = index2; i < v2.size(); i++) {
			if (myVec[myVec.size() - 1] != v2[i]) {
				myVec.push_back(v2[i]);
			}
		}
	} else {
		for (int i = index1; i < this->size(); i++) {
			if (myVec[myVec.size() - 1] != this->arrPtr[i]) {
				myVec.push_back(this->arrPtr[i]);
			}
		}
	}
	return myVec;
}

template<typename T>
Vector<T>& Vector<T>::getIntersection(Vector<T>v2) {
	Vector<T> myVec;
	int index1 = 0, index2 = 0;

	quick_sort(this->arrPtr, size());
	quick_sort(v2.arrPtr, v2.size());

	for (int i = 0; i < (this->size() + v2.size()); i++) {
		if (this->arrPtr[index1] == v2[index2]) {
			myVec.push_back(this->arrPtr[index1]);
			index1++;
			index2++;
		} else if (this->arrPtr[index1] < v2[index2]) {
			index1++;
		} else {
			index2++;
		}
		if (index1 == this->size()) {
			break;
		} else if (index2 == v2.size()) {
			break;
		}
	}
	return myVec;
}

template <typename T>
void Vector<T>::print_from_index(int index) {
	for (int i = index; i < this->size(); i++) {
		cout << setw(15) << right << this->arrPtr[i];
		if (arrPtr[i] == "") {
			break;
		}
	}
}

#endif // !Vector_H_