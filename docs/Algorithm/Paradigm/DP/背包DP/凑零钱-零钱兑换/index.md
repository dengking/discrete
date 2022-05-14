# 凑零钱、零钱兑换

从完全背包的递归版本代码来进行思考。

## 资源

在如下文章中进行了介绍：

1、labuladong [动态规划详解](https://mp.weixin.qq.com/s/Cw39C9MY9Wr2JlcvBQZMcA) 

其中描述了这个问题从DFS-recursion到DP的过程。

2、labuladong [经典动态规划：完全背包问题](https://mp.weixin.qq.com/s/zGJZpsGVMlk-Vc2PEY4RPw)

3、leetcode [一篇文章吃透背包问题！（细致引入+解题模板+例题分析+代码呈现](https://leetcode-cn.com/problems/partition-equal-subset-sum/solution/yi-pian-wen-zhang-chi-tou-bei-bao-wen-ti-a7dd/) 



## 题目

|                                                              | 问题分类                                         |                                                              |
| ------------------------------------------------------------ | ------------------------------------------------ | ------------------------------------------------------------ |
| LeetCode [322. 零钱兑换](https://leetcode-cn.com/problems/coin-change/) | 最值问题: "凑成总金额所需的 **最少的硬币个数** " | 1、最终的结果与银币的顺序没有关系: 相同硬币组合的不管怎样进行排列其实个数都是相同的，因此最终的结果也是相同的，因此也就和顺序没有关系；<br>2、在具体的顺序上，其实是不需要考虑顺序的，原因在上面已经进行了分析 |
| LeetCode [518. 零钱兑换 II](https://leetcode-cn.com/problems/coin-change-2/) | 组合计数: "可以凑成总金额的硬币组合数"           | 1、最终的结果与银币的顺序有关系，相同硬币组合的不同排列应该算同一个，不能够分别进行计数；那在具体实现的时候，如何保证这一点呢？ |
|                                                              |                                                  |                                                              |



### LeetCode [322. 零钱兑换](https://leetcode-cn.com/problems/coin-change/) 

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

一、上述写法是更加符合思维的: 

1、对于每个容量amount，考虑当前所有的`coins` 

2、在**完全背包问**题中，我们一次只取一个物品，下次循环的时候，还是从第一个物品开始，因此这样就能够实现重复取同一个物品 

二、上述是典型的最优值的问题，它是**顺序不敏感**的，即相同元素的不同排列顺序，最终的结果是相同的



### LeetCode [518. 零钱兑换 II](https://leetcode-cn.com/problems/coin-change-2/) 



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

