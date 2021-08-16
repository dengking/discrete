# LeetCode [526. 优美的排列](https://leetcode-cn.com/problems/beautiful-arrangement/) 中等



## 我的解题: 回溯法 + 剪枝



```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int countArrangement(int n)
	{
		int count = 0;
		vector<int> v;
		for (int i = 1; i <= n; ++i)
		{
			v.push_back(i);
		}
		dfs(0, n, count, v);
		return count;
	}
	/**
	 * @brief
	 *
	 * @param index 排列的第index位
	 * @param n
	 * @param count
	 */
	void dfs(int index, int n, int &count, vector<int> &v)
	{
		if (index == n)
		{
			++count;
			return;
		}
		for (int i = index; i < n; ++i)
		{
			swap(v[i], v[index]);
			if (v[index] % (index + 1) == 0 || (index + 1) % v[index] == 0)
			{
				dfs(index + 1, n, count, v);
			}
			swap(v[i], v[index]);
		}
	}
};

int main()
{
	Solution s;
	s.countArrangement(5);
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g


```



## [官方解题](https://leetcode-cn.com/problems/beautiful-arrangement/solution/you-mei-de-pai-lie-by-leetcode-solution-vea2/)



### 方法二：状态压缩 + 动态规划

令 $f[\textit{mask}]$ 表示状态为 $\textit{mask}$ 时的可行方案总数，这样答案即为 $f[2^n - 1]$。

> NOTE: 
>
> $2^n - 1$ 对应的是 $\underbrace{1  1\cdots 1}_{n}$
>
> 

这样我们可以得到状态间的转移方程：
$$
f[\textit{mask}] = \sum_{i \in \textit{mask} ~\wedge \big( i+1 \mid \textit{num}(\textit{mask}) ~\vee~ \textit{num}(\textit{mask}) \mid i+1 \big) } f[\textit{mask} - 2^i]
$$
其中 $\textit{num}(\textit{mask})$ 表示二进制数 $\textit{mask}$中 $1$ 的个数，$x \mid y$ 表示 $x$ 可以整除 $y$。

