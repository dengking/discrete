# LeetCode [62. 不同路径](https://leetcode-cn.com/problems/unique-paths/) 中等



## 我的解题

起点: `a[0][0]`

终点: `a[m-1][n-1]`

选择: 

每个位置有两个选择

状态: 所处的位置，使用坐标 `[i][j]` 表示

状态转移方程、递归方程: 

令 `a[i][j]` 为 从 start到 位置 `[i][j]` 的不同路径数

```
a[i][j] = a[i][j-1] + a[i-1][j]
a[i][j] = a[i][j-1] (i=0)
a[i][j] = a[i-1][j] (j=0)
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

