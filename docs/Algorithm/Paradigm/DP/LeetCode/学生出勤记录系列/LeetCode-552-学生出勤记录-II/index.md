# LeetCode [552. 学生出勤记录 II](https://leetcode.cn/problems/student-attendance-record-ii/) 困难





## [官方解题](https://leetcode.cn/problems/student-attendance-record-ii/solution/xue-sheng-chu-qin-ji-lu-ii-by-leetcode/)

> NOTE: 
>
> 一、这道题是典型的从**穷举**到**DP**
>
> 1、穷举
>
> "backtrack回溯-DFS state space-complete n-ary treeN叉树遍历-枚举穷举"
>
> 这种方式显然是会导致超时的，在 [【彤哥来刷题啦】一题六解：DFS -> 记忆化 -> DP -> 降维 -> 降维 -> 滚动数组](https://leetcode.cn/problems/student-attendance-record-ii/solution/tong-ge-lai-shua-ti-la-yi-ti-liu-jie-dfs-s5fa/) 中，演示了解法。
>
> 
>
> 2、DP
>
> 递归关系是难以想出的，需要思考"divide conquer-problem原问题subproblem子问题"
>
> 二、这道题，让我想到了"股票买卖"问题，它们的相同点是都有着很多的限制，即状态比较多，动态规划方程是比较复杂的
>
> 

### 方法一：动态规划

可以使用**动态规划**计算可奖励的出勤记录的数量。

由于可奖励的出勤记录要求缺勤次数少于 $2$​ 和连续迟到次数少于 $3$​，因此动态规划的**状态**由**总天数**、**缺勤次数**和**结尾连续迟到次数**决定（由于不会记录连续迟到次数等于或多于 $3$​ 的情况，因此非结尾的连续迟到次数一定少于 $3$​，只需要记录**结尾连续迟到次数**即可）。

> NOTE: 
>
> 一、"**结尾连续迟到次数**"是非常关键的，它决定了是否是一个可以获得奖励的记录，程序是不会记录无法获得奖励的记录的；因此可以通过"**结尾连续迟到次数**"来快速判断当前记录是否是一个可以获得奖励的记录。

定义 $\textit{dp}[i][j][k]$ 表示前 $i$ 天有 $j$ 个 $\text{'A'}$ 且结尾有连续 $k$ 个 $\text{'L'}$ 的可奖励的出勤记录的数量，其中 $0 \le i \le n$，$0 \le j \le 1$，$0 \le k \le 2$。

#### Base case

当 $i=0$ 时，没有任何出勤记录，此时 $\text{'A'}$ 的数量和结尾连续 $\text{'L'}$ 的数量一定是 $0$，因此**动态规划**的边界情况是 $\textit{dp}[0][0][0] = 1$。

#### 递归关系

> NOTE: 
>
> 一、需要考虑递归关系是难以想出的，需要思考"divide conquer-problem原问题subproblem子问题"
>
> 在各种选择下，状态的转移；
>
> 

当 $1 \le i \le n$ 时，$\textit{dp}[i][][]$ 的值从 $\textit{dp}[i-1][][]$ 的值转移得到，计算每个状态的值需要考虑第 $i$​ 天的出勤记录：

**一、如果第 $i$ 天的出勤记录是 $\text{'P'}$ **

如果第 $i$ 天的出勤记录是 $\text{'P'}$，则前 $i$ 天和前 $i-1$ 天的出勤记录相比，$\text{'A'}$ 的数量不变，结尾连续 $\text{'L'}$ 的数量清零，因此对 $0 \le j \le 1$，有

$$
\textit{dp}[i][j][0] := \textit{dp}[i][j][0] + \sum_{k=0}^2 \textit{dp}[i-1][j][k]
$$
> NOTE: 
>
> 需要注意，第三维度是需要清0的

**二、如果第 $i$​ 天的出勤记录是 $\text{'A'}$​**

如果第 $i$ 天的出勤记录是 $\text{'A'}$，则前 $i$ 天和前 $i-1$ 天的出勤记录相比，$\text{'A'}$ 的数量加 $1$，结尾连续 $\text{'L'}$ 的数量清零，此时要求前 $i-1$ 天的出勤记录记录中的 $\text{'A'}$ 的数量必须为 $0$，否则前 $i$ 天的出勤记录至少有 $2$ 个 $\text{'A'}$，不满足可奖励的条件，因此有
$$
\textit{dp}[i][1][0] := \textit{dp}[i][1][0] + \sum_{k=0}^2 \textit{dp}[i-1][0][k]
$$
**三、如果第 $i$ 天的出勤记录是 $\text{'L'}$**

如果第 $i$ 天的出勤记录是 $\text{'L'}$，则前 $i$ 天和前 $i-1$ 天的出勤记录相比，$\text{'A'}$ 的数量不变，结尾连续 $\text{'L'}$ 的数量加 $1$，此时要求前 $i-1$ 天的出勤记录记录中的结尾连续 $\text{'L'}$ 的数量不超过 $2$，否则前 $i$ 天的出勤记录的结尾至少有 $3$ 个 $\text{'L'}$，不满足可奖励的条件，因此对 $0 \le j \le 1$ 和 $1 \le k \le 2$，有
$$
\textit{dp}[i][j][k] := \textit{dp}[i][j][k] + \textit{dp}[i-1][j][k-1]
$$

> NOTE: 
>
> 上述关系的实现如下:
>
> ```C++
> // 第 i 天的出勤记录是 'L'
> for (int j = 0; j <= 1; ++j)
> {
>     for (int k = 1; k <= 2; ++k)
>     {
>         dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k - 1]) % MOD;
>     }
> }
> ```
>
> 

上述状态转移方程对于 $i=1$​ 也适用。

计算长度为 $n$ 的所有可奖励的出勤记录的数量，即为计算 $\textit{dp}[n][][] $的所有元素之和。计算过程中需要将结果对 $10^9+7$取模。

根据上述思路，可以得到时间复杂度和空间复杂度都是 $O(n)$ 的实现。

#### 完整代码

```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
	static constexpr int MOD = 1'000'000'007;
public:
	int checkRecord(int n)
	{
		vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3))); // 定义 dp[i][j][k] 表示前 i 天有 j 个 ‘A’ 且结尾有连续 k 个 ‘L’ 的可奖励的出勤记录的数量，其中 0≤i≤n，0≤j≤1，0≤k≤2。
		dp[0][0][0] = 1; // base case
		for (int i = 1; i <= n; ++i)
		{
			// 第 i 天的出勤记录是 'P'
			for (int j = 0; j <= 1; ++j)
			{
				for (int k = 0; k <= 2; ++k)
				{
					dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j][k]) % MOD;
				}
			}
			// 第 i 天的出勤记录是 'A'
			for (int k = 0; k <= 2; ++k)
			{
				dp[i][1][0] = (dp[i][1][0] + dp[i - 1][0][k]) % MOD;
			}
			// 第 i 天的出勤记录是 'L'
			for (int j = 0; j <= 1; ++j)
			{
				for (int k = 1; k <= 2; ++k)
				{
					dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k - 1]) % MOD;
				}
			}
		}
		int sum = 0;
		for (int j = 0; j <= 1; j++)
		{
			for (int k = 0; k <= 2; k++)
			{
				sum = (sum + dp[n][j][k]) % MOD;
			}
		}
		return sum;
	}
};

int main()
{
	Solution s;
}

// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g


```

#### 状态压缩

注意到 $\textit{dp}[i][][]$ 只会从 $\textit{dp}[i-1][][]$转移得到。因此可以将 $\textit{dp}$ 中的总天数的维度省略，将空间复杂度优化到 $O(1)$。





## [【彤哥来刷题啦】一题六解：DFS -> 记忆化 -> DP -> 降维 -> 降维 -> 滚动数组](https://leetcode.cn/problems/student-attendance-record-ii/solution/tong-ge-lai-shua-ti-la-yi-ti-liu-jie-dfs-s5fa/)
