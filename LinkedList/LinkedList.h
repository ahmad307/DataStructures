#include<iostream>
#include <algorithm>
#include <map>

using namespace std;

/* Template classes are used to enable storage of different data types */

template <class T>
class Node
{
public:
	Node<T>* next;
	T value;
	Node();
};

template <class T>
class LinkedList
{
	Node<T>* head;
	Node<T>* tail;
	int size;

	//Helper Variables for undo function
	string lastOperation;
	T lastElement;
	int lastPos, lastPos2;
public:
	LinkedList();
	~LinkedList();

	int Length();
	void push_back(T val);
	void push_front(T val);
	void insert_at(T val, int pos);

	void pop_back();
	void pop_front();
	void remove_at(int pos);

	T display_at(int pos);
	void swap(int pos1, int pos2);
	void make_unique();
	void undo();
};

