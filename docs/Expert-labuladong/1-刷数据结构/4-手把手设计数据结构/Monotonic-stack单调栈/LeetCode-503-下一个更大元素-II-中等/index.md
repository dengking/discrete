# LeetCode [503. 下一个更大元素 II](https://leetcode-cn.com/problems/next-greater-element-ii/) 中等



## 我的解题

是参考的 labuladong [单调栈 Monotonic Stack 的使用](https://mp.weixin.qq.com/s/_b_QzXkL4e0y5241betVSg) 中的解法。



```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	vector<int> nextGreaterElements(vector<int> &nums)
	{
		int len = nums.size();
		vector<int> ret(len);

		stack<int> st;
		for (int i = len * 2 - 1; i >= 0; --i)
		{
			int index = i % len;
			while (!st.empty() && st.top() <= nums[index])
			{
				st.pop();
			}
			ret[index] = st.empty() ? -1 : st.top();
			st.push(nums[index]);
		}
		return ret;
	}
};

int main()
{
	Solution s;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g


```



## 官方解题

> 

