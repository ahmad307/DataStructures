#include <iostream>
using namespace std;

/* Template classes are used to store different data types */

template <class T>
class Stack
{
	T *stackArr;
	int size, capacity;
public:
	Stack();
	~Stack();

	void push(T val);
	void pop();
	T top();
	void expand();
	int Length();
	bool empty();
};

