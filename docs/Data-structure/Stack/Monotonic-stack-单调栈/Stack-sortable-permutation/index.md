# Stack-sortable permutation

一、由于栈的操作只有`push`、`pop`、`top`，无法进行swap，因此对于栈排序的核心是: 

1、坚持"monotonic order"，即使当前stack中的element保持"monotonic"，一旦，待`push`的element和`top`之间不满足"monotonic order"，那么就需要将当前stack全部"pop and append" 到array中。因此，栈排序是可能需要分多次"pop and append" 的。

2、对于一个排好序的stack，"pop and append" 到一个array中，这个array是能够保持和stack相同的顺序的，这个过程好比是将一个叠有盘子的竖直柱子(stack)的横过来(array)。







## wikipedia [Stack-sortable permutation](https://en.wikipedia.org/wiki/Stack-sortable_permutation)

In [mathematics](https://en.wikipedia.org/wiki/Mathematics) and [computer science](https://en.wikipedia.org/wiki/Computer_science), a **stack-sortable permutation** (also called a **tree permutation**)[[1\]](https://en.wikipedia.org/wiki/Stack-sortable_permutation#cite_note-knott-1) is a [permutation](https://en.wikipedia.org/wiki/Permutation) whose elements may be [sorted](https://en.wikipedia.org/wiki/Sorting_algorithm) by an algorithm whose internal storage is limited to a single [stack data structure](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)). The stack-sortable permutations are exactly the permutations that do not contain the [permutation pattern](https://en.wikipedia.org/wiki/Permutation_pattern) 231; they are counted by the [Catalan numbers](https://en.wikipedia.org/wiki/Catalan_number), and may be placed in [bijection](https://en.wikipedia.org/wiki/Bijection) with many other combinatorial objects with the same counting function including [Dyck paths](https://en.wikipedia.org/wiki/Dyck_path) and [binary trees](https://en.wikipedia.org/wiki/Binary_tree). 

> NOTE: 
>
> 1、如何bijection with Dyck path、binary tree？

### Sorting with a stack

The problem of sorting an input sequence using a stack was first posed by [Knuth (1968)](https://en.wikipedia.org/wiki/Stack-sortable_permutation#CITEREFKnuth1968), who gave the following [linear time](https://en.wikipedia.org/wiki/Linear_time) algorithm (closely related to algorithms for the later [all nearest smaller values](https://en.wikipedia.org/wiki/All_nearest_smaller_values) problem): 

1、Initialize an empty stack

2、For each input value x:

​    2.1、While the stack is nonempty and *x* is larger than the top item on the stack, pop the stack to the output

> NOTE: 
>
> 栈顶到栈底是升序的，显然这个algorithm的输出是一个ascending array。

​    2.2、Push *x* onto the stack

> NOTE: 
>
> 栈中的元素，自栈顶开始是升序的

3、While the stack is nonempty, pop it to the output



Knuth observed that this algorithm correctly sorts some input sequences, and fails to sort others. For instance, the sequence 3,2,1 is correctly sorted: the three elements are all pushed onto the stack, and then popped in the order 1,2,3. However, the sequence 2,3,1 is not correctly sorted: the algorithm first pushes 2, and pops it when it sees the larger input value 3, causing 2 to be output before 1 rather than after it.

> NOTE: 
>
> 1、思考: 如何设计算法能够实现快速地判断？
>
> 



## geeksforgeeks [Check if an array is stack sortable](https://www.geeksforgeeks.org/check-array-stack-sortable/)

### 问题描述

Given an **array** of N distinct elements where elements are between 1 and N both inclusive, check if it is **stack-sortable** or not. An array `A[]` is said to be **stack sortable** if it can be stored in another `array B[]`, using a temporary stack `S`.

The operations that are allowed on array are:

1、Remove the starting element of array `A[]` and push it into the stack.

2、Remove the top element of the stack `S` and append it to the end of array `B`.

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



### 算法

Given, array `A[]` is a permutation of `[1, …, N]`, so let us suppose the initially `B[] = {0}`. Now we can observe that: 

1、We can only push an element in the stack `S` if the stack is empty or the current element is less than the top of the stack.（因为问题要求的是数组B要是ascending（升序） order的，所以stack `S`需要是降序的）

2、We can only pop from the stack only if the top of the stack is ![B[end] + 1](https://www.geeksforgeeks.org/wp-content/ql-cache/quicklatex.com-47cda539e896bdb6d65b750c2119b430_l3.svg) as the array `B[]` will contain {1, 2, 3, 4, …, n}. If we are not able to push the starting element of the array `A[]`, then the given array is Not Stack Sortable.

> NOTE: s
>
> 一、上述algorithm和 wikipedia [Stack-sortable permutation](https://en.wikipedia.org/wiki/Stack-sortable_permutation) 中描述的是有差异的，但是它们的原理大体是相同的，它们的主要差异
>
> 1、 wikipedia [Stack-sortable permutation](https://en.wikipedia.org/wiki/Stack-sortable_permutation) 是进行实际的sort；而本算法是判定，因此，在本算法中，不需要实际的使用一个output array。
>
> 下面是一些细节差异: 
>
> 1、这个algorithm中，"We can only pop from the stack only if the top of the stack is ![B[end] + 1](https://www.geeksforgeeks.org/wp-content/ql-cache/quicklatex.com-47cda539e896bdb6d65b750c2119b430_l3.svg)"，而  wikipedia [Stack-sortable permutation](https://en.wikipedia.org/wiki/Stack-sortable_permutation) 中，只要  "*x* is larger than the top item on the stack, pop the stack to the output"
>
> 2、下面这个algorithm，是从结果入手
>
> 二、问题中假设`B[]`是从1开始直至N的，下面这个algorithm充分运用了这个事实:
>
> 1、`B_end`的初始值是`1`，下一个期望的值是`B_end + 1`
>
> "We can only pop from the stack only if the top of the stack is ![B[end] + 1](https://www.geeksforgeeks.org/wp-content/ql-cache/quicklatex.com-47cda539e896bdb6d65b750c2119b430_l3.svg) as the array `B[]` will contain {1, 2, 3, 4, …, n}"



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

