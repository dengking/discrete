# [Stack | Set 3 (Reverse a string using stack)](https://www.geeksforgeeks.org/stack-set-3-reverse-string-using-stack/)

## 问题描述

Given a string, reverse it using stack. For example “GeeksQuiz” should be converted to “ziuQskeeG”.

## 算法1

Following is simple algorithm to reverse a string using stack.

```
1) Create an empty stack.
2) One by one push all characters of string to stack.
3) One by one pop all characters from stack and put 
   them back to string.
```

[Recommended: Please solve it on “***PRACTICE\***” first, before moving on to the solution.](https://practice.geeksforgeeks.org/problems/reverse-a-string-using-stack/1)

### 实现

```c++
// CPP program to reverse a string using stack 
#include <bits/stdc++.h> 
using namespace std; 

// A structure to represent a stack 
class Stack 
{ 
	public: 
	int top; 
	unsigned capacity; 
	char* array; 
}; 

// function to create a stack of given 
// capacity. It initializes size of stack as 0 
Stack* createStack(unsigned capacity) 
{ 
	Stack* stack = new Stack(); 
	stack->capacity = capacity; 
	stack->top = -1; 
	stack->array = new char[(stack->capacity * sizeof(char))]; 
	return stack; 
} 

// Stack is full when top is equal to the last index 
int isFull(Stack* stack) 
{ return stack->top == stack->capacity - 1; } 

// Stack is empty when top is equal to -1 
int isEmpty(Stack* stack) 
{ return stack->top == -1; } 

// Function to add an item to stack. 
// It increases top by 1 
void push(Stack* stack, char item) 
{ 
	if (isFull(stack)) 
		return; 
	stack->array[++stack->top] = item; 
} 

// Function to remove an item from stack. 
// It decreases top by 1 
char pop(Stack* stack) 
{ 
	if (isEmpty(stack)) 
		return -1; 
	return stack->array[stack->top--]; 
} 

// A stack based function to reverse a string 
void reverse(char str[]) 
{ 
	// Create a stack of capacity 
	//equal to length of string 
	int n = strlen(str); 
	Stack* stack = createStack(n); 

	// Push all characters of string to stack 
	int i; 
	for (i = 0; i < n; i++) 
		push(stack, str[i]); 

	// Pop all characters of string and 
	// put them back to str 
	for (i = 0; i < n; i++) 
		str[i] = pop(stack); 
} 

// Driver code 
int main() 
{ 
	char str[] = "GeeksQuiz"; 

	reverse(str); 
	cout << "Reversed string is " << str; 

	return 0; 
} 

// This code is contributed by rathbhupendra 

```

 **Time Complexity:** O(n) where n is number of characters in stack.
**Auxiliary Space:** O(n) for stack. 

## 算法2

 A string can also be reversed without using any auxiliary space. Following C, Java, C# and Python programs to implement reverse without using stack. 

```c++
// C++ program to reverse a string without using stack 
#include <bits/stdc++.h> 
using namespace std; 

// A utility function to swap two characters 
void swap(char *a, char *b) 
{ 
	char temp = *a; 
	*a = *b; 
	*b = temp; 
} 

// A stack based function to reverse a string 
void reverse(char str[]) 
{ 
	// get size of string 
	int n = strlen(str), i; 

	for (i = 0; i < n/2; i++) 
		swap(&str[i], &str[n-i-1]); 
} 

// Driver program to test above functions 
int main() 
{ 
	char str[] = "abc"; 

	reverse(str); 
	cout<<"Reversed string is "<< str; 

	return 0; 
} 

//This is code is contributed by rathbhupendra 

```

