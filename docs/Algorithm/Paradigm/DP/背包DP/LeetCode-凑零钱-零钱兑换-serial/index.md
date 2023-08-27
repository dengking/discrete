# 凑零钱、零钱兑换

从完全背包的递归版本代码来进行思考。

## 资源

在如下文章中进行了介绍：

1、labuladong [动态规划详解](https://mp.weixin.qq.com/s/Cw39C9MY9Wr2JlcvBQZMcA) 

其中描述了这个问题从DFS-recursion到DP的过程。

2、labuladong [经典动态规划：完全背包问题](https://mp.weixin.qq.com/s/zGJZpsGVMlk-Vc2PEY4RPw)

3、[LeetCode-一篇文章吃透背包问题！（细致引入+解题模板+例题分析+代码呈现](https://leetcode.cn/problems/partition-equal-subset-sum/solution/yi-pian-wen-zhang-chi-tou-bei-bao-wen-ti-a7dd/) 



## 题目

|                                                              | 问题分类                                         |                                                              |
| ------------------------------------------------------------ | ------------------------------------------------ | ------------------------------------------------------------ |
| [LeetCode-322. 零钱兑换](https://leetcode.cn/problems/coin-change/) | 最值问题: "凑成总金额所需的 **最少的硬币个数** " | 1、最终的结果与银币的顺序没有关系: 相同硬币组合的不管怎样进行排列其实个数都是相同的，因此最终的结果也是相同的，因此也就和顺序没有关系；<br>2、在具体的顺序上，其实是不需要考虑顺序的，原因在上面已经进行了分析 |
| [LeetCode-518. 零钱兑换 II](https://leetcode.cn/problems/coin-change-2/) | 组合计数: "可以凑成总金额的硬币组合数"           | 1、最终的结果与银币的顺序有关系，相同硬币组合的不同排列应该算同一个，不能够分别进行计数；那在具体实现的时候，如何保证这一点呢？ |
|                                                              |                                                  |                                                              |



### [LeetCode-322. 零钱兑换](https://leetcode.cn/problems/coin-change/) 



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



#### 二刷

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

一、上述写法是更加符合思维的: 

1、对于每个容量amount，考虑当前所有的`coins` 

2、在**完全背包问**题中，我们一次只取一个物品，下次循环的时候，还是从第一个物品开始，因此这样就能够实现重复取同一个物品 

二、上述是典型的最优值的问题，它是**顺序不敏感**的，即相同元素的不同排列顺序，最终的结果是相同的



### [LeetCode-518. 零钱兑换 II](https://leetcode.cn/problems/coin-change-2/) 

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



#### 结合具体的例子进行理解

首先，它是和顺序无关的，即1、2、1和1、1、2是相同的，那如何来做到呢？我觉得它采用的做法是通过**顺序**来**去重**，其实是按照coins的顺序来，结合下面的例子，1永远在2的前面。

##### 例子一

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

##### 例子二

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

##### 总结

上述算法其实是通过对coins进行排序来顺序去重的目的，其实 `dp[i] += dp[i - coin]` 所做的是append一个新的coin到之前的sequence中，它非常巧妙。

#### [官方解题](https://leetcode.cn/problems/coin-change-2/solution/ling-qian-dui-huan-ii-by-leetcode-soluti-f7uh/)



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



一、可以看到，上述问题for循环和前面的for循环正好相反

二、上述是典型的计数问题，它是**顺序敏感**的，题目要求对于相同元素的不同排列只能够算一个，因此需要考虑去重，那它是如何实现的呢？

三、用计数原理来进行理解

