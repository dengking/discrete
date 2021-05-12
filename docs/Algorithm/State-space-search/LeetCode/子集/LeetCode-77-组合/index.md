# leetcode [77. 组合](https://leetcode-cn.com/problems/combinations/)



## 我的解题



### 一个错误的解题

```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
	vector<vector<int>> ans; // 最终答案
	vector<int> t; // 存放临时的答案

public:
	vector<vector<int>> combine(int n, int k)
	{
		dfs(n, 0, k);
		return ans;
	}
	/**
	 * @brief
	 *
	 * @param cur 递归深度
	 * @param solution_len 解的长度
	 */
	void dfs(int n, int cur, int solution_len)
	{
		if (cur == solution_len)
		{
			ans.push_back(t);
			return;
		}
		for (int i = 1; i <= n; ++i)
		{
			t.push_back(i);
			dfs(n, cur + 1, solution_len);
			t.pop_back();
		}
	}
};

template<typename ...Args>
ostream& operator <<(ostream &stream, const vector<Args...> &v)
{
	stream << "[";
	for (auto &&i : v)
	{
		stream << i << ",";
	}
	stream << "]";
	return stream;
}
int main()
{
	Solution s;
	vector<vector<int>> combs = s.combine(4, 2);
	cout << combs.size() << endl;
	cout << combs << endl;
}
// g++ test.cpp -pedantic -Wall -Wextra --std=c++11

```

输出如下:

```C++
16
[[1,1,],[1,2,],[1,3,],[1,4,],[2,1,],[2,2,],[2,3,],[2,4,],[3,1,],[3,2,],[3,3,],[3,4,],[4,1,],[4,2,],[4,3,],[4,4,],]
```

