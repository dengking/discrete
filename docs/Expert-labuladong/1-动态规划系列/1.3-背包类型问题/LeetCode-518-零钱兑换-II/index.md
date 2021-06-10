# LeetCode [518. 零钱兑换 II](https://leetcode-cn.com/problems/coin-change-2/) 中等



## 我的解题

是参考 labuladong [经典动态规划：完全背包问题](https://mp.weixin.qq.com/s/zGJZpsGVMlk-Vc2PEY4RPw) 中的解法。

```C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	int change(int amount, vector<int> &coins)
	{
		int n = coins.size();
		vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
		for (int i = 0; i <= n; ++i)
		{
			dp[i][0] = 1;
		}
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= amount; ++j)
			{
				if (j - coins[i - 1] >= 0) // 能够装下第i个物品
				{
					dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
				}
				else // 装不下第i个物品
				{
					dp[i][j] = dp[i - 1][j];
				}
			}
		return dp[n][amount];
	}
};
ostream& operator<<(ostream &stream, vector<int> v)
{
	for (auto &&i : v)
		stream << i;
	return stream;
}
// Driver code
int main()
{

	Solution s;
	return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```

