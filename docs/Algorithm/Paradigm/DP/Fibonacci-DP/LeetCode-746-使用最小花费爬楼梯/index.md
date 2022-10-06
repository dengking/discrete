# [LeetCode-746. 使用最小花费爬楼梯](https://leetcode.cn/problems/min-cost-climbing-stairs/) 简单



## 我的解题

这是在阅读 emre.me [Coding Patterns: Staircase (DP)](https://emre.me/coding-patterns/staircase/) 时发现的。

```
dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]) # 爬到第i楼需要支付的费用
```


```
dp[0] = 0
```


```
dp[1] = 0
```


上述base case非常重要，因为题目要求可以从0楼、1楼开始，所以它们的初始值都是0.
```
dp[2] = dp[0] + cost[0] # 从0楼走两步到了2
        dp[1] + cost[1] # 从1楼走一步
```



```
dp[3] = dp[2] + cost[2] # 从2楼再走一步
        dp[1] + cost[1] + cost[2] # 从1楼走一步到2楼，从2楼走一步到3楼
        dp[1] + cost[1] # 从1楼走两步到3楼
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
    vector<int> dp(n + 1, INT_MAX / 2);
    dp[0] = 0;
    dp[1] = 0;                                     // 爬到1楼
    dp[2] = min(dp[0] + cost[0], dp[1] + cost[1]); // 爬到2楼
    for (int i = 3; i <= n; ++i)                   // 爬到第n楼
    {
      dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    return dp[n];
  }
};

int main()
{
}
```

