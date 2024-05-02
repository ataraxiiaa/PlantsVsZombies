#pragma once

#include <iostream>
using namespace std;

template <typename Type>class Vector 
{
	Type* ptr;
	int currSize, maxSize;

public:
	Vector(); // Default Constructor 
	~Vector() { delete[] ptr; }

	void push_back(Type value);

	Type& operator[](int index) { return ptr[index]; }
};

template <typename Type> class Vector<Type*>  // Class created for pointer to pointer
{
	Type** ptr;
	int currSize, maxSize;
public:
	Vector()
	{
		ptr = new Type * [5];
		currSize = 0;
		maxSize = 5;
	}
	/*~Vector() {
		for (int i = 0; i < currSize; ++i) {
			if (ptr[i] != nullptr)
				delete[] ptr[i];
		}
			delete[] ptr;
	}*/
	int GetSize()const { return this->currSize; }

	void push_back(Type* value) {
		if (currSize == maxSize) {
			Type** temp = new Type * [maxSize];
			for (int i = 0; i < maxSize; ++i)
				temp[i] = ptr[i];
			delete[] ptr;
			ptr = new Type * [2 * maxSize];
			for (int i = 0; i < maxSize; ++i)
				ptr[i] = temp[i];
			delete[] temp;
			maxSize *= 2;
		}
		ptr[currSize] = value;
		++currSize;
	}
	Type*& operator[](int index) 
	{ 
		return ptr[index]; 
	}

};