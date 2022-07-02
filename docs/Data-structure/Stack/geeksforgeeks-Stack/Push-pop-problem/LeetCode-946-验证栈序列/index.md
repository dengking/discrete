# leetcode [946. 验证栈序列](https://leetcode.cn/problems/validate-stack-sequences/)



## 我的解题

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

