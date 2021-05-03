# [Check if a queue can be sorted into another queue using a stack](https://www.geeksforgeeks.org/check-queue-can-sorted-another-queue-using-stack/)

## 问题描述

Given a Queue consisting of first **n** natural numbers (in random order). The task is to check whether the given Queue elements can be arranged in **increasing order** in another Queue using a stack. The operation allowed are:
\1. Push and pop elements from the stack
\2. Pop (Or enqueue) from the given Queue.
\3. Push (Or Dequeue) in the another Queue. 

 **Examples**  

```
Input : Queue[] = { 5, 1, 2, 3, 4 }
Output : Yes
Pop the first element of the given Queue i.e 5.
Push 5 into the stack.
Now, pop all the elements of the given Queue and push them to
second Queue.
Now, pop element 5 in the stack and push it to the second Queue.
 
Input : Queue[] = { 5, 1, 2, 6, 3, 4 }
Output : No
Push 5 to stack.
Pop 1, 2 from given Queue and push it to another Queue.
Pop 6 from given Queue and push to stack.
Pop 3, 4 from given Queue and push to second Queue.
Now, from using any of above operation, we cannot push 5
into the second Queue because it is below the 6 in the stack.
```



## 算法

Observe, second Queue (which will contain the sorted element) takes inputs (or enqueue elements) either from given Queue or Stack. So, next expected (which will initially be 1) element must be present as a front element of given Queue or top element of the Stack. So, simply simulate the process for the second Queue by initializing the expected element as 1. And check if we can get expected element from the front of the given Queue or from the top of the Stack. If we cannot take it from the either of them then pop the front element of given Queue and push it in the Stack.

Also, observe, that the stack must also be sorted at each instance i.e the element at the top of the stack must be smallest in the stack. For eg. let x > y, then x will always be expected before y. So, x cannot be pushed before y in the stack. Therefore, we cannot push element with the higher value on the top of the element having lesser value.

Algorithm:
\1. Initialize the expected_element = 1
\2. Check if either front element of given Queue or top element of the stack have expected_element
….a) If yes, increment expected_element by 1, repeat step 2.
….b) Else, pop front of Queue and push it to the stack. If the popped element is greater than top of the Stack, return “No”.

Below is the implementation of this approach:

```c++
// CPP Program to check if a queue of first 
// n natural number can be sorted using a stack 
#include <bits/stdc++.h> 
using namespace std; 

// Function to check if given queue element 
// can be sorted into another queue using a 
// stack. 
bool checkSorted(int n, queue<int>& q) 
{ 
	stack<int> st; 
	int expected = 1; 
	int fnt; 

	// while given Queue is not empty. 
	while (!q.empty()) { 
		fnt = q.front(); 
		q.pop(); 

		// if front element is the expected element 
		if (fnt == expected) 
			expected++; 

		else { 
			// if stack is empty, push the element 
			if (st.empty()) { 
				st.push(fnt); 
			} 

			// if top element is less than element which 
			// need to be pushed, then return fasle. 
			else if (!st.empty() && st.top() < fnt) { 
				return false; 
			} 

			// else push into the stack. 
			else
				st.push(fnt); 
		} 

		// while expected element are coming from 
		// stack, pop them out. 
		while (!st.empty() && st.top() == expected) { 
			st.pop(); 
			expected++; 
		} 
	} 

	// if the final expected element value is equal 
	// to initial Queue size and the stack is empty. 
	if (expected - 1 == n && st.empty()) 
		return true; 

	return false; 
} 

// Driven Program 
int main() 
{ 
	queue<int> q; 
	q.push(5); 
	q.push(1); 
	q.push(2); 
	q.push(3); 
	q.push(4); 

	int n = q.size(); 

	(checkSorted(n, q) ? (cout << "Yes") : 
						(cout << "No")); 

	return 0; 
} 

```

