#include "BST.cpp"

int main()
{
	BST <int> myBst;
	
	cout << "Enter the number of nodes in the tree:" << endl;
	int nodes;
	cin >> nodes;

	cout << "Enter your tree elements" << endl;
	while (nodes--)
	{
		int temp;	
		cin >> temp;
		myBst.insert(temp);
	}

	cout << "Enter the node to be removed, or enter -1" << endl;
	int nodeToRemove;
	cin >> nodeToRemove;

	if (nodeToRemove != -1)
		myBst.remove(nodeToRemove);

	cout << "Your tree elements:" << endl;
	myBst.display(myBst.getRoot());

	return 0;
}