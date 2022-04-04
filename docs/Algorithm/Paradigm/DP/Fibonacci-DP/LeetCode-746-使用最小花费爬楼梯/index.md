# leetcode [746. 使用最小花费爬楼梯](https://leetcode-cn.com/problems/min-cost-climbing-stairs/) 简单



## 我的解题

楼顶为 `i` 时，从第0楼爬上来的最小话费。

```
dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]) # 爬到第i楼需要支付的费用
dp[0] = 0
```





```c++
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
  int minCostClimbingStairs(vector<int> &cost)
  {
    int n = cost.size();
    vector<int> dp(n, INT_MAX / 2);
    dp[0] = 0;
    for (int i = 0; i < 2; ++i)
    {
      if (i + 1 < n)
        dp[i + 1] = min(dp[i + 1], cost[i]);
      if (i + 2 < n)
        dp[i + 2] = min(dp[i + 2], cost[i]);
    }
    for (int i = 2; i < n; ++i)
    {
      dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    return dp[n - 1];
  }
};

int main()
{
}
```

