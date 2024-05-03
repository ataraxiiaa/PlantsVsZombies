#include "Vector.h"

template <typename Type> Vector<Type>::Vector() {
    ptr = new Type[5];
    currSize = 0;
    maxSize = 5;
}

template <typename Type> void Vector<Type>::push_back(Type value) {
    if (currSize == maxSize) {
        Type* temp = new Type[maxSize];
        for (int i = 0; i < maxSize; ++i)
            temp[i] = ptr[i];
        delete[] ptr;
        ptr = new Type[2 * maxSize];
        for (int i = 0; i < maxSize; ++i)
            ptr[i] = temp[i];
        delete[] temp;
        maxSize *= 2;
    }
    ptr[currSize] = value;
    ++currSize;
}
template <typename Type> void Vector<Type>::Destroy(int index) {
    if (index == currSize - 1) {
        currSize--;
    }
    else {
        for (int i = index; i < currSize - 1; ++i) { // Discarding the vakue not required
            ptr[i] = ptr[i + 1]; // Move the values by 1
        }
        currSize--; // Adjust the current Size
    }
}
