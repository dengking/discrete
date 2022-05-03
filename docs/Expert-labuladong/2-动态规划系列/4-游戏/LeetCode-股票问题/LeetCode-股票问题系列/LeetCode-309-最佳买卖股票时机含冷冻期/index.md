# leetcode [309. 最佳买卖股票时机含冷冻期](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/) 中等



## 我的解题

按照 labuladong [团灭 LeetCode 股票买卖问题](https://mp.weixin.qq.com/s/lQEj_K1lUY83QtIzqTikGA) 给出的算法实现的。

### 一个错误的答案

```C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	/**
	 * @brief
	 * dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
	 * dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i] )
	 *
	 * @param prices
	 * @return
	 */
	int maxProfit(vector<int> &prices)
	{
		int dp_i_0 = 0, dp_i_1 = numeric_limits<int>::min();
		int dp_pre_0 = 0; // dp[i-2][0]
		for (int i = 0; i < prices.size(); ++i)
		{
			dp_pre_0 = dp_i_0;
			dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
			dp_i_1 = max(dp_i_1, dp_pre_0 - prices[i]);
		}
		return dp_i_0;
	}
};
int main()
{
	vector<int> price { 1, 2, 3, 0, 2 };
	Solution s;
	cout << s.maxProfit(price) << endl;

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```

上面是我第一次写的，它是错误的:

```C++
		for (int i = 0; i < prices.size(); ++i)
		{
			dp_pre_0 = dp_i_0;
			dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
			dp_i_1 = max(dp_i_1, dp_pre_0 - prices[i]);
		}
```

在这个`for`中，在`dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);`被执行之前，`dp_i_0`的值是上一轮的，因此它对应的是 `dp[i-1][0]`，所有 `dp_pre_0 = dp_i_0`、`dp_i_1 = max(dp_i_1, dp_pre_0 - prices[i])` 其实对应的是:

```C++
dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i] )
```



正确的写法如下:

### 正确的写法

```C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	/**
	 * @brief
	 * dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
	 * dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i] )
	 *
	 * @param prices
	 * @return
	 */
	int maxProfit(vector<int> &prices)
	{
		int dp_i_0 = 0, dp_i_1 = numeric_limits<int>::min();
		int dp_pre_0 = 0; // dp[i-2][0]
		for (int i = 0; i < prices.size(); ++i)
		{
			int temp = dp_i_0;
			dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
			dp_i_1 = max(dp_i_1, dp_pre_0 - prices[i]);
			dp_pre_0 = temp;
		}
		return dp_i_0;
	}
};
int main()
{
	vector<int> price { 1, 2, 3, 0, 2 };
	Solution s;
	cout << s.maxProfit(price) << endl;

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```

`int temp = dp_i_0;` 表示将`dp[i-1][1]`存入其中

`dp_pre_0 = temp;` 则此时`dp_pre_0` 中存入的是`dp[i-1][1]`的值，在下一轮迭代的时候，它对应的是 `dp[i-2][0]` 。