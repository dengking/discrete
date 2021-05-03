# [Reverse a stack using recursion](https://www.geeksforgeeks.org/reverse-a-stack-using-recursion/)

## 问题描述

Write a program to reverse a stack using recursion. You are not allowed to use loop constructs like `while`, `for`..etc, and you can only use the following ADT functions on Stack `S`: 

```c
isEmpty(S)
push(S)
pop(S) 
```

***SUMMARY*** : 上述三个操作是这个问题的限制，也就是说在我们的实现中只能够使用上述三个操作；该问题的另外一个限制是只能够使用递归，不能够使用`while`；

[Recommended: Please try your approach on ***{IDE}\*** first, before moving on to the solution.](https://ide.geeksforgeeks.org/)

## 算法

The idea of the solution is to hold all values in **Function Call Stack** until **the stack** becomes **empty**. When the stack becomes **empty**, insert all held items one by one at the **bottom** of the stack.

For example, let the **input stack** be

```
    1  <-- top
    2
    3
    4   
First 4 is inserted at the bottom.
    4 <-- top

Then 3 is inserted at the bottom
    4 <-- top    
    3

Then 2 is inserted at the bottom
    4 <-- top    
    3 
    2
     
Then 1 is inserted at the bottom
    4 <-- top    
    3 
    2
    1
```

So we need a function that inserts at the **bottom of a stack** using the above given basic stack function.

**void insertAtBottom(():** First pops all stack items and stores the popped item in **function call stack** using **recursion**. And when stack becomes empty, pushes new item and all items stored in call stack.

**void reverse():** This function mainly uses `insertAtBottom()` to pop all items one by one and insert the popped items at the bottom.



```C++
// C++ code to reverse a 
// stack using recursion 
#include<bits/stdc++.h> 
using namespace std; 

// using std::stack for 
// stack implementation 
stack<char> st; 

// intializing a string to store 
// result of reversed stack 
string ns; 

// Below is a recursive function 
// that inserts an element 
// at the bottom of a stack. 
char insert_at_bottom(char x) 
{ 

	if(st.size() == 0) 
	st.push(x); 

	else
	{ 
		
		// All items are held in Function Call 
		// Stack until we reach end of the stack 
		// When the stack becomes empty, the 
		// st.size() becomes 0, the above if 
		// part is executed and the item is 
		// inserted at the bottom 
			
		char a = st.top(); 
		st.pop(); 
		insert_at_bottom(x); 

		// push allthe items held in 
		// Function Call Stack 
		// once the item is inserted 
		// at the bottom 
		st.push(a); 
	} 
} 

// Below is the function that 
// reverses the given stack using 
// insert_at_bottom() 
char reverse() 
{ 
	if(st.size()>0) 
	{ 
		
		// Hold all items in Function 
		// Call Stack until we 
		// reach end of the stack 
		char x = st.top(); 
		st.pop(); 
		reverse(); 
		
		// Insert all the items held 
		// in Function Call Stack 
		// one by one from the bottom 
		// to top. Every item is 
		// inserted at the bottom 
		insert_at_bottom(x); 
	} 
} 

// Driver Code 
int main() 
{ 
	
	// push elements into 
	// the stack 
	st.push('1'); 
	st.push('2'); 
	st.push('3'); 
	st.push('4'); 
	
	cout<<"Original Stack"<<endl; 
	
	// print the elements 
	// of original stack 
	cout<<"1"<<" "<<"2"<<" "
		<<"3"<<" "<<"4"
		<<endl; 
	
	// function to reverse 
	// the stack 
	reverse(); 
	cout<<"Reversed Stack"
		<<endl; 
	
	// storing values of reversed 
	// stack into a string for display 
	while(!st.empty()) 
	{ 
		char p=st.top(); 
		st.pop(); 
		ns+=p; 
	} 
	
	//display of reversed stack 
	cout<<ns[3]<<" "<<ns[2]<<" "
		<<ns[1]<<" "<<ns[0]<<endl; 
	return 0; 
} 

// This code is contributed by Gautam Singh 

```







***SUMMARY*** : 上述解法其实本质上来说是借助两个stack来实现reverse，每个stack类似于 [Tower of Hanoi](https://en.wikipedia.org/wiki/Tower_of_Hanoi) 中的一根柱子；在这个例子中，我需要借鉴的一个技巧就是对function call stack的运用，这是一个非常好的demo；

### `reverse`

这个函数其实是将`st`柱子清空，然后再将栈中的元素给放回来；

### `insertAtBottom`

```c++
// Below is a recursive function 
// that inserts an element 
// at the bottom of a stack. 
char insert_at_bottom(char x) 
{ 

	if(st.size() == 0) 
	st.push(x); 

	else
	{ 
		
		// All items are held in Function Call 
		// Stack until we reach end of the stack 
		// When the stack becomes empty, the 
		// st.size() becomes 0, the above if 
		// part is executed and the item is 
		// inserted at the bottom 
			
		char a = st.top(); 
		st.pop(); 
		insert_at_bottom(x); 

		// push allthe items held in 
		// Function Call Stack 
		// once the item is inserted 
		// at the bottom 
		st.push(a); 
	} 
} 
```

上述函数所实现的其实可以这样形象的来理解：我们把`st`看做是一个柱子，上面摞着一堆的碟子，上述过程就是将`st`柱子上的元素移动到另一个柱子上，这个柱子就是function call stack；当`st`柱子为空的时候，就将元素`x`放到该柱子上，然后将function call stack柱子上的元素移回来；上述代码是使用递归来实现的；这个递归，我觉得比较类似于结构化递归，即沿着栈来进行递归；





# [Reverse a stack without using extra space in O(n)](https://www.geeksforgeeks.org/reverse-stack-without-using-extra-space/)