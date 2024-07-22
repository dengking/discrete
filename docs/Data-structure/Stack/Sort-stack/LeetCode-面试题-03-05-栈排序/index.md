# [LeetCode-面试题 03.05. 栈排序](https://leetcode.cn/problems/sort-of-stacks-lcci/)



## 我的解题

### 递归法

> NOTE: 
>
> 是按照 geeksforgeeks [Sort a stack using recursion](https://www.geeksforgeeks.org/sort-a-stack-using-recursion/) 中的算法写的

```C++
#include <bits/stdc++.h>
using namespace std;

class SortedStack
{
	stack<int> m_data;
public:
	SortedStack()
	{

	}

	void push(int val)
	{
		if (isEmpty() || val <= m_data.top()) // 满足顺序要求
		{
			m_data.push(val);
		}
		else // 栈顶元素更小，则先将它弹出，然后插入val
		{
			int temp = m_data.top();
			m_data.pop();
			push(val);
			push(temp);
		}
	}

	void pop()
	{
		if (!isEmpty())
		{
			m_data.pop();
		}
	}

	int peek()
	{
		if (isEmpty())
		{
			return -1;
		}
		else
		{
			return m_data.top();
		}

	}

	bool isEmpty()
	{
		return m_data.empty();
	}
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */
// Driver code
int main()
{

	return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g


```

