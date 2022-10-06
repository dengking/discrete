# [LeetCode-64. 最小路径和](https://leetcode.cn/problems/minimum-path-sum/) 中等



## 我的解题

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

