# [Sort a stack using recursion](https://www.geeksforgeeks.org/sort-a-stack-using-recursion/)

## 问题描述

Given a stack, sort it using recursion. Use of any loop constructs like while, for..etc is not allowed. We can only use the following ADT functions on Stack S:

```C
is_empty(S)  : Tests whether stack is empty or not.
push(S)         : Adds new element to the stack.
pop(S)         : Removes top element from the stack.
top(S)         : Returns value of the top element. Note that this
               function does not remove element from the stack.
```

Example:

```
Input:  -3  <--- Top
        14 
        18 
        -5 
        30 

Output: 30  <--- Top
        18 
        14 
        -3 
        -5 
```

##  Algorithm 
This problem is mainly a variant of [Reverse stack using recursion](https://www.geeksforgeeks.org/reverse-a-stack-using-recursion). 

The idea of the solution is to hold all values in Function Call Stack until the stack becomes empty. When the stack becomes empty, insert all held items one by one in sorted order. Here sorted order is important. 

We can use below algorithm to sort stack elements:

```python
sortStack(stack S)
    if stack is not empty:
        temp = pop(S);  
        sortStack(S); 
        sortedInsert(S, temp);
```

Below algorithm is to insert element is sorted order:

```python
sortedInsert(Stack S, element)
    if stack is empty OR element > top element
        push(S, elem)
    else
        temp = pop(S)
        sortedInsert(S, element)
        push(S, temp)
```

### Implementation: 

Below is the implementation of above algorithm. 

```c
// C program to sort a stack using recursion 
#include <stdio.h> 
#include <stdlib.h> 

// Stack is represented using linked list 
struct stack 
{ 
	int data; 
	struct stack *next; 
}; 

// Utility function to initialize stack 
void initStack(struct stack **s) 
{ 
	*s = NULL; 
} 

// Utility function to chcek if stack is empty 
int isEmpty(struct stack *s) 
{ 
	if (s == NULL) 
		return 1; 
	return 0; 
} 

// Utility function to push an item to stack 
void push(struct stack **s, int x) 
{ 
	struct stack *p = (struct stack *)malloc(sizeof(*p)); 

	if (p == NULL) 
	{ 
		fprintf(stderr, "Memory allocation failed.\n"); 
		return; 
	} 

	p->data = x; 
	p->next = *s; 
	*s = p; 
} 

// Utility function to remove an item from stack 
int pop(struct stack **s) 
{ 
	int x; 
	struct stack *temp; 

	x = (*s)->data; 
	temp = *s; 
	(*s) = (*s)->next; 
	free(temp); 

	return x; 
} 

// Function to find top item 
int top(struct stack *s) 
{ 
	return (s->data); 
} 

// Recursive function to insert an item x in sorted way 
void sortedInsert(struct stack **s, int x) 
{ 
	// Base case: Either stack is empty or newly inserted 
	// item is greater than top (more than all existing) 
	if (isEmpty(*s) || x > top(*s)) 
	{ 
		push(s, x); 
		return; 
	} 

	// If top is greater, remove the top item and recur 
	int temp = pop(s); 
	sortedInsert(s, x); 

	// Put back the top item removed earlier 
	push(s, temp); 
} 

// Function to sort stack 
void sortStack(struct stack **s) 
{ 
	// If stack is not empty 
	if (!isEmpty(*s)) 
	{ 
		// Remove the top item 
		int x = pop(s); 

		// Sort remaining stack 
		sortStack(s); 

		// Push the top item back in sorted stack 
		sortedInsert(s, x); 
	} 
} 

// Utility function to print contents of stack 
void printStack(struct stack *s) 
{ 
	while (s) 
	{ 
		printf("%d ", s->data); 
		s = s->next; 
	} 
	printf("\n"); 
} 

// Driver Program 
int main(void) 
{ 
	struct stack *top; 

	initStack(&top); 
	push(&top, 30); 
	push(&top, -5); 
	push(&top, 18); 
	push(&top, 14); 
	push(&top, -3); 

	printf("Stack elements before sorting:\n"); 
	printStack(top); 

	sortStack(&top); 
	printf("\n\n"); 

	printf("Stack elements after sorting:\n"); 
	printStack(top); 

	return 0; 
} 

```





# [Sort a stack using a temporary stack](https://www.geeksforgeeks.org/sort-stack-using-temporary-stack/)

## 问题描述

Given a stack of integers, sort it in ascending（升序） order using another temporary stack.

**Examples:**

```
Input : [34, 3, 31, 98, 92, 23]
Output : [3, 23, 31, 34, 92, 98]

Input : [3, 5, 1, 4, 2, 8]
Output : [1, 2, 3, 4, 5, 8]
```

[Recommended: Please solve it on “***PRACTICE\***” first, before moving on to the solution.](https://practice.geeksforgeeks.org/problems/sort-a-stack/1)

##  algorithm 

1. Create a temporary stack say **tmpStack**.
2. While input stack is NOT empty do this:
   - Pop an element from input stack call it **temp**
   - while temporary stack is NOT empty and top of temporary stack is greater than temp,
     pop from temporary stack and push it to the input stack
   - push **temp** in temporary stack
3. The sorted numbers are in tmpStack

 

Here is a dry run of above pseudo code. 

```
input: [34, 3, 31, 98, 92, 23]

Element taken out: 23
input: [34, 3, 31, 98, 92]
tmpStack: [23]

Element taken out: 92
input: [34, 3, 31, 98]
tmpStack: [23, 92]

Element taken out: 98
input: [34, 3, 31]
tmpStack: [23, 92, 98]

Element taken out: 31
input: [34, 3, 98, 92]
tmpStack: [23, 31]

Element taken out: 92
input: [34, 3, 98]
tmpStack: [23, 31, 92]

Element taken out: 98
input: [34, 3]
tmpStack: [23, 31, 92, 98]

Element taken out: 3
input: [34, 98, 92, 31, 23]
tmpStack: [3]

Element taken out: 23
input: [34, 98, 92, 31]
tmpStack: [3, 23]

Element taken out: 31
input: [34, 98, 92]
tmpStack: [3, 23, 31]

Element taken out: 92
input: [34, 98]
tmpStack: [3, 23, 31, 92]

Element taken out: 98
input: [34]
tmpStack: [3, 23, 31, 92, 98]

Element taken out: 34
input: [98, 92]
tmpStack: [3, 23, 31, 34]

Element taken out: 92
input: [98]
tmpStack: [3, 23, 31, 34, 92]

Element taken out: 98
input: []
tmpStack: [3, 23, 31, 34, 92, 98]

final sorted list: [3, 23, 31, 34, 92, 98]
```





```c++

// C++ program to sort a stack using an 
// auxiliary stack. 
#include <bits/stdc++.h> 
using namespace std; 

// This function return the sorted stack 
stack<int> sortStack(stack<int> &input) 
{ 
	stack<int> tmpStack; 

	while (!input.empty()) 
	{ 
		// pop out the first element 
		int tmp = input.top(); 
		input.pop(); 

		// while temporary stack is not empty and top 
		// of stack is greater than temp 
		while (!tmpStack.empty() && tmpStack.top() > tmp) 
		{ 
			// pop from temporary stack and push 
			// it to the input stack 
			input.push(tmpStack.top()); 
			tmpStack.pop(); 
		} 

		// push temp in tempory of stack 
		tmpStack.push(tmp); 
	} 

	return tmpStack; 
} 

// main function 
int main() 
{ 
	stack<int> input; 
	input.push(34); 
	input.push(3); 
	input.push(31); 
	input.push(98); 
	input.push(92); 
	input.push(23); 

	// This is the temporary stack 
	stack<int> tmpStack = sortStack(input); 
	cout << "Sorted numbers are:\n"; 

	while (!tmpStack.empty()) 
	{ 
		cout << tmpStack.top()<< " "; 
		tmpStack.pop(); 
	} 
} 

```

***SUMMARY*** : 上述算法非常类似于[All nearest smaller values](https://en.wikipedia.org/wiki/All_nearest_smaller_values)

