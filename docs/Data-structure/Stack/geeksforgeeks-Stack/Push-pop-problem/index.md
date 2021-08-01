# 前言

1、最近在catalan数的相关问题，发现这个问题经常作为一个例子出现，所以有必要对它好好地进行分析；

2、使用parenthesis来进行分析:

入栈对应的是正括号，出栈对应的是反括号。



## geeksforgeeks [Check if the given push and pop sequences of Stack is valid or not](https://www.geeksforgeeks.org/check-if-the-given-push-and-pop-sequences-of-stack-is-valid-or-not/) 

Given `push[]` and `pop[]` sequences with distinct values. The task is to check if this could have been the result of a sequence of push and pop operations on an initially empty stack. Return “True” if it otherwise returns “False”. 

###  **Examples:** 

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

###  Approach 

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





## csdn [出栈入栈顺序规律](https://blog.csdn.net/qq_1932568757/article/details/82752325)



## 计数

入栈为开括号、出栈为闭括号，对于stack而言，它必须要括号匹配，因此，所有可能的入栈、出栈就是Catalan number。