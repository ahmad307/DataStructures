#include "Stack.cpp"

int main()
{
	Stack <int> myStack;

	cout << "Enter the number of elements to add to the stack:" << endl;
	int size, element;
	cin >> size;

	//Adding the elements to the stack
	for (int i = 0; i < size; i++)
	{
		cin >> element;
		myStack.push(element);
	}
	
	//Displaying the stack in FILO order

	cout << "Stack elements in FILO order:" << endl;
	while (myStack.empty() == false)
	{
		cout << myStack.top() << endl;
		myStack.pop();
	}

	return 0;
}