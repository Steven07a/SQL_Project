#ifndef sort_functions_H_
#define sort_functions_H_

template <typename T>
void quick_sort(T a[], int size);
template <typename T>
void quick_sort(T a[], int start, int end);
template <class T>
void swap(T a[], unsigned int index1, unsigned int index2);

template <class T>
void quick_sort(T a[], int size) {
    quick_sort(a, 0, size);
}

template <class T>
void quick_sort(T a[], int start, int end) {
    //base case
    int pivotIndex = start, storeIndex = start + 1, arrIndex = pivotIndex + 1;
    //print_array_segment(a, 0, 10);
    if (start < end) {
        while (arrIndex < end) {
            //checks if there is a value less then our value at our pivet index then swaps that value with the store index
            if (a[arrIndex] < a[pivotIndex]) {
                swap(a, arrIndex, storeIndex);
                storeIndex++;
            }
            arrIndex++;
        }
        swap(a, pivotIndex, storeIndex - 1);
        quick_sort(a, start, storeIndex - 1);
        quick_sort(a, storeIndex, end);
    }
}

template <class T>
void swap(T a[], unsigned int index1, unsigned int index2) {
    T temp = a[index1];
    a[index1] = a[index2];
    a[index2] = temp;
}

#endif // !sort_functions_H_
