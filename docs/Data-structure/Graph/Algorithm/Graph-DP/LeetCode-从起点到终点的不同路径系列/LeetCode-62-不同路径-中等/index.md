# LeetCode [62. 不同路径](https://leetcode.cn/problems/unique-paths/) 中等

是在阅读 宫水三叶 [【动态规划/总结必看】从一道入门题与你分享关于 DP 的分析技巧](https://mp.weixin.qq.com/s/G_KYdjrhQQO43-t0Jw8iBA) 时，发现的这道题。

## 我的解题

一、状态转移方程

1、起点和终点

起点: `a[0][0]`

终点: `a[m-1][n-1]`

2、选择: 

每个位置有两个选择：

a、从它的左边到达；

b、从它的上边到达；

3、

状态（其实对应的是问题的规模、dfs的入参）: 所处的位置，使用坐标 `[i][j]` 表示

4、状态转移方程、递归方程: 

令 `a[i][j]` 为 从 start到 位置 `[i][j]` 的不同路径数

```
a[i][j] = a[i][j-1] + a[i-1][j] # i>0 && j>0
base case:
a[i][j] = a[i][j-1] = 1(i=0)
a[i][j] = a[i-1][j] = 1(j=0)
```



### 完整代码

```C++
// LeetCode.h: 标准系统包含文件的包含文件
// 或项目特定的包含文件。

#pragma once

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> dp(m, vector<int>(n));
    dp[0][0] = 1;//这是DP计数问题的常见base case
		for (int i = 0; i < m; ++i)
		{
			dp[i][0] = 1;
		}
		for (int i = 0; i < n; ++i)
		{
			dp[0][i] = 1;
		}
		for (int row = 1; row < m; ++row)
			for (int col = 1; col < n; ++col)
			{
				dp[row][col] = dp[row - 1][col] + dp[row][col - 1];
			}
		return dp[m - 1][n - 1];
	}
};

int main()
{

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```



### fibonacci DP计数问题

在 emre.me [Coding Patterns: Staircase (DP)](https://emre.me/coding-patterns/staircase/) 中将上述问题归入到了"Staircase (DP)"即"fibonacci DP计数问题"范畴中，从上述实现来看，我觉得是比较符合的。