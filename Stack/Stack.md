# Stack
This is a brief description of the Stack class, its supported functions and their runtime.
----------
- A Stack is an array-like data structure that stores elements in "Last in First out" manner. In other words, the last inserted element is always on top of the stack and it is the first element that can be removed.
- The default stack size in this class is 100, but the size can be expanded if the number of inserted elements > 100.

## Functions
### push:
- Takes one element as a parameter and adds it on top of the stack.
- Time Complexity: O(1) ( O(1) is the average time, as the stack size might need to be expanded)

### pop:
- Removes the element on top of the stack.
- Doesn't take any parameters.
- Time Complexity: O(1)

### top:
- Returns the element on top of the stack.
- Time Comlexity: O(1)

### expand:
- Helper function used in ```push``` function to expand the stack size to double the current size.
- Time Complexity: O(n)

### Length:
- Returns the number of elements in the stack.
- Time Complexity: O(1)

### empty:
- Boolean function that returns ```true``` if the number of elements in the stack is equal to zero and ```false``` otherwise.
- Time Complexity: O(1)
