# Minumum Heap

This is a brief description of the Minumum Heap class and its supported functions and their runtime.
---------
- A minimum heap is a tree-like data structure (on the abstract level) where each node has a maximum of two children who must carry a value **greater** than the node's value.

- The heap maintains an O(logN) access and deletion time by ordering the heap elements in an array where: 
    - ith element's parent is at index (i/2)
    - ith element's left child is at index (2*i)
    - ith element's right child is at index (2*i + 1) 
    
- Object constructor of the class takes one argument; the object's data type (e.g. ```Heap <int> myHeap```).

## Functions
### insert:
- Takes one element as a parameter and inserts it in its appropiate place in the heap.
- Time Complexity: O(logN)

### deleteMin:
- Takes one element as a parameter and removes it from the heap, yet maintaining the heap's order.
- Time Complexity: O(logN)

### displayAll
- Takes no parameters and displays heap array elements in their array order.
- Time Complexity: O(N)