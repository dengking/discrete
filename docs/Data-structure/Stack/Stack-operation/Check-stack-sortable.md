# [Check if an array is stack sortable](https://www.geeksforgeeks.org/check-array-stack-sortable/)

## 问题描述

Given an **array** of N distinct elements where elements are between 1 and N both inclusive, check if it is **stack-sortable** or not. An array `A[]` is said to be **stack sortable** if it can be stored in another `array B[]`, using a temporary stack `S`.

The operations that are allowed on array are:

1. Remove the starting element of array `A[]` and push it into the stack.
2. Remove the top element of the stack `S` and append it to the end of array `B`.

If all the element of `A[]` can be moved to `B[]` by performing these operations such that array `B` is sorted in ascending（升序） order, then array `A[]` is **stack sortable**.



 Examples: 

```
Input : A[] = { 3, 2, 1 }
Output : YES
Explanation : 
Step 1: Remove the starting element of array A[] 
        and push it in the stack S. ( Operation 1)
        That makes A[] = { 2, 1 } ; Stack S = { 3 }
Step 2: Operation 1
        That makes A[] = { 1 } Stack S = { 3, 2 }
Step 3: Operation 1
        That makes A[] = {} Stack S = { 3, 2, 1 }
Step 4: Operation 2
        That makes Stack S = { 3, 2 } B[] = { 1 }
Step 5: Operation 2
        That makes Stack S = { 3 } B[] = { 1, 2 }
Step 6: Operation 2
        That makes Stack S = {} B[] = { 1, 2, 3 }
  
Input : A[] = { 2, 3, 1}
Output : NO
```

[Recommended: Please try your approach on ***{IDE}\*** first, before moving on to the solution.](https://ide.geeksforgeeks.org/)

## 算法

 Given, array `A[]` is a permutation of `[1, …, N]`, so let us suppose the initially `B[] = {0}`. Now we can observe that: 

1. We can only push an element in the stack `S` if the stack is empty or the current element is less than the top of the stack.（因为问题要求的是数组B要是ascending（升序） order的，所以stack `S`需要是降序的）
2. We can only pop from the stack only if the top of the stack is ![B[end] + 1](https://www.geeksforgeeks.org/wp-content/ql-cache/quicklatex.com-47cda539e896bdb6d65b750c2119b430_l3.svg) as the array `B[]` will contain {1, 2, 3, 4, …, n}.

***SUMMARY*** : 问题中假设`A[]`是从1开始直至N的；

If we are not able to push the starting element of the array `A[]`, then the given array is Not Stack Sortable.

Below is the implementation of above idea:



```c++
// C++ implementation of above approach. 
#include <bits/stdc++.h> 
using namespace std; 

// Function to check if A[] is 
// Stack Sortable or Not. 
bool check(int A[], int N) 
{ 
	// Stack S 
	stack<int> S; 

	// Pointer to the end value of array B. 
	int B_end = 0; 

	// Traversing each element of A[] from starting 
	// Checking if there is a valid operation 
	// that can be performed. 
	for (int i = 0; i < N; i++) 
	{ 
		// If the stack is not empty 
		if (!S.empty()) 
		{ 
			// Top of the Stack. 
			int top = S.top(); 

			// If the top of the stack is 
			// Equal to B_end+1, we will pop it 
			// And increment B_end by 1. 
			while (top == B_end + 1) 
			{ 
				// if current top is equal to 
				// B_end+1, we will increment 
				// B_end to B_end+1 
				B_end = B_end + 1; 

				// Pop the top element. 
				S.pop(); 

				// If the stack is empty We cannot 
				// further perfom this operation. 
				// Therefore break 
				if (S.empty()) 
				{ 
					break; 
				} 

				// Current Top 
				top = S.top(); 
			} 

			// If stack is empty 
			// Push the Current element 
			if (S.empty()) { 
				S.push(A[i]); 
			} 
			else
			{ 
				top = S.top(); 

				// If the Current element of the array A[] 
				// if smaller than the top of the stack 
				// We can push it in the Stack. 
				if (A[i] < top) 
				{ 
					S.push(A[i]); 
				} 
				// Else We cannot sort the array 
				// Using any valid operations. 
				else
				{ 
					// Not Stack Sortable 
					return false; 
				} 
			} 
		} 
		else
		{ 
			// If the stack is empty push the current 
			// element in the stack. 
			S.push(A[i]); 
		} 
	} 

	// Stack Sortable 
	return true; 
} 

// Driver's Code 
int main() 
{ 
	int A[] = { 4, 1, 2, 3 }; 
	int N = sizeof(A) / sizeof(A[0]); 
	check(A, N)? cout<<"YES": cout<<"NO"; 
	return 0; 
} 

```

