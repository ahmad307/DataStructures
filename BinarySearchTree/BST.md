# Binary Search Tree

This is a brief description of the Binary Search Tree class, its supported functions and their runtime.
----------
- A binary tree is a tree where each of its nodes has no more than two children.
- A Binary Search Tree is a binary tree where one of each the node's children must be of a bigger value than the node's value, and the other must be of a value smaller than the node's value.
- Binary Search Trees play a great role in sorting elements and allows inserting and removing elements in a relatively short time. O(logN) on average.
- Object constructor of the class takes one argument; the object's data type (e.g. ```BST <int> myBST```. And can take an additional value as the tree's root (e.g. ```BST <int> myBST(5)```.


## Functions
### insert:
- Takes one element as a parameter and inserts it the appropriate position in the tree.
- Time Complexity: O(logN) (Avg)

### display:
- Takes a node pointer as a parameter.
- Prints the all sub-tree elements with the given parameter as its root.
- Prints all elements on one line in "Pre-Order" manner.
- Prints the whole tree if the given pointer refers to the root node.
- Time Complexity: O(N)

### remove:
- Takes one element as a parameter.
- Removes the element from the tree, without affecting the binary search tree properties.
- Time Complexity: O(logN) (Avg)

### findParent:
- Helper function for ```remove()``` function.
- Takes one element as a parameter.
- Returns a pointer to its parent node.
- Time Complexity: O(logN) (Avg)

### find:
- Takes one element as a parameter.
- Returns True if the element is found in the tree and False otherwise.
- Time Complexity: O(N)

### height:
- Takes a node pointer as a parameter.
- Helper function for "isBalanced" function.
- Returns the height of the sub-tree with the given node as its root.
- Time Complexity: O(n)

### isBalanced:
- Takes one element as a parameter, which is the root of the subtree to check if balanced.
- Returns True if the sub-tree is balanced (i.e. for every node the difference between the size of the right child's sub-tree differs at most by 1 from the size of the left child's sub-tree) and False if it's not.
- Returns whether whole tree is balanced if given a pointer to the root node (See "getRoot" function).
- Time Complexity: O(N)

### getSize:
- Doesn't take any parameters.
- Returns the number of elements in the tree.
- Time Complexity: O(1)

### getLevel:
- Takes one element as a parameter.
- Returns the level at which the given node is found.
- Time Complexity: O(N)

### getRoot:
- Doesn't take any parameters.
- Returns a pointer to the root node.
- Useful when using "isBalanced" function.
- Time Complexity: O(1)

