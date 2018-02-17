#include "Heap.cpp"

using namespace std;

int main()
{
	int n;	cin >> n;
	Heap<int> myHeap(n);

	//Building the minumum heap
	for (int i = 0; i < n; i++)
	{
		int x;	cin >> x;
		myHeap.insert(x);
	}

	myHeap.displayAll();

	cout << "Deleting the Minumum Node" << endl;

	myHeap.deleteMin();
	myHeap.displayAll();

	return 0;
}