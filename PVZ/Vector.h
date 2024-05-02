#pragma once

#include <iostream>
using namespace std;

template <typename Type>class Vector  // Vector Template that would take type 
{
	Type* ptr; // Pointer to store the type
	int currSize, maxSize; // to track if to expand the vector array or not

public:
	Vector(); // Default Constructor 
	~Vector() { delete ptr; } // Destructor

	void push_back(Type value); // Adding values to the array

	Type& operator[](int index) { return ptr[index]; } // Accessing address the pointer is pointing to 
};

template <typename Type> class Vector<Type*>  // Template of vector created for pointer to pointer
{
	Type** ptr; // pointer to pointer to type
	int currSize, maxSize; // Used to track if to expand the array or ot
public:
	Vector() // Default constructor 
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