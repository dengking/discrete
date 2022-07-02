# LeetCode [155. 最小栈](https://leetcode.cn/problems/min-stack/) 简单



## 使用辅助栈



```C++
#include <bits/stdc++.h>
using namespace std;

class MinStack
{
	stack<int> m_data;
	stack<int> m_min;
public:
	/** initialize your data structure here. */
	MinStack()
	{
		m_min.push(INT_MAX);
	}

	void push(int val)
	{
		m_data.push(val);
		m_min.push(min(val, m_min.top()));
	}

	void pop()
	{
		m_data.pop();
		m_min.pop();
	}

	int top()
	{
		return m_data.top();
	}

	int getMin()
	{
		return m_min.top();
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
int main()
{
	Solution s;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g


```

## LeetCode [一个栈同时保存当前值和栈内最小值](https://leetcode.cn/problems/min-stack/solution/zui-yi-dong-yi-ge-zhan-tong-shi-bao-cun-dang-qian-/)

> NOTE: 
>
> 这种方式也比较简单