#include "Stack.h"

/* Stack Class Constructor */
template <class T>
Stack<T>::Stack()
{
	stackArr = new T[100];
	size = 0;
	capacity = 100;
}

/* Add a new element to the top of the stack */
template <class T>
void Stack<T>::push(T val)
{
	//Expanding array size if it is full
	if (size == capacity)	
		expand();

	if (size == 0)
	{
		stackArr[0] = val;
	}
	else {
		stackArr[size] = val;
	}

	size++;
}

/* Remove the top element from the stack */
template <class T>
void Stack<T>::pop()
{
	size--;
}

/* Return the top element in the stack*/
template <class T>
T Stack<T>::top()
{
	return stackArr[size - 1];
}

/* Expand the stack size to double the current size */
template <class T>
void Stack<T>::expand()
{
	//Declaring a new array with bigger size
	T *newArr = new T[capacity * 2];

	//Keeping a pointer on the existing array
	T *temp = stackArr;

	//Adding existing elements to the new array
	for (int i = 0; i < size; i++)	   
	{
		newArr[i] = stackArr[i];
	}

	stackArr = newArr;
	capacity *= 2;

	//Deleting previous stackArr
	delete[]temp;
}

/* Return the stack size */
template <class T>
int Stack<T>::Length()
{
	return size;
}

/* Check whether the stack is empty or not*/
template <class T>
bool Stack<T>::empty()
{
	if (size == 0)
		return true;
	else
		return false;
}

/* Stack Class Deconstructor */
template <class T>
Stack<T>::~Stack()
{
	delete[]stackArr;
}
