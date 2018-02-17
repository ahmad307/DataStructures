#include <iostream>
#include <algorithm>

/* Template classes are used to enable storage of different data types */

template <class T>
class Heap
{
	T *arr;
	int elementsCount;

public:
	Heap(int size);

	void insert(T val);
	void deleteMin();
	void displayAll();
};
