# LeetCode [121. 买卖股票的最佳时机](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/) 简单



## 我的解题

这是我参照 labuladong [LeetCode 股票问题的一种通用解法](https://mp.weixin.qq.com/s/TrN7mMdLEPCmT5mOXzgP5A) 中，写出的答案。

```C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	int maxProfit(vector<int> &prices)
	{
		int res = 0; // 最终结果，即最大利润
		int min_buy_price = prices[0]; // 最小买入价格
		for (size_t i = 1; i < prices.size(); ++i) // 卖出的时机
		{
			min_buy_price = min(prices[i], min_buy_price); // 更新最小买价
			res = max(res, prices[i] - min_buy_price);
		}
		return res;
	}
};

int main()
{
	vector<int> n { 1, 2, 5 };
	Solution s;
	cout << s.maxProfit(n) << endl;

	n = { 7, 1, 5, 3, 6, 4 };
	cout << s.maxProfit(n) << endl;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```



## TODO

在 [C++ 利用哨兵👨‍✈️，维护一个单调栈📈(图解，直观掌握)](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/c-li-yong-shao-bing-wei-hu-yi-ge-dan-diao-zhan-tu-/) 中，给出了一种使用单调栈的解法。