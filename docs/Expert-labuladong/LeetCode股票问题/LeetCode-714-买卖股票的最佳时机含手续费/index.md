# leetcode [714. 买卖股票的最佳时机含手续费](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)



## 我的解题

按照 labuladong [团灭 LeetCode 股票买卖问题](https://mp.weixin.qq.com/s/lQEj_K1lUY83QtIzqTikGA) 中给出的算法。



```C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	/**
	 * @brief
	 * dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
	 * dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i] - fee)
	 *
	 * @param prices
	 * @return
	 */
	int maxProfit(vector<int> &prices, int fee)
	{
		int dp_i_0 = 0, dp_i_1 = numeric_limits<int>::min();
		for (int i = 0; i < prices.size(); ++i)
		{
			dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
			dp_i_1 = max(dp_i_1, dp_i_0 - prices[i] - fee);
		}
		return dp_i_0;
	}
};
int main()
{
	int fee = 2;
	vector<int> price { 1, 3, 2, 8, 4, 9 };
	Solution s;
	cout << s.maxProfit(price, fee) << endl;

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```

