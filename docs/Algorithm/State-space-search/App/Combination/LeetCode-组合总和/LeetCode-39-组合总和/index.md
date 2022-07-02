# LeetCode [39. 组合总和](https://leetcode.cn/problems/combination-sum/)



## 我的解题

这是典型的穷举问题；

这个问题，和背包问题非常类似；

```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
	vector<int> m_combi;
	vector<vector<int>> m_res;
public:
	vector<vector<int>> combinationSum(vector<int> &candidates, int target)
	{

		DFS(candidates, target, 0);
		return m_res;
	}
	void DFS(vector<int> &candidates, int target, int index)
	{
		if (target == 0)
		{
			m_res.push_back(m_combi);
			return;
		}
		if (index == candidates.size())
		{
			return;
		}
		DFS(candidates, target, index + 1); // 不选择第index个元素

		if (target - candidates[index] >= 0) // 选择第index个元素
		{
			m_combi.push_back(candidates[index]);
			DFS(candidates, target - candidates[index], index);
			m_combi.pop_back();
		}
	}
};

int main()
{

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g


```

