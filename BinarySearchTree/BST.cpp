#include "BST.h"

/* Classes Constructors */

template <class T>
Node<T>::Node(T val)
{
	value = val;
	smaller = bigger = NULL;
}

template <class T>
BST<T>::BST()
{
	root = NULL;
	size = 0;
}

template <class T>
BST<T>::BST(T val)
{
	root = new Node<T>(val);
	size = 0;
}

/* BST Functions*/

/* Inserts new nodes into the appropriate place in the tree */
template <class T>
void BST<T>::insert(T val)
{
	//Inserting root if not existing
	if (root == NULL)
	{
		root = new Node<T>(val);
		return;
	}
	
	// Creating an iterator to traverse the tree
	Node<T> *it = root;
	while (true)
	{
		if (it->value < val)
		{
			if (it->bigger == NULL)
			{
				it->bigger = new Node<T>(val);
				break;
			}

			it = it->bigger;
		}
		else if (it->value > val)
		{
			if (it->smaller == NULL)
			{
				it->smaller = new Node<T>(val);
				break;
			}
			it = it->smaller;
		}
	}
	
	size++;
}

/* Prints tree elements in Pre-Order manner */
template <class T>
void BST<T>::display(Node<T> *currentNode)
{
	if (currentNode != NULL)
	{
		cout << currentNode->value << " ";
		display(currentNode->bigger);
		display(currentNode->smaller);
	}
}

/* Returns true if the node exists in the tree */
template <class T>
bool BST<T>::find(T val)
{
	Node<T> *temp = root;
	while (temp != NULL)
	{
		if (temp->value == val)
			return true;

		if (val < temp->value)
		{
			temp = temp->smaller;
		}
		else {
			temp = temp->bigger;
		}
	}
	return false;
}

/* 
Helper function for "isBalanced" function.
Returns the size of the sub-tree whose root is the given node
*/
template <class T>
int BST<T>::height(Node<T> *node)
{
	if (node == NULL)	
		return 0;

	return 1 + height(node->bigger) + height(node->smaller);
}

/* Returns true if the tree is balanced and false otherwise */
template <class T>
bool BST<T>::isBalanced(Node<T> *node)
{
	if (node ==	NULL)
	{
		return true;
	}
	else if (abs(height(node->bigger) - height(node->smaller)) > 1)
	{
		return false;
	}
	else {
		return isBalanced(node->bigger) & isBalanced(node->smaller);
	}
}

/* Returns the given node's level */
template <class T>
int BST<T>::getLevel(T val)
{
	Node<T> *temp = root;
	int counter = 0;

	while (temp != NULL)
	{
		if (temp->value == val)
			return counter;

		if (val < temp->value)
		{
			temp = temp->smaller;
		}
		else {
			temp = temp->bigger;
		}
		counter++;
	}
	return -1;
}

/* Rerturns a pointer to the roor function */
template <class T>
Node<T>* BST<T>::getRoot()
{
	return root;
}

/* Returns the tree size */
template <class T>
void BST<T>::getSize()
{
	return size;
}

template <class T>
BST<T>::~BST()
{
}
