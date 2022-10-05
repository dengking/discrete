# leetcode [123. 买卖股票的最佳时机 III](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/) 困难



## 动态规划

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
   * @brief
   * dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
   * dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
   *
   * @param k
   * @param prices
   * @return int
   */
  int maxProfit(vector<int> &prices)
  {
    int len = prices.size();
    if (len < 2)
    {
      return 0;
    }
    // n 天最多只能进行 n/2 笔交易
    // 题目要求k为2，但是可能无法完成两次交易
    int k = min(2, len / 2);

    vector<vector<int>> hold_dp(len, vector<int>(k + 1));     // 持有
    vector<vector<int>> not_hold_dp(len, vector<int>(k + 1)); // 不持有
    for (int i = 0; i <= k; ++i)                              //交易0次，不可能有持仓，所以初始化为无效值
    {
      hold_dp[0][i] = INT_MIN / 2;     // 如果使用INT_MIN，那么在进行减法的时候，是会underflow的
      not_hold_dp[0][i] = INT_MIN / 2; //
    }
    // 只有如下两个合法的状态，因为：
    // 对于hold_dp[0][2]、hold_dp[0][3]等，表示多次买入，题目要求每天只能够交易一次
    // 对于not_hold_dp[0][1]、not_hold_dp[0][2]等，表示没有持仓，但是进行了多次的交易，显然这是不合法的
    hold_dp[0][1] = -prices[0]; // 只有一个物品，买入一次即持仓了
    not_hold_dp[0][0] = 0;      // 没有持仓，也没有交易

    for (int i = 1; i < len; ++i)
    {
      for (int j = 1; j <= k; ++j)
      {
        hold_dp[i][j] = max(hold_dp[i - 1][j], not_hold_dp[i - 1][j - 1] - prices[i]);
        not_hold_dp[i][j] = max(not_hold_dp[i - 1][j], hold_dp[i - 1][j] + prices[i]);
      }
    }
    return *max_element(not_hold_dp[len - 1].begin(), not_hold_dp[len - 1].end());
  }
};

// Driver code
int main()
{

  Solution solu;
  vector<int> prices{7, 1, 5, 3, 6, 4};
  return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

