#include "LinkedList.h"

/* Classes Constructors */

template <class T>
Node<T>::Node()
{
	next = NULL;
	value = NULL;
}

template <class T>
LinkedList<T>::LinkedList()
{
	head = tail = NULL;
	size = 0;

	//Helper Variables for undo function
	lastOperation = "";
	lastElement = NULL;
	lastPos = lastPos2 = -1;
}

/* Returns List's Size */
template <class T>
int LinkedList<T>::Length()
{
	return size;
}

/* Insertion Functions */

template <class T>
void LinkedList<T>::push_back(T val)
{
	Node<T> *newNode = new Node<T>();
	newNode->value = val;

	if (size == 0)
	{
		head = newNode;
		tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = newNode;
	}

	size++;

	//Recording the operation (undo)
	lastElement = val;
	lastOperation = "push_back";
}

template <class T>
void LinkedList<T>::push_front(T val)
{
	Node<T> *newNode = new Node<T>();
	newNode->value = val;
	newNode->next = head;
	head = newNode;

	size++;

	//Recording the operation (undo)
	lastElement = val;
	lastOperation = "push_front";
}

template <class T>
void LinkedList<T>::insert_at(T val, int pos)
{
	if (pos == 0)
		return push_front(val);
	else if (pos == size - 1)
		return push_back(val);

	Node<T> *it = head;
	Node<T> *newNode = new Node<T>();
	newNode->value = val;

	for (int i = 1; i < pos; i++)
	{
		it = it->next;
	}

	newNode->next = it->next;
	it->next = newNode;

	size++;

	//Recording the operation (undo)
	lastElement = val;
	lastOperation = "insert_at";
	lastPos = pos;
}

/* Deletion Functions */

template <class T>
void LinkedList<T>::pop_back()
{
	lastElement = tail->value;
	lastOperation = "pop_back";

	Node<T> *it = head;
	for (int i = 1; i < size - 1; i++)
	{
		it = it->next;
	}

	tail = it;
	delete it->next;
	it->next = NULL;

	size--;
}

template <class T>
void LinkedList<T>::pop_front()
{
	lastElement = head->value;
	lastOperation = "pop_front";

	Node<T> *temp = head;
	head = head->next;
	delete temp;

	size--;
}

template <class T>
void LinkedList<T>::remove_at(int pos)
{
	if (pos == 0)
		return pop_front();
	else if (pos == size - 1)
		return pop_back();

	Node<T> *it = head;
	for (int i = 1; i < pos; i++)
	{
		it = it->next;
	}

	Node<T> *temp = it->next;

	//Recording the operation (undo)
	lastOperation = "remove_at";
	lastElement = temp->value;
	lastPos = pos;

	it->next = it->next->next;
	delete temp;

	size--;
}

/* Displays value at required index */
template <class T>
T LinkedList<T>::display_at(int pos)
{
	Node<T> *it = head;

	for (int i = 0; i < pos; i++)
	{
		it = it->next;
	}

	return it->value;
}

/* Displays all list elements on a single line seperated by spaces */
template <class T>
void LinkedList<T>::display_all()
{
	Node<T> *it = head;

	for (int i = 0; i < size; i++)
	{
		cout << it->value << " ";
		it = it->next;
	}
}

/* Swaps the values of two indices */
template <class T>
void LinkedList<T>::swap(int pos1, int pos2)
{
	if (pos1 == pos2)
		return;

	Node<T> *it = head, *temp;
	int Min = min(pos1, pos2), Max = max(pos1,pos2);

	for (int i = 1; i <= Min; i++)
	{
		it = it->next;
	}

	temp = it;

	for (int i = Min; i < Max; i++)
	{
		it = it->next;
	}

	T tempValue = it->value;
	it->value = temp->value;
	temp->value = tempValue;

	//Recording the operation (undo)
	lastOperation = "swap";
	lastPos = pos1;
	lastPos2 = pos2;
}

/* Removes repeated elements in the list */
template <class T>
void LinkedList<T>::make_unique()
{
	map <T, int> exist;
	map <int, int> remove;
	Node<T> *it = head;

	for (int i = 0; i < size; i++)
	{
		if (exist[it->value] == 1)
		{
			remove[i] = 1;
		}
		else {
			exist[it->value] = 1;
		}

		it = it->next;
	}

	int tempSize = size;
	it = head;
	for (int i = 0; i < tempSize; i++)
	{
		if (remove[i+1] == 1)
		{
			Node<T>* temp = it->next;
			it->next = it->next->next;

			if (remove[i+2] == 0)
				i++;

			delete temp;
			size--;
		}
		if (remove[i+1] == 0)
			it = it->next;
	}
}

template <class T>
void LinkedList<T>::undo()
{
	if (lastOperation == "push_back")
		pop_back();

	else if (lastOperation == "push_front")
		pop_front();

	else if (lastOperation == "pop_front")
		push_front(lastElement);

	else if (lastOperation == "pop_back")
		push_back(lastElement);

	else if (lastOperation == "insert_at")
		remove_at(lastPos);

	else if (lastOperation == "remove_at")
		insert_at(lastElement, lastPos);

	else if (lastOperation == "swap")
		swap(lastPos, lastPos2);
}

/* Deconstructor */
template <class T>
LinkedList<T>::~LinkedList()
{
	for (int i = 0; i < size; i++)
		pop_front();
}
