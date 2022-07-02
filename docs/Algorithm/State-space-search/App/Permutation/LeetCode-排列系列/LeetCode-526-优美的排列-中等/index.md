# LeetCode [526. 优美的排列](https://leetcode.cn/problems/beautiful-arrangement/) 中等



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



## [官方解题](https://leetcode.cn/problems/beautiful-arrangement/solution/you-mei-de-pai-lie-by-leetcode-solution-vea2/)



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



## 【宫水三叶】详解两种状态压缩 DP 思路

利用数据范围不超过 $15$，我们可以使用「状态压缩 DP」进行求解。

**使用一个二进制数表示当前哪些数已被选，哪些数未被选，目的是为了可以使用位运算进行加速。**

假设变量 `state` 存放了「当前数的使用情况」，当我们需要检查值为 k 的数是否被使用时，可以使用位运算



**定义 `f[i][state]`为考虑前 `i` 个数，且当前选择方案为 `state` 的所有方案数量。**

