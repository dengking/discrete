# [LeetCode-63. 不同路径 II](https://leetcode.cn/problems/unique-paths-ii/) 中等



## 我的解题

在 [LeetCode-62. 不同路径](https://leetcode.cn/problems/unique-paths/) 的基础上增加了一点难度：增加了障碍物，对 leetcode [62. 不同路径](https://leetcode.cn/problems/unique-paths/) 做一点修改即可解决这道题。

### 完整代码如下

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

