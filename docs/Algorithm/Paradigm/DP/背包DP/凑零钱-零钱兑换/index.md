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

三、用计数原理来进行理解

## [徐洲更](https://leetcode.cn/u/xu-zhou-geng/) # [零钱兑换II和爬楼梯问题到底有什么不同？](https://leetcode.cn/problems/coin-change-2/solution/ling-qian-dui-huan-iihe-pa-lou-ti-wen-ti-dao-di-yo/)

在LeetCode上有两道题目非常类似，分别是

1、[70.爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/)

2、[518. 零钱兑换 II](https://leetcode-cn.com/problems/coin-change-2/)

如果我们把每次可走步数/零钱面额限制为 `[1,2]`，把楼梯高度/总金额限制为 `3`，那么这两道题目就可以抽象成 "给定 `[1,2]`，求组合成3的**组合数**和**排列数**"。

接下来引出本文的核心两段代码:

```c++
class Solution1 {
public:
    int change(int amount, vector<int>& coins) {
        int dp[amount+1];
        memset(dp, 0, sizeof(dp)); //初始化数组为0
        dp[0] = 1;
        for (int j = 1; j <= amount; j++){ //枚举金额
            for (int coin : coins){ //枚举硬币
                if (j < coin) continue; // coin不能大于amount
                dp[j] += dp[j-coin];
            }
        }
        return dp[amount];
    }
};
class Solution2 {
public:
    int change(int amount, vector<int>& coins) {
        int dp[amount+1];
        memset(dp, 0, sizeof(dp)); //初始化数组为0
        dp[0] = 1;
        for (int coin : coins){ //枚举硬币
            for (int j = 1; j <= amount; j++){ //枚举金额
                if (j < coin) continue; // coin不能大于amount
                dp[j] += dp[j-coin];
            }
        }
        return dp[amount];
    }
};

```

如果不仔细看，你会觉得这两个 Solution 似乎是一模一样的代码，但细心一点你会发现他们在嵌套循环上存在了差异。这个差异使得一个求解结果是 **排列数**，一个求解结果是 **组合数**。

因此在不看后面的分析之前，你能分辨出哪个 Solution 是得到**排列**，哪个 Solution 是得到**组合**吗？



### 70. 爬楼梯

这道题目子问题是，`problem(i) = sub(i-1) + sub(i-2)`, 即求解第i阶楼梯等于求解第 `i-1` 阶楼梯和第 `i-2` 阶楼梯之和。

> NOTE:
>
> 一、上述定义是典型的排列数，结合一个具体的例子来说：
>
> ```c++
> 3 = 1 + 2
> 
> 3 = 2 + 1
> ```
>
> 其实这就说明 [70.爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/) 是排列数问题，而不是组合数问题。
>
> 二、现在想来， [70.爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/) 其实可以归入完全背包问题，它和 LeetCode [322. 零钱兑换](https://leetcode-cn.com/problems/coin-change/) 非常类似
>
> 三、下面的"泛化问题"章节给出的source code是和上面的分析一致的，我们是可以将上述数据代入下面source code的for循环的，这样说能够看出这个source code的本质

状态数组是 `DP[i]`, 状态转移方程是 `DP[i] = DP[i-1] + DP[i-2]`

#### 泛化问题

如果我们把问题泛化，不再是固定的 1，2，而是任意给定台阶数，例如 1,2,5 呢？

我们只需要修改我们的 DP 方程 `DP[i] = DP[i-1] + DP[i-2] + DP[i-5]`, 也就是`DP[i] = DP[i] + DP[i-j] ,j =1,2,5`

在原来的基础上，我们的代码可以做这样子修改

```c++
class Solution {
public:
    int climbStairs(int n) {
        int DP[n+1];
        memset(DP, 0, sizeof(DP));
        DP[0] = 1;
        int steps[2] = {1,2};
        for (int i = 1; i <= n; i++){
            for (int j = 0; j < 2; j++){
                int step = steps[j];
                if ( i < step ) continue;// 台阶少于跨越的步数
                DP[i] = DP[i] + DP[i-step];
            }
        }
        return DP[n];

    }
};

```





### 零钱兑换II

问题描述如下:

> 给定不同面额的硬币和一个总金额。写出函数来计算可以凑成总金额的硬币组合数。假设每一种面额的硬币有无限个。

定义子问题: `problem(i) = sum( problem(i-j) ), j =1,2,5`。含义为凑成总金额i的硬币组合数等于凑成总金额硬币 `i-1`, `i-2`, `i-5`,...的子问题之和。

我们发现这个子问题定义居然和我们之前泛化的爬楼梯问题居然是一样的，那后面的状态数组和状态转移方程也是一样的，所以当前问题的代码可以在之前的泛化爬楼梯问题中进行修改而得。

```c++
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int dp[amount+1];
        memset(dp, 0, sizeof(dp)); //初始化数组为0
        dp[0] = 1;
        for (int j = 1; j <= amount; j++){ //枚举金额
            for (int i = 0; i < coins.size(): i++){ 
                int coin = coins[i]; //枚举硬币
                if (j < coin) continue; // coin不能大于amount
                dp[j] += dp[j-coin];
            }
        }
        return dp[amount];
    }
};
```

这就是我们之前的 Solution1 代码。

但是当你运行之后，却发现这个代码并不正确，得到的结果比预期的大。究其原因，该代码计算的结果是 **排列数**，而不是 **组合数**，也就是代码会把 `1,2`和 `2,1` 当做两种情况。但更加根本的原因是我们**子问题定义**出现了错误。



#### 正确的字问题定义

正确的 **子问题** 定义应该是，`problem(k,i) = problem(k-1, i) + problem(k, i-k)`

即前 **k** 个硬币凑齐金额 **i** 的组合数 **等于** 前 **k-1** 个硬币凑齐金额 **i** 的组合数 **加上** 在原来 **i-k** 的基础上使用硬币的组合数。说的更加直白一点，那就是用前 `k` 的硬币凑齐金额 `i` ，要分为两种情况开率，一种是没有用前 `k-1` 个硬币就凑齐了，一种是前面已经凑到了 `i-k` ，现在就差第 `k` 个硬币了。

> NOTE:
>
> 上述是典型的使用加分原理

**状态数组**就是 `DP\[k\]\[i\]`, 即前 `k` 个硬币凑齐金额 `i` 的组合数。

这里不再是一维数组，而是**二维**数组。第一个维度用于记录当前组合有没有用到硬币k，第二个维度记录现在凑的金额是多少？如果没有第一个维度信息，当我们凑到金额i的时候，我们不知道之前有没有用到硬币k。

因为这是个**组合**问题，**我们不关心硬币使用的顺序，而是硬币有没有被用到**。是否使用第k个硬币受到之前情况的影响。

> NOTE:
>
> 这段话点明了前面的思想，阐述了 **组合数** 和 **排列数** 的差别

状态转移方程如下

```sh
if 金额数大于硬币
    DP[k][i] = DP[k-1][i] + DP[k][i-k]
else
    DP[k][i] = DP[k-1][i]
```

因此正确代码如下:

```c++
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int K = coins.size() + 1;
        int I = amount + 1;
        int DP[K][I];
        //初始化数组
        for (int k = 0; k < K; k++){
            for (int i = 0; i < I; i++){
                DP[k][i] = 0;
            }
        }
        //初始化基本状态
        for (int k = 0; k < coins.size() + 1; k++){
            DP[k][0] = 1;
        }
        for (int k = 1; k <= coins.size() ; k++){
            for (int i = 1; i <= amount; i++){  
                if ( i >= coins[k-1]) {
                    DP[k][i] = DP[k][i-coins[k-1]] + DP[k-1][i]; 
                } else{
                    DP[k][i] = DP[k-1][k];
                }
            }
        }
        return DP[coins.size()][amount];
    }
};
```

此时，交换这里面的循环不会影响最终的结果。也就是

```c++
for (int i = 1; i <= amount; i++){  
    for (int k = 1; k <= coins.size() ; k++){ 
        if ( i >= coins[k-1]) {
            DP[k][i] = DP[k][i-coins[k-1]] + DP[k-1][i]; 
         } else{
             DP[k][i] = DP[k-1][k];
         }
     }
}
```

之前**爬楼梯问题**中，我们将一维数组降维成点。这里问题能不能也试着降低一个维度，只用一个数组进行表示呢？

这个时候，我们就需要重新定义我们的**子问题**了。此时的**子问题**是:

> 对于硬币从 0 到 k，我们必须使用第k个硬币的时候，当前金额的组合数。

因此 **状态数组** `DP[i]` 表示的是对于第k个硬币能凑的组合数

状态转移方程如下

```
 DP[[i] = DP[i] + DP[i-k]
```

于是得到我们开头的第二个Solution。

```c++
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int dp[amount+1];
        memset(dp, 0, sizeof(dp)); //初始化数组为0
        dp[0] = 1;
        for (int coin : coins){ //枚举硬币
            for (int i = 1; i <= amount; i++){ //枚举金额
                if (i < coin) continue; // coin不能大于amount
                dp[i] += dp[i-coin];
            }
        }
        return dp[amount];
    }
};

```

