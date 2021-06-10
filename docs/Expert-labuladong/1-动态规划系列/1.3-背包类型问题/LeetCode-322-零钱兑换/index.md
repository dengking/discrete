# leetcode [322. 零钱兑换](https://leetcode-cn.com/problems/coin-change/)





## 我的解题

这个问题在 labuladong [动态规划详解](https://mp.weixin.qq.com/s/Cw39C9MY9Wr2JlcvBQZMcA)  中，给出了非常详细的解释。

通过"状态、选择、base case"可以思考出"状态转移方程"。

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

