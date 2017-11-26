#include <iostream>
using namespace std;

/* Template classes are used to enable storing different data types */

template <class T>
class Node
{
public:
	T value;
	Node<T> *smaller, *bigger;
	Node(T val);
};

template <class T>
class BST
{
	Node<T> *root;
	int size;
public:
	BST();
	BST(T val);
	~BST();

	void insert(T val);
	void display(Node<T> *currentNode);

	bool find(T val);
	int height(Node<T>* node);
	bool isBalanced(Node<T> *node);

	void getSize();
	int getLevel(T val);
	Node<T>* getRoot();
};

