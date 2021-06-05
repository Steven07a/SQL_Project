#ifndef BTreeFunctions_H_
#define BTreeFunctions_H_

#include <iostream>
#include "C:\Users\Steven_dev\Desktop\CS_Stuff\vector\vector\vector\Vector.h"

using namespace std;


template <class T>      //return the larger of the two items
T maximal(const T& a, const T& b) {
    return a > b ? a : b;
}

template <class T>      //swap the two items
void swaps(T& a, T& b) {
    T temp = b;
    b = a;
    a = temp;
}

template <class T>        //return index of the largest item in data
int index_of_maximal(T data[], int n) {
    T maxIndex = 0;
    for (int i = 0; i < n; i++) {
        if (data[maxIndex] < data[i]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

template <class T>      //return the first element in data that is not less than entry
int first_ge(const T data[], int n, const T& entry) {
    for (int i = 0; i < n; i++) {
        if (data[i] >= entry) {
            return i;
        }
    }
    return n;
}

template <class T>       //append entry to the right of data
void attach_item(T data[], int& n, const T& entry) {
    n++;
    data[n] = entry;
}

template <class T>  //insert entry at index i in data
void insert_item(T data[], int index, int& n, T entry) {
    if (n > 0) {
        for (int i = n; i > index; i--) {
            data[i] = data[i - 1];
        }
    }
    n++;
    data[index] = entry;
}

template <class T>      //insert entry into the sorted array data with length n
void ordered_insert(T data[], int& n, T entry) {
    int index = first_ge(data, n, entry);
    insert_item(data, index, n, entry);
}
                                                        
template <class T>  //remove the last element in data and place it in entry
void detach_item(T data[], int& n, T& entry) {
    entry = data[n-1];
    data[n-1] = T();
    n--;
}
                                                        

template <class T>      //delete item at index i and place it in entry
void delete_item(T data[], int index, int& n, T& entry) {
    entry = data[index];
    data[index] = T();
    for (int i = index; i < n-1; i++) {
        data[i] = data[i + 1];
    }
    n--;
}

template <class T>      //append data2 to the right of data1
void merge(T data1[], int& n1, T data2[], int& n2) {
    int max = n1 + n2;
    int index = 0;
    for (int i = n1; i < max; i++) {
        data1[i] = data2[index];
        data2[index] = T();
        index++;
        n2--;
        n1++;
    }
}

template <class T>   //move n/2 elements from the right of data1 and move to data2
void split(T data1[], int& n1, T data2[], int& n2) {
    int temp = n1;
    for (int i = (n1 / 2); i < temp; i++) {
        data2[n2] = data1[i];
        data1[i] = T();
        n2++;
        n1--;
    }
}
                                                        

template <class T>          //copy src[] into dest[]
void copy_array(T dest[], const T src[],
    int& dest_size, int src_size) {
    for (int i = 0; i < src_size; i++) {
        dest[i] = src[i];
        dest_size++;
    }
}

template <class T> //print array data
void print_array(const T data[], int n, int pos = -1) {
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
}


template <class T>          //item > all data[i]
bool is_gt(const T data[], int n, const T& item) {
    bool greater = true;
    for (int i = 0; i < n; i++) {
        if (data[i] > item) {
            greater = false;
        }
    }
    return greater;
}

template <class T>           //item <= all data[i]
bool is_le(const T data[], int n, const T& item) {
    bool lessThan = true;
    for (int i = 0; i < n; i++) {
        if (data[i] <= item) {
            lessThan = false;
        }
    }
    return lessThan;
}

template<class T>
void cleanArr(T data[], int& n) {
    for (int i = 0; i < n; i++) {
        data[i] = T();
    }
    n = 0;
}
//-------------- Vector Extra operators: ---------------------

template <typename T>       //print vector list
ostream& operator <<(ostream& outs, const Vector<T>& list) {
    for (int i = 0; i < list.size(); i++) {
        outs << list[i] << " ";
    }
    return outs;
}

template <typename T>        //list.push_back addme
Vector<T>& operator +=(Vector<T>& list, const T& addme) {
    list.push_back(addme);
    return list;
}



#endif // !BTreeFunctions_H_
