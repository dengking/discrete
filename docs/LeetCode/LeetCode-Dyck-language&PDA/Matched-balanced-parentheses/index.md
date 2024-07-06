# Matched balanced parentheses



## algorithm: stack

素材：

1、geeksforgeeks [Check for balanced parentheses in an expression](https://www.geeksforgeeks.org/check-for-balanced-parentheses-in-an-expression/)

2、labuladong

labuladong [3 分钟看懂如何判断括号的合法性](https://mp.weixin.qq.com/s/o2MjTSIC4FkPscF5MnLXMQ)

labuladong [手把手解决三道括号相关的算法题](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247487246&idx=1&sn=4a514020ce9dc8777e2d1d503188b62b&scene=21#wechat_redirect)



### geeksforgeeks [Check for balanced parentheses in an expression](https://www.geeksforgeeks.org/check-for-balanced-parentheses-in-an-expression/)



#### 问题描述

>**Input**: exp = “[()]{}{[()()]()}”
>**Output**: Balanced
>
>**Input**: exp = “[(])”
>**Output**: Not Balanced



#### Algorithm

```c++
// CPP program to check for balanced parenthesis. 
#include<bits/stdc++.h> 
using namespace std; 

// function to check if paranthesis are balanced 
bool areParanthesisBalanced(string expr) 
{ 
	stack<char> s; 
	char x; 

	// Traversing the Expression 
	for (int i=0; i<expr.length(); i++) 
	{ 
		if (expr[i]=='('||expr[i]=='['||expr[i]=='{') 
		{ 
			// Push the element in the stack 
			s.push(expr[i]); 
			continue; 
		} 

		// IF current current character is not opening 
		// bracket, then it must be closing. So stack 
		// cannot be empty at this point. 
		if (s.empty()) 
		return false; 

		switch (expr[i]) 
		{ 
		case ')': 

			// Store the top element in a 
			x = s.top(); 
			s.pop(); 
			if (x=='{' || x=='[') 
				return false; 
			break; 

		case '}': 

			// Store the top element in b 
			x = s.top(); 
			s.pop(); 
			if (x=='(' || x=='[') 
				return false; 
			break; 

		case ']': 

			// Store the top element in c 
			x = s.top(); 
			s.pop(); 
			if (x =='(' || x == '{') 
				return false; 
			break; 
		} 
	} 

	// Check Empty Stack 
	return (s.empty()); 
} 

// Driver program to test above function 
int main() 
{ 
	string expr = "{()}[]"; 

	if (areParanthesisBalanced(expr)) 
		cout << "Balanced"; 
	else
		cout << "Not Balanced"; 
	return 0; 
} 

```

