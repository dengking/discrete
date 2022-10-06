# [LeetCode-518. 零钱兑换 II](https://leetcode.cn/problems/coin-change-2/) 中等



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
		for (int i = 0; i <= n; ++i) // 金额为0
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



### 结合具体的例子进行理解

首先，它是和顺序无关的，即1、2、1和1、1、2是相同的，那如何来做到呢？我觉得它采用的做法是通过**顺序**来**去重**，其实是按照coins的顺序来，结合下面的例子，1永远在2的前面。

#### 例子一

```c++
amount=3, coins=[1,2] 
```

第一轮：

```
coin=1 # 表示以1打头
dp[1] += dp[1-1] = dp[0] = 1

dp[2] += dp[2-1] = dp[1] = 1

dp[3] += dp[3-1] = dp[2] = 1
```

这一轮计算的都是以1打头的

第二轮：

```
coin=2 # 表示以2打头
dp[2] += dp[2-2] = dp[0] = 1 + 1

dp[3] += dp[3-2] = dp[1] = 1 + 1
```

这一轮计算的都是以2打头的



需要注意，初始值`dp[0]=1`非常重要，它的含义结合一个具体的例子最好理解：

```
coin=1 # 表示以1打头
dp[1] += dp[1-1] = dp[0] = 1
```

也就是说，如果目标金额能够由指定金币凑成，那么最终的凑法数量是由从目标金额中扣除掉该金币后，对应的金额的凑发数量决定的。显然，如果目标金额减去硬币后为0，说明它是能够由这个银币凑成的，因此凑法需要加上1.

#### 例子二

```
amount = 5, coins = [1, 2, 5]
```

第一轮:

```
coin=1 # 表示以1打头
dp[1] += dp[1-1] = dp[0] = 1

dp[2] += dp[2-1] = dp[1] = 1

dp[3] += dp[3-1] = dp[2] = 1

dp[4] += dp[4-1] = dp[3] = 1

dp[5] += dp[5-1] = dp[4] = 1 # 表示全部由1凑成的
```

第二轮:

```
coin=2 # 表示以2打头

dp[2] += dp[2-2] = dp[0] = 1 + 1# 全部由2凑成

dp[3] += dp[3-2] = dp[1] = 1 + 1

dp[4] += dp[4-2] = dp[2] = 1 + 2

dp[5] += dp[5-2] = dp[3] = 1 + 2 
```

第三轮：

```
dp[5] += dp[5-5] = dp[0] = 1 + 3
```

#### 总结

上述算法其实是通过对coins进行排序来顺序去重的目的，其实 `dp[i] += dp[i - coin]` 所做的是append一个新的coin到之前的sequence中，它非常巧妙。

## [官方解题](https://leetcode.cn/problems/coin-change-2/solution/ling-qian-dui-huan-ii-by-leetcode-soluti-f7uh/)



```c++
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for (int& coin : coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};

```

