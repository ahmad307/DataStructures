/* Main.cpp file to test LinkedList class */

#include "LinkedList.cpp"

int main()
{
	//Creating a LinkedList object of integer type
	LinkedList<int> myLinkedList;

	cout << "Enter the List's size" << endl;
	int size;
	cin >> size;

	cout << "Enter the List's elements" << endl;
	for (int i = 0; i < size; i++)
	{
		int element;
		cin >> element;
		myLinkedList.push_back(element);
	}

	//Removing repeated elements in the list
	myLinkedList.make_unique();

	myLinkedList.insert_at(99, 0);
	myLinkedList.undo();	//Undoing last operation

	cout << "Unique elements in your list:" << endl;
	for (int i = 0; i < myLinkedList.Length(); i++)
	{
		cout << myLinkedList.display_at(i) << " ";
	}
	cout << endl;

	return 0;
}
