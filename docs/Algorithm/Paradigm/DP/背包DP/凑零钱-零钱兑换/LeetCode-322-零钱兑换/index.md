# [LeetCode-322. 零钱兑换](https://leetcode.cn/problems/coin-change/)



## 我的解题

一、这个问题在 labuladong [动态规划详解](https://mp.weixin.qq.com/s/Cw39C9MY9Wr2JlcvBQZMcA)  中，给出了非常详细的解释。

通过"状态、选择、base case"可以思考出"状态转移方程"。

二、这个问题是典型的完全背包问题

```C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	int coinChange(vector<int> &coins, int amount)
	{
		vector<int> dp_table(amount + 1, amount + 1); // dp table，记录解，即最少的个数
		dp_table[0] = 0;
		for (int i = 1; i <= amount; ++i) // 金额，它对应的是状态
		{
			for (auto &&coin : coins)
			{
				if (i - coin < 0)
					continue;
				dp_table[i] = min(dp_table[i], 1 + dp_table[i - coin]);
			}
		}
		return dp_table[amount] == amount + 1 ? -1 : dp_table[amount];
	}
};

int main()
{
	vector<int> n { 1, 2, 5 };
	int amount = 11;
	Solution s;
	cout << s.coinChange(n, amount) << endl;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```



### 二刷

这是仿照 [LeetCode-一篇文章吃透背包问题！（细致引入+解题模板+例题分析+代码呈现](https://leetcode.cn/problems/partition-equal-subset-sum/solution/yi-pian-wen-zhang-chi-tou-bei-bao-wen-ti-a7dd/) 写的: 

```c++
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <numeric>

using namespace std;

class Solution
{
public:
  int coinChange(vector<int> &coins, int amount)
  {
    vector<long long> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i <= amount; ++i)
    {
      for (auto &&coin : coins)
      {
        if (i >= coin)
        {
          dp[i] = min(dp[i], dp[i - coin] + 1);
        }
      }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
  }
};

int main()
{
  vector<int> coins{2};
  Solution s;
  int amount = 3;
  s.coinChange(coins, amount);
}

```

