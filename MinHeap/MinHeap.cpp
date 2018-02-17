#include "Heap.h"

/* Class Constructor */
template <class T>
Heap<T>::Heap(int size)
{
	arr = new T[size];
	elementsCount = 0;
}

/* Inserts element into appropriate place in The Min Heap */
template <class T>
void Heap<T>::insert(T val)
{
	arr[elementsCount] = val;

	int index = elementsCount + 1;
	while (arr[(index / 2) - 1] > arr[index - 1])
	{
		swap(arr[(index / 2) - 1], arr[index - 1]);
		index /= 2;
	}

	elementsCount++;
}

/* Removes the Min element from the Heap */
template <class T>
void Heap<T>::deleteMin()
{
	swap(arr[0], arr[elementsCount - 1]);
	
	int p1 = 0, p2;

	//Setting p2 to the min of the 2 children
	int temp = (p1 * 2) + 1;
	if (arr[temp] < arr[temp + 1])  p2 = temp;
	else  p2 = temp + 1;

	while (arr[p1] > arr[p2] && p2<elementsCount-1)
	{
		swap(arr[p1], arr[p2]);
		p1 = p2;

		//Setting p2 to the min of the 2 children
		temp = (p1 * 2) + 1;
		if (arr[temp] < arr[temp + 1])  p2 = temp;
		else  p2 = temp + 1;
	}

	elementsCount--;
}

/* Prints Min Heap elemnts' space seperated*/
template <class T>
void Heap<T>::displayAll()
{
	for (int i = 0; i < elementsCount; i++)
	{
		std::cout << arr[i] << " ";
	}
	cout << endl;
}