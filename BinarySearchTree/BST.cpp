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

template <class T>
void BST<T>::remove(T val)
{
	//Creating two pointers to traverse the tree & to mark the node to be removed
	Node<T> *it = root, *nodeToRemove;

	//Searching the tree for the node to be removed
	while (true)
	{
		if (val > it->value)
			it = it->bigger;
		else if (val < it->value)
			it = it->smaller;
		else {
			nodeToRemove = it;
			break;
		}
	}

	//Setting a pointer to the parent of nodeToRemove
	Node<T> *parent = findParent(nodeToRemove->value);
	
	//Directly deleting the node if no children found
	if (nodeToRemove->smaller == NULL && nodeToRemove->bigger == NULL)
	{
		if (nodeToRemove == root)	//Dealing with root to avoid 'findParent' returning zero
			root = NULL;
		else if (parent->bigger->value == val)
			parent->bigger = NULL;
		else 
			parent->smaller = NULL;
		return;
	}

	//Removing the node if it has 1 child
	if (nodeToRemove->bigger == NULL)
	{
		//Dealing with root to avoid 'findParent' returning zero
		if (nodeToRemove == root)
		{
			it = nodeToRemove->smaller;
			while (it->smaller != NULL || it->bigger != NULL)
			{
				if (it->smaller != NULL)
					it = it->smaller;
				else
					it = it->bigger;
			}
			Node<T> *itParent = findParent(it->value);
			swap(nodeToRemove->value, it->value);
			itParent->smaller = NULL;

			return;
		}

		if (parent->value > nodeToRemove->value)
		{
			parent->smaller = nodeToRemove->smaller;
		}
		else if (parent->value < nodeToRemove->value)
		{
			parent->bigger = nodeToRemove->smaller;
		}

		return;
	}	
	else if (nodeToRemove->smaller == NULL)
	{
		//Dealing with root to avoid 'findParent' returning zero
		if (nodeToRemove == root)
		{
			it = nodeToRemove->bigger;
			while (it->smaller != NULL || it->bigger != NULL)
			{
				if (it->smaller != NULL)
					it = it->smaller;
				else
					it = it->bigger;
			}
			Node<T> *itParent = findParent(it->value);
			swap(nodeToRemove->value, it->value);

			if (nodeToRemove->value > itParent->value)
				itParent->bigger = NULL;
			else
				itParent->smaller = NULL;
			
			return;
		}

		if (parent->value > nodeToRemove->value)
		{
			parent->smaller = nodeToRemove->bigger;
		}
		else if (parent->value < nodeToRemove->value)
		{
			parent->bigger = nodeToRemove->bigger;
		}

		return;
	}

	/* Removing node if it has 2 children */

	//Reaching smallest node in nodeToRemove right sub-tree
	Node<T> *smallestNode = nodeToRemove->bigger;
	while (smallestNode->smaller != NULL || smallestNode->bigger != NULL)
	{
		if (smallestNode->smaller != NULL)
			smallestNode = smallestNode->smaller;
		else
			smallestNode = smallestNode->bigger;
	}

	//Saving the node to be removed value
	T smallestNodeValue = smallestNode->value;

	//Removing the node
	Node<T> *smallestNodeParent = findParent(smallestNode->value);
	if (smallestNodeParent->value > smallestNode->value)
	{
		smallestNodeParent->smaller = NULL;
	}
	else {
		smallestNodeParent->bigger = NULL;
	}

	//Substituting the nodeToRemove value with the smallest value in its right sub-tree
	nodeToRemove->value = smallestNodeValue;
}

/* Returns zero if given the root as a parameter*/
template <class T>
Node<T>* BST<T>::findParent(T val)
{
	//Checking if the inquiry node exists in the tree
	if (find(val) == false)
		return 0;

	//Checking if the node has no parent
	if (val == root->value)
		return 0;


	Node<T> *it = root;

	while (true)
	{
		//Returning current node if one of its children matches the node required
		if ((it->smaller != NULL && it->smaller->value == val) || (it->bigger != NULL && it->bigger->value == val))
			return it;

		//Traversing the tree
		if (val > it->value)
			it = it->bigger;
		else if (val < it->value)
			it = it->smaller;
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
