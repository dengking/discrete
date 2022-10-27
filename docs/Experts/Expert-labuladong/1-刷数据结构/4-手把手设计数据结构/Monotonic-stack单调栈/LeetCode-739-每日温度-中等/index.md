# [LeetCode-739. 每日温度](https://leetcode.cn/problems/daily-temperatures/) 中等



## 我的解题

```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	vector<int> dailyTemperatures(vector<int> &temperatures)
	{
		int len = temperatures.size();
		vector<int> ret(len, 0);
		stack<pair<int, int>> st;
		for (int i = len - 1; i >= 0; --i)
		{
			while (!st.empty() && st.top().second <= temperatures[i])
			{
				st.pop();
			}
			ret[i] = st.empty() ? 0 : st.top().first - i;
			st.emplace(i, temperatures[i]);
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

