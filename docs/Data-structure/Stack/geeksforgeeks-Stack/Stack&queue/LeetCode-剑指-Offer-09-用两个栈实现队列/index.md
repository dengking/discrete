# leetcode [剑指 Offer 09. 用两个栈实现队列](https://leetcode.cn/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/)



## 我的解答

```C++
/* Program to implement a stack
 using two queue */
#include <bits/stdc++.h>
using namespace std;

class CQueue
{
	stack<int> s1, s2;
public:
	CQueue()
	{

	}

	void appendTail(int value)
	{
		s1.push(value);
	}

	int deleteHead()
	{
		if (s1.empty() && s2.empty())
		{
			return -1;
		}
		if (s2.empty())
		{
			while (!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
		}
		int ret = s2.top();
		s2.pop();
		return ret;
	}
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
// Driver code
int main()
{
	CQueue q;
	for (int i = 0; i < 100; ++i)
	{
		q.appendTail(i);
	}
	for (int i = 0; i < 100; ++i)
	{
		cout << q.deleteHead() << ",";
	}
	cout << endl;
	return 0;
}
// g++ test.cpp

```

