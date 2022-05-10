# 背包DP



## 完全背包 vs 0-1背包



一、完全背包不需要考虑物品，只需要考虑背包容量，因此它是一维的；

需要注意的是：在完全背包问题中，我们一次只取一个物品，下次循环的时候，还是从第一个物品开始，因此这样就能够实现重复取同一个物品了，典型的例子就是零钱兑换问题，比如 leetcode [322. 零钱兑换](https://leetcode-cn.com/problems/coin-change/) ：

```c++
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
```



二、0-1背包需要考虑物品，考虑背包容量，因此它是二维的；

## 完全背包



### 凑零钱

参见 `凑零钱-零钱兑换` 章节。

### 与顺序是否相关

一、顺序是否对问题的结果产生影响？

1、计数问题: 可以肯定的是，如果与顺序相关，则组合数会更多，如果与顺序无比，则组合数更少。

2、最值问题: 顺序并不产生影响，因为不同顺序的结果相同，因此并不会对最终结果产生影响。



二、资源

在下面的文章中，有描述:

1、LeetCode [518. 零钱兑换 II](https://leetcode-cn.com/problems/coin-change-2/) 中等





## 资源

1、leetcode [一篇文章吃透背包问题！（细致引入+解题模板+例题分析+代码呈现](https://leetcode-cn.com/problems/partition-equal-subset-sum/solution/yi-pian-wen-zhang-chi-tou-bei-bao-wen-ti-a7dd/) 

2、leetcode [希望用一种规律搞定背包问题](https://leetcode-cn.com/problems/combination-sum-iv/solution/xi-wang-yong-yi-chong-gui-lu-gao-ding-bei-bao-wen-/)



资源：

1、[宫水三叶](https://leetcode-cn.com/u/ac_oier/) # [【动态规划/背包问题】运用分组背包进行求解](https://leetcode-cn.com/problems/number-of-dice-rolls-with-target-sum/solution/dong-tai-gui-hua-bei-bao-wen-ti-yun-yong-axtf/)

## 习题汇总



leetcode [322. 零钱兑换](https://leetcode-cn.com/problems/coin-change/) :



```c++
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
```

对于每个amount，会考虑所有的coins，显然它罗列了所有的可能性。

