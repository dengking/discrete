# 从起点到终点的路径数目系列

题目:

[LeetCode-62. 不同路径-中等](https://leetcode.cn/problems/unique-paths/) 

[LeetCode-63. 不同路径 II-中等](https://leetcode.cn/problems/unique-paths-ii/) 

[LeetCode-64. 最小路径和-中等](https://leetcode.cn/problems/minimum-path-sum/) 

[LeetCode-980. 不同路径 III-困难](https://leetcode.cn/problems/unique-paths-iii/) 

算法分析：

它们都可以归入fibonacci DP。



## [LeetCode-62. 不同路径-middle](https://leetcode.cn/problems/unique-paths/) 

是在阅读 宫水三叶 [【动态规划/总结必看】从一道入门题与你分享关于 DP 的分析技巧](https://mp.weixin.qq.com/s/G_KYdjrhQQO43-t0Jw8iBA) 时，发现的这道题。



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



#### 完整代码

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



#### fibonacci DP计数问题

在 emre.me [Coding Patterns: Staircase (DP)](https://emre.me/coding-patterns/staircase/) 中将上述问题归入到了"Staircase (DP)"即"fibonacci DP计数问题"范畴中，从上述实现来看，我觉得是比较符合的。



## [LeetCode-63. 不同路径 II-middle](https://leetcode.cn/problems/unique-paths-ii/) 

在 [LeetCode-62. 不同路径](https://leetcode.cn/problems/unique-paths/) 的基础上增加了一点难度：增加了障碍物，对 leetcode [62. 不同路径](https://leetcode.cn/problems/unique-paths/) 做一点修改即可解决这道题。

```c++
// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>
#include <list>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <cmath>
#include <numeric>
#include <climits>
#include <random>
// example1.cpp
// new-delete-type-mismatch error
#include <memory>
#include <vector>
using namespace std;

class Solution
{
public:
  /**
   * @brief 将障碍物等不可达的地方，全部都设置为0，这样对于计数就不会产生影响
   *
   * @param obstacleGrid
   * @return int
   */
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
  {
    int m = obstacleGrid.size();    //行
    int n = obstacleGrid[0].size(); //列
    if (m == 1 && n == 1)           // 只有一个格子
    {
      return 0;
    }
    vector<vector<int>> dp(m, vector<int>(n));
    // 不能够加上下面的这句话，因为存在如下用例:
    // [[0]]、[[1]]，对于这两种情况，此时的base case应该是根据如下函数进行确定
    // dp[0][0] = 1;               // dp计数问题的base case
    for (int i = 0; i < m; ++i) // 处理第一列
    {
      // 在第一行或者第一列，如果存在障碍物那么这个障碍物后的地方都是不可达的
      if (obstacleGrid[i][0] == 1)
      {
        break;
      }
      else
      {
        dp[i][0] = 1;
      }
    }
    for (int i = 0; i < n; ++i) // 处理第一行
    {
      // 在第一行或者第一列，如果存在障碍物那么这个障碍物后的地方都是不可达的
      if (obstacleGrid[0][i] == 1)
      {
        break;
      }
      else
      {
        dp[0][i] = 1;
      }
    }
    for (int i = 1; i < m; ++i)
    {
      for (int j = 1; j < n; ++j)
      {
        if (obstacleGrid[i][j] == 1) //碰到障碍物，不处理
        {
          continue;
        }
        else
        {
          //
          // 从上面过来；从左边过来
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
      }
    }
    return dp[m - 1][n - 1];
  }
};

// Driver code
int main()
{

  Solution solu;
  vector<int> nums = {2, 4, 6, 8, 10};
  return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```



## [LeetCode-64. 最小路径和-middle](https://leetcode.cn/problems/minimum-path-sum/) 

这道题其实和 [62. 不同路径](https://leetcode.cn/problems/unique-paths/) 非常类似，属于fibonacci dp求解最优值，它和[LeetCode-746. 使用最小花费爬楼梯](https://leetcode.cn/problems/min-cost-climbing-stairs/) 简单如出一辙。

```c++
// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>
#include <list>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <cmath>
#include <numeric>
#include <climits>
#include <random>
// example1.cpp
// new-delete-type-mismatch error
#include <memory>
#include <vector>
using namespace std;

class Solution
{
public:
  int minPathSum(vector<vector<int>> &grid)
  {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n));
    for (int i = 0; i < m; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        if (i == 0 && j == 0)
        {
          dp[i][j] = grid[0][0];
        }
        else if (i == 0 && j > 0) // 第一行
        {
          dp[i][j] = dp[i][j - 1] + grid[i][j];
        }
        else if (j == 0 && i > 0) // 第一列
        {
          dp[i][j] = dp[i - 1][j] + grid[i][j];
        }
        else
        {
          assert(i > 0 && j > 0);
          dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
      }
    }
    return dp[m - 1][n - 1];
  }
};

// Driver code
int main()
{

  Solution solu;
  vector<vector<int>> nums{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  solu.minPathSum(nums);
  return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```



## [LeetCode-980. Unique Paths III-hard-TODO](https://leetcode.cn/problems/unique-paths-iii/)



