# Linked List

This is a brief description of the Linked List class, its supported functions and their runtime.
----------
- A Linked List is a linear data structure where its elements are not consecutively organized in the memory, but rather consisting of several nodes connected with each other. Where each element carries a pointer refering to the subsequent element.
- Object constructor of the class takes one parameter which is the object's data type. 
(e.g. ```LinkedList <char> myLinkedlist;``` )

## Functions
### push_back:
- Takes one element as a parameter and adds it to the end of the list.
- Time Complexity: O(1)

### push_front:
- Takes one element as a parameter and adds it to the beginning of the list.
- Time Complexity: O(1)

### insert_at:
- Takes two parameters: First the element to be added to the list. Second the position at which to add this element.
- Time Complexity: O(n)

### pop_back:
- Doesn't take any parameters.
- Removes the last element in the list.
- Time Complexity: O(1)

### pop_front:
- Doesn't take any parameters.
- Removes the first element in the list.
- Time Complexity: O(1)

### remove_at:
- Takes one parameter, which is the index of the position at which to remove an element.
- Time Complexity: O(n)

### swap:
- Takes two parameters (indices) and swaps their values.
- Time Complexity: O(n)

## make_unique:
- Doesn't take any parameters.
- Removes all repeated values in the list, and leaves only one occurance of each.
- Time Complexity: O(n)

## Undo:
- Reverses the last operation made on the list (e.g. Reinserts last removed element).
- Time Complexity: Matches the time complexity of the function to be reversed.
- The function does not undo ```make_unique```.

### display_at:
- Takes one parameter (index) and returns the value this index node holds.
- Time Complexity: O(n)

## display_all:
- Prints all elements in the list on one line seperated by spaces.
- Time Complexity: O(n) *Compared to O(n^2) when using ```display_at()``` to print the whole list.

### Length:
- Doesn't take any parameters.
- Returns the number of elements in the list.







