# leetcode [123. 买卖股票的最佳时机 III](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/) 困难



## 我的解题

### 使用状态压缩





### 使用嵌套循环

```
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	/**
	 * @brief
	 * dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
	 * dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i] )
	 *
	 * @param prices
	 * @return
	 */
	int maxProfit(vector<int> &prices)
	{
		int dp_i_0 = 0, dp_i_1 = numeric_limits<int>::min();
		int k_max = 2;
		int dp_table[prices.size()][k_max][2] { 0 };
		for (int i = 0; i < prices.size(); ++i)
		{
			for (int k = 1; i <= k_max; ++k)
			{
				if (i == 0)
				{

				}
				else
				{
					dp_table[i][k][0] = max(dp_table[i - 1][k][0], dp_table[i - 1][k][1] + prices[i]);
					dp_table[i][k][1] = max(dp_table[i - 1][k][1], dp_table[i - 1][k - 1][0] - prices[i]);
				}
			}
		}
		return dp_i_0;
	}
};
int main()
{
	vector<int> price { 3, 3, 5, 0, 0, 3, 1, 4 };
	Solution s;
	cout << s.maxProfit(price) << endl;

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```

