# Stack-sortable permutation

一、由于栈的操作只有`push`、`pop`、`top`，无法进行swap，因此对于栈排序的核心是: 

1、坚持"monotonic order"，即让当前stack中的element保持"monotonic"，一旦，待`push`的element和`top`之间不满足"monotonic order"，那么就需要将当前stack全部"pop and append" 到array中。因此，栈排序是可能需要分多次"pop and append" 的。

2、对于一个排好序的stack，"pop and append" 到一个array中，这个array是能够保持和stack相同的顺序的，这个过程好比是将一个叠有盘子的竖直柱子(stack)的横过来(array)。



## wikipedia [Stack-sortable permutation](https://en.wikipedia.org/wiki/Stack-sortable_permutation)

In [mathematics](https://en.wikipedia.org/wiki/Mathematics) and [computer science](https://en.wikipedia.org/wiki/Computer_science), a **stack-sortable permutation** (also called a **tree permutation**)[[1\]](https://en.wikipedia.org/wiki/Stack-sortable_permutation#cite_note-knott-1) is a [permutation](https://en.wikipedia.org/wiki/Permutation) whose elements may be [sorted](https://en.wikipedia.org/wiki/Sorting_algorithm) by an algorithm whose internal storage is limited to a single [stack data structure](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)). The stack-sortable permutations are exactly the permutations that do not contain the [permutation pattern](https://en.wikipedia.org/wiki/Permutation_pattern) 231; they are counted by the [Catalan numbers](https://en.wikipedia.org/wiki/Catalan_number), and may be placed in [bijection](https://en.wikipedia.org/wiki/Bijection) with many other combinatorial objects with the same counting function including [Dyck paths](https://en.wikipedia.org/wiki/Dyck_path) and [binary trees](https://en.wikipedia.org/wiki/Binary_tree). 

> NOTE: 
>
> 1、如何bijection with Dyck path、binary tree？这是我目前还没有搞清楚的

### Sorting with a stack

#### Algorithm

> NOTE: 
>
> 1、这个algorithm是有缺陷的，它无法处理 "2,3,1 pattern"，因此在实际application中，是无法直接使用这个algorithm的。

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

#### 2,3,1 pattern

Knuth observed that this algorithm correctly sorts some input sequences, and fails to sort others. For instance, the sequence 3,2,1 is correctly sorted: the three elements are all pushed onto the stack, and then popped in the order 1,2,3. However, the sequence 2,3,1 is not correctly sorted: the algorithm first pushes 2, and pops it when it sees the larger input value 3, causing 2 to be output before 1 rather than after it.

> NOTE: 
>
> 1、思考: 如何设计算法能够实现快速地判断？后面给出了判定算法
>
> 



Because this algorithm is a [comparison sort](https://en.wanweibaike.com/wiki-Comparison_sort), its success or failure does not depend on the numerical values of the input sequence, but only on their relative order; that is, an input may be described by the [permutation](https://en.wanweibaike.com/wiki-Permutation) needed to form that input from a sorted sequence of the same length. Knuth characterized the permutations that this algorithm correctly sorts as being exactly the permutations that do not contain the [permutation pattern](https://en.wanweibaike.com/wiki-Permutation_pattern) 231: three elements *x*, *y*, and *z*, appearing in the input in that respective order, with *z* < *x* < *y*. Moreover, he observed that, if the algorithm fails to sort an input, then that input cannot be sorted with a single stack.



### Bijections and enumeration

> NOTE: 
>
> 1、没有读懂

## 判断算法

1、下面的给出的判定算法是有局限性的: 输入需要是连续的数字，否则无法判断

### geeksforgeeks [Check if an array is stack sortable](https://www.geeksforgeeks.org/check-array-stack-sortable/)

#### 问题描述

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



#### 算法

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
>
> 三、下面的代码是需要进行特殊说明的
>
> ```C++
> 				// If the Current element of the array A[]
> 				// if smaller than the top of the stack
> 				// We can push it in the Stack.
> 				if (A[i] < top)
> 				{
> 					S.push(A[i]);
> 				}
> 				// Else We cannot sort the array
> 				// Using any valid operations.
> 				else
> 				{
> 					// Not Stack Sortable
> 					return false;
> 				}
> 
> ```
>
> 结合下面的例子来进行理解
>
> ```C++
> 4、1、2、5、3
> ```
>
> 
>
> 当`A[i]`为5的时候，此时`top`为4，显然`A[i] > top`。在 wikipedia [Stack-sortable permutation](https://en.wikipedia.org/wiki/Stack-sortable_permutation) 的算法中，对于这种情况，它采取的措施是`pop`，这个算法没有采取`pop`，而是直接返回false。这样做有什么道理？
>
> 1、这个算法是保证有序的、连续递增的，它通过下面的方式来进行实现，它所有的`pop`都是基于"We can only pop from the stack only if the top of the stack is ![B[end] + 1](https://www.geeksforgeeks.org/wp-content/ql-cache/quicklatex.com-47cda539e896bdb6d65b750c2119b430_l3.svg) as the array  will contain {1, 2, 3, 4, …, n}"的，它的这个是能够保证严格的、连续的有序的(1、2、3的模式)。
>
> 2、 wikipedia [Stack-sortable permutation](https://en.wikipedia.org/wiki/Stack-sortable_permutation) 中的算法是有缺陷的，它无法处理"2,3,1 pattern"，这个算法能够处理"2,3,1 pattern"，原因在于上面那段代码，显然当`2，3`就会进入到这个分支:
>
> ```C++
>                 else
> 				{
> 					// Not Stack Sortable
> 					return false;
> 				}
> ```
>
> 



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
			if (S.empty())
			{
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
	check(A, N) ? cout << "YES" : cout << "NO" << std::endl;

	int B[] = { 2, 3, 1 };
	N = sizeof(B) / sizeof(B[0]);
	check(B, N) ? cout << "YES" : cout << "NO" << std::endl;
	return 0;
}
// g++ test.cpp

```

> NOTE: 
>
> 1、输出为:
>
> ```C++
> YES
> NO
> ```
>
> 



### geeksforgeeks [Check if a queue can be sorted into another queue using a stack](https://www.geeksforgeeks.org/check-queue-can-sorted-another-queue-using-stack/)

#### 问题描述

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



#### 算法

Observe, second Queue (which will contain the sorted element) takes inputs (or enqueue elements) either from given Queue or Stack. So, next expected (which will initially be 1) element must be present as a front element of given Queue or top element of the Stack. So, simply simulate the process for the second Queue by initializing the expected element as 1. And check if we can get expected element from the front of the given Queue or from the top of the Stack. If we cannot take it from the either of them then pop the front element of given Queue and push it in the Stack.

Also, observe, that the stack must also be sorted at each instance i.e the element at the top of the stack must be smallest in the stack. For eg. let x > y, then x will always be expected before y. So, x cannot be pushed before y in the stack. Therefore, we cannot push element with the higher value on the top of the element having lesser value.

Algorithm:
\1. Initialize the expected_element = 1
\2. Check if either front element of given Queue or top element of the stack have expected_element
….a) If yes, increment expected_element by 1, repeat step 2.
….b) Else, pop front of Queue and push it to the stack. If the popped element is greater than top of the Stack, return “No”.

> NOTE: 
>
> 1、这个algorithm，其实和 geeksforgeeks [Check if an array is stack sortable](https://www.geeksforgeeks.org/check-array-stack-sortable/) 类似
>
>  

Below is the implementation of this approach:

```c++
// CPP Program to check if a queue of first
// n natural number can be sorted using a stack
#include <bits/stdc++.h>
using namespace std;

// Function to check if given queue element
// can be sorted into another queue using a
// stack.
bool checkSorted(int n, queue<int> &q)
{
	stack<int> st;
	int expected = 1;
	int fnt;

	// while given Queue is not empty.
	while (!q.empty())
	{
		fnt = q.front();
		q.pop();

		// if front element is the expected element
		if (fnt == expected)
		{
			expected++;
		}
		else
		{
			// if stack is empty, push the element
			if (st.empty())
			{
				st.push(fnt);
			}
			// if top element is less than element which
			// need to be pushed, then return fasle.
			else if (!st.empty() && st.top() < fnt)
			{
				return false;
			}
			// else push into the stack.
			else
			{
				st.push(fnt);
			}
		}

		// while expected element are coming from
		// stack, pop them out.
		while (!st.empty() && st.top() == expected)
		{
			st.pop();
			expected++;
		}
	}
	// if the final expected element value is equal
	// to initial Queue size and the stack is empty.
	if (expected - 1 == n && st.empty())
	{
		return true;
	}
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

	(checkSorted(n, q) ? (cout << "Yes") : (cout << "No"));

	return 0;
}
// g++ test.cpp

```

