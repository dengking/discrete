# leetcode [122. 买卖股票的最佳时机 II](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/)





## 我的解题

### 动态规划

按照 labuladong [团灭 LeetCode 股票买卖问题](https://mp.weixin.qq.com/s/lQEj_K1lUY83QtIzqTikGA) 中给出的动态规划算法来解题。

```C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	/**
	 * @brief
	 * dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
	 * dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])
	 *
	 * @param prices
	 * @return
	 */
	int maxProfit(vector<int> &prices)
	{
		int dp_i_0 = 0, dp_i_1 = numeric_limits<int>::min();
		for (int i = 0; i < prices.size(); ++i)
		{
			dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
			dp_i_1 = max(dp_i_1, dp_i_0 - prices[i]);
		}
		return dp_i_0;
	}
};
int main()
{
	vector<int> price { 7, 1, 5, 3, 6, 4 };
	Solution s;
	cout << s.maxProfit(price) << endl;

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```

