#include "BST.cpp"

int main()
{
	BST <int> myBst;
	
	cout << "Enter the number of nodes in the tree:" << endl;
	int nodes;
	cin >> nodes;

	while (nodes--)
	{
		int temp;	cin >> temp;
		myBst.insert(temp);
	}

	cout << "Your tree elements:" << endl;
	myBst.display(myBst.getRoot());

	return 0;
}