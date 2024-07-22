# Stack permutation

所谓stack permutation，指的是给定一个permutation，将它经过stack转换为另外一个permutation。

geeksforgeeks [Stack Permutations (Check if an array is stack permutation of other)](https://www.geeksforgeeks.org/stack-permutations-check-if-an-array-is-stack-permutation-of-other/) 

> A ***stack permutation*** is a permutation of objects in the given input queue which is done by transferring elements from the input queue to the output queue with the help of a stack and the built-in **push** and **pop** functions.
>
> The rules are: 
>
> - Only ***dequeue*** from the input queue.
> - Use inbuilt ***push***, and ***pop*** functions in the single stack.
> - Stack and input queue must be ***empty*** at the ***end***.
> - Only ***enqueue*** to the output queue.
>
> There are a huge number of permutations possible using a stack for a single input queue. 

gpt-4-vision: stack permutation and stack-sortabe permutation

> A stack permutation is a permutation of elements that can be obtained by passing the elements through a stack. The process involves pushing the incoming elements onto the stack and popping them out to form a new sequence, the **stack permutation**. The order in which elements are pushed and popped is subject to the stack's last-in-first-out (LIFO) principle.
>
> A **stack-sortable permutation**, on the other hand, is a specific type of stack permutation that can be completely sorted into its natural increasing order using a single stack. Not all permutations are stack-sortable due to the constraints imposed by the stack's LIFO nature.
>
> Here's a more detailed comparison:
>
> **Stack Permutation:**
> - Any permutation that can be achieved by a sequence of push and pop operations on a stack.
> - The resulting permutation may or may not be in sorted order.
> - The process does not necessarily sort the input; it just rearranges it according to stack operations.
>
> **Stack-sortable Permutation:**
> - A permutation that can be sorted into ascending order using a single stack.
> - There is a specific sequence of push and pop operations that results in a sorted sequence.
> - Not all permutations are stack-sortable. For example, the permutation [2, 1, 3] is stack-sortable, but [3, 1, 2] is not because once 3 is pushed onto the stack, it cannot be popped out before 1 and 2, which violates the sorted order.
>
> To determine if a permutation is stack-sortable, you can simulate the stack operations. If you can push and pop all elements such that the output sequence is in ascending order, the permutation is stack-sortable. If at any point you are forced to pop an element out of order, the permutation is not stack-sortable.
>
> The concept of stack-sortable permutations is closely related to the Catalan numbers, as mentioned earlier, because the number of stack-sortable permutations of length `n` is the `n`-th Catalan number. This is the same number that counts various other combinatorial structures, such as binary trees with `n` nodes, Dyck paths of semi-length `n`, and well-formed parentheses expressions with `n` pairs of parentheses.



## Application

1. 判定一个permutation是否是另外一个permutation的stack permutation(一般称为push-pop-problem)
2. stack-sortable-permutation(在下一章节进行介绍)



## Push-pop-problem

下面文章所讨论的是同一个问题:

1. geeksforgeeks [Stack Permutations (Check if an array is stack permutation of other)](https://www.geeksforgeeks.org/stack-permutations-check-if-an-array-is-stack-permutation-of-other/) 

2. geeksforgeeks [Check if the given push and pop sequences of Stack is valid or not](https://www.geeksforgeeks.org/check-if-the-given-push-and-pop-sequences-of-stack-is-valid-or-not/) 

3. csdn [出栈入栈顺序规律](https://blog.csdn.net/qq_1932568757/article/details/82752325)

pop sequence其实就是stack permutation，检查这类问题的算法其实就是模拟: 既然给定了push sequence，那么就顺次进行push，问题是何时进行pop？显然就是当stack中的元素和pop sequence中的匹配的时候，就需要进行pop了。


### geeksforgeeks [Check if the given push and pop sequences of Stack is valid or not](https://www.geeksforgeeks.org/check-if-the-given-push-and-pop-sequences-of-stack-is-valid-or-not/) 

Given `push[]` and `pop[]` sequences with distinct values. The task is to check if this could have been the result of a sequence of push and pop operations on an initially empty stack. Return “True” if it otherwise returns “False”. 

####  **Examples:** 

```
Input: pushed = { 1, 2, 3, 4, 5 }, popped = { 4, 5, 3, 2, 1 }
Output: True
Following sequence can be performed:
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1

Input: pushed = { 1, 2, 3, 4, 5 }, popped = { 4, 3, 5, 1, 2 }
Output: False
1 can't be popped before 2.
```

> NOTE: 上述`pushed`和`popped`中的元素是可以交替的，但是并不是所有的`pushed`和`popped`序列的组合都是合法的，有很多是不合法的，那如何快速地判断哪些是合法的，哪些是不合法的呢？

####  Approach 

If the element `X` has been pushed to the stack then check if the top element in the `pop[]` sequence is `X` or not. If it is `X` then pop it right now else top of the `push[]` sequence will be changed and make the sequences invalid. So, similarly do the same for all the elements and check if the stack is empty or not in the last. If empty then print **True** else print **False**. 

 Below is the implementation of above approach: 

```c++
// C++ implementation of above approach 
#include <iostream> 
#include <stack> 
  
using namespace std; 
  
// Function to check validity of stack sequence 
bool validateStackSequence(int pushed[], int popped[], int len){ 
      
    // maintain count of popped elements 
    int j = 0; 
      
    // an empty stack 
    stack <int> st; 
    for(int i = 0; i < len; i++){ 
        st.push(pushed[i]); 
          
        // check if appended value is next to be popped out 
        while (!st.empty() && j < len && st.top() == popped[j]){ 
            st.pop(); 
            j++; 
        } 
    } 
      
    return j == len; 
} 
  
// Driver code 
int main() 
{ 
   int pushed[] = {1, 2, 3, 4, 5}; 
   int popped[] = {4, 5, 3, 2, 1}; 
   int len = sizeof(pushed)/sizeof(pushed[0]); 
     
   cout << (validateStackSequence(pushed, popped, len) ? "True" : "False"); 
     
   return 0; 
} 
  
// This code is contributed by Rituraj Jain 
```



```python
# Function to check validity of stack sequence 
def validateStackSequence(pushed, popped): 
    # maintain count of popped elements 
    j = 0
  
    # an empty stack 
    stack = [] 
  
    for x in pushed: 
        stack.append(x) 
  
        # check if appended value is next to be popped out 
        while stack and j < len(popped) and stack[-1] == popped[j]: 
            stack.pop() 
            j = j + 1
  
    return j == len(popped) 
  
  
# Driver code 
pushed = [1, 2, 3, 4, 5] 
popped = [4, 5, 3, 2, 1] 
print(validateStackSequence(pushed, popped)) 
```



### [LeetCode-946. 验证栈序列](https://leetcode.cn/problems/validate-stack-sequences/) 

[LeetCode-剑指 Offer 31. 栈的压入、弹出序列](https://leetcode.cn/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/)



#### C++

是参考 geeksforgeeks [Check if the given push and pop sequences of Stack is valid or not](https://www.geeksforgeeks.org/check-if-the-given-push-and-pop-sequences-of-stack-is-valid-or-not/) 中给出的算法写出的。

```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
	{
		int len = pushed.size();
		stack<int> st;
		int popped_index = 0;
		for (int i = 0; i < len; ++i)
		{
			st.push(pushed[i]);
			while (!st.empty() && st.top() == popped[popped_index])
			{
				st.pop();
				++popped_index;
			}
		}
		return popped_index == len;
	}
};

// Driver code
int main()
{

	return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g


```

