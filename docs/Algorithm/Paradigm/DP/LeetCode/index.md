# LeetCode DP问题整理

## 最优值问题

可以把所有的**最优值问题**一起拿起来进行对比。

在下面的文章中给出了算法框架：

一、labuladong [团灭 LeetCode 股票买卖问题](https://mp.weixin.qq.com/s/lQEj_K1lUY83QtIzqTikGA) 



## Fibonacci DP 

跟背包DP一样，Fibonacci DP 也可以分为计数问题、最优值问题。

### 原问题

#### [LeetCode-509. 斐波那契数](https://leetcode.cn/problems/fibonacci-number/) 简单 

##### 核心code

```c++
class Solution
{
public:
  int fib(int n)
  {
    if (n <= 1)
    {
      return n;
    }
    int prev = 1, prev_prev = 0, cur = 0;
    for (int i = 2; i <= n; ++i)
    {
      cur = prev + prev_prev;
      prev_prev = prev;
      prev = cur;
    }
    return cur;
  }
};
```





### 计数

一、加法法则

二、[LeetCode-62. 不同路径](https://leetcode.cn/problems/unique-paths/) 和 LeetCode [1155. 掷骰子的N种方法](https://leetcode.cn/problems/number-of-dice-rolls-with-target-sum/) 比较类似。

三、计数问题，本质上是罗列所有的可能性、穷举，因此对于这种问题，基本上是都可以通过回溯法来解决的，一个典型的案例就是在 [LeetCode-1155. 掷骰子的N种方法](https://leetcode.cn/problems/number-of-dice-rolls-with-target-sum/) # [Java题解 动态规划法](https://leetcode.cn/problems/number-of-dice-rolls-with-target-sum/solution/javati-jie-cong-jian-dan-di-gui-dao-ya-s-3jg7/) 中所总结的，它首先使用回溯法，然后使用DP。

#### [LeetCode-70-爬楼梯](https://leetcode.cn/problems/climbing-stairs/) 

##### 核心code

```C++
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 2)
        {
            return n;
        }
        int prev = 2, prev_prev = 1, cur = 0;
        for (int i = 3; i <= n; ++i)
        {
            cur = prev + prev_prev;
            prev_prev = prev;
            prev = cur;
        }
        return cur;
    }
};
```

##### hightlight

一、计数问题



#### [LeetCode-91-解码方法-中等](https://leetcode.cn/problems/decode-ways/) 

##### 核心code

```c++

class Solution
{
public:
  int numDecodings(string s)
  {
    int N = s.size();
    vector<int> dp(N + 1);
    dp[0] = 1;
    for (int i = 1; i <= N; ++i)
    {
      if (s[i - 1] == '0')
      {
        if (i <= 1)
        {
          dp[i] = 0;
          return 0;
        }
        else
        {
          if (s[i - 2] == '1' || s[i - 2] == '2') // 前一位数这两个数，才能够形成有个有效的二位数
            dp[i] = dp[i - 2];
          else
            return 0;
        }
      }
      else
      {
        dp[i] = dp[i - 1]; // 单独映射到一个字母
        if (i >= 2)
        {
          if (s[i - 2] == '0') // 前一位数0，则不需要考虑两者形成两位数
          {
            continue;
          }
          else
          {
            auto ss = s.substr(i - 2, 2);
            if (atoi(ss.c_str()) <= 26) // 需要考察两位数能否映射位一个字母
              dp[i] += dp[i - 2];
          }
        }
      }
    }
    return dp[N];
  }
};
```



#### [LeetCode-62-不同路径](https://leetcode.cn/problems/unique-paths/) 

##### 核心code

```C++
class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> dp(m, vector<int>(n));
		for (int i = 0; i < m; ++i)
		{
			dp[i][0] = 1;
		}
		for (int i = 0; i < n; ++i)
		{
			dp[0][i] = 1;
		}
		for (int row = 1; row < m; ++row)
			for (int col = 1; col < n; ++col)
			{
				dp[row][col] = dp[row - 1][col] + dp[row][col - 1];
			}
		return dp[m - 1][n - 1];
	}
};
```

##### hightlight

一、这个问题没有空问题

二、来源

宫水三叶 [DP 路径问题](https://mp.weixin.qq.com/mp/appmsgalbum?__biz=MzU4NDE3MTEyMA==&action=getalbum&album_id=1773144264147812354&scene=173&from_msgid=2247485319&from_itemidx=1&count=3&uin=&key=&devicetype=Windows+10+x64&version=6303052a&lang=zh_CN&ascene=7&fontgear=2)

三、它也可以归入fibonacci DP



### 最优值问题

[LeetCode-746. 使用最小花费爬楼梯](https://leetcode.cn/problems/min-cost-climbing-stairs/) 和 leetcode [198. 打家劫舍](https://leetcode.cn/problems/house-robber/) 非常类似: 

| 题目                                                         | 核心的思想                                                   | 核心code                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| [LeetCode-746. 使用最小花费爬楼梯](https://leetcode.cn/problems/min-cost-climbing-stairs/) | 两个选择: <br>1、从前一个台阶跨过来<br>2、从前两个台阶跨过来 | `dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);` |
| [LeetCode-198. 打家劫舍](https://leetcode.cn/problems/house-robber/) | 两个选择:<br>1、抢: 从前两个跨过来<br>2、不抢: 从前一个跨过来 | `dp[dp_index] = max(dp[dp_index - 1], dp[dp_index - 2] + nums[i]);` |
|                                                              |                                                              |                                                              |



#### [LeetCode-746. 使用最小花费爬楼梯](https://leetcode.cn/problems/min-cost-climbing-stairs/) 

```c++

class Solution
{
public:
  int minCostClimbingStairs(vector<int> &cost)
  {
    int n = cost.size();
    vector<int> dp(n + 1, INT_MAX / 2);
    dp[0] = 0;
    dp[1] = 0;                                     // 爬到1楼
    dp[2] = min(dp[0] + cost[0], dp[1] + cost[1]); // 爬到2楼
    for (int i = 3; i <= n; ++i)                   // 爬到第n楼
    {
      dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    return dp[n];
  }
};

```

#### 打家劫舍系列



#### [LeetCode-64-最小路径和-中等](https://leetcode.cn/problems/minimum-path-sum/) 



## Subsequence-Subarray-Substring-DP

参见 `Subsequence-Subarray-Substring-DP` 章节。



## graph DP

### 最优值问题

#### [LeetCode-787. K 站中转内最便宜的航班](https://leetcode.cn/problems/cheapest-flights-within-k-stops/) 

```c++
m(v, k) 表示从source节点到v节点，中转k次的最便宜的价格
Parent(v) 表示节点v的parent节点
Price(u, v) 表示从节点u到节点v的价格，其实就是图的权重
m(v, k) = min(m(v, k-1), m(Parent(v), k-1) + Price(Parent(v), v))

base case: 
1、从src到src，无论经过多少次中转都是0
2、所有直接与source节点，都不需要经过中转(k=0)，它们的最小价格是可以直接获得的。
```



##### 核心code

```c++

class Solution
{
public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
  {
    int col = k + 1; //列数，从0-k，一共有k+1列
    vector<vector<long>> dp(n, vector<long>(col, INT_MAX));
    // base case
    for (int i = 0; i < col; ++i)
    {
      dp[src][i] = 0; // 从src到src，无论经过多少次中转都是0
    }
    for (auto &&flight : flights)
    {
      int src_node = flight[0];  // 源节点
      int dest_node = flight[1]; // 目标节点
      int weight = flight[2];
      if (src_node == src) // 是源节点
      {
        dp[dest_node][0] = weight;
      }
    }
    for (int i = 1; i <= k; ++i)
    {
      for (auto &&flight : flights)
      {
        int src_node = flight[0];  // 源节点
        int dest_node = flight[1]; // 目标节点
        int weight = flight[2];
        dp[dest_node][i] = min({
            dp[dest_node][i],            // 自己
            dp[dest_node][i - 1],        // 前一个节点
            dp[src_node][i - 1] + weight //
        });
      }
    }
    return dp[dst][k] == INT_MAX ? -1 : dp[dst][k];
  }
};

```

可以看到，上述求解最优值的过程，其实和前面的[LeetCode-746. 使用最小花费爬楼梯](https://leetcode.cn/problems/min-cost-climbing-stairs/) 、LeetCode [300. 最长递增子序列](https://leetcode.cn/problems/longest-increasing-subsequence/) 非常类似。



## 背包DP

### 零钱兑换

[LeetCode-322. 零钱兑换](https://leetcode.cn/problems/coin-change/)

[LeetCode-518. 零钱兑换 II](https://leetcode.cn/problems/coin-change-2/)



## 最优值问题: 股票买卖DP

和前面的Fibonacci DP 最优值问题、graph DP 最优值问题、背包DP最优值问题相比，股票买卖DP复杂度要高很多：

1、它涉及买卖，因此涉及利润、成不的计算

2、它需要维护当前持有股票的状态，这导致问题的维度进一步增加





## 计数问题

### base case

DP解计数问题的base case对于empty problem，它一般会初始化为1，下面是例子：

1、[LeetCode-91. 解码方法](https://leetcode.cn/problems/decode-ways/) 中等

2、[LeetCode-62. 不同路径](https://leetcode.cn/problems/unique-paths/) 中等

3、[LeetCode-416. 分割等和子集](https://leetcode.cn/problems/partition-equal-subset-sum/) # [星晴pro](https://leetcode.cn/u/eh-xing-qing/) # [一篇文章吃透背包问题！（细致引入+解题模板+例题分析+代码呈现](https://leetcode.cn/problems/partition-equal-subset-sum/solution/yi-pian-wen-zhang-chi-tou-bei-bao-wen-ti-a7dd/) 



[LeetCode-552. 学生出勤记录 II](https://leetcode.cn/problems/student-attendance-record-ii/) 困难

### Fibonacci DP

Fibonacci DP的计数问题是典型的使用加分原理的。



## K次

### DP

1、[LeetCode-787. K 站中转内最便宜的航班](https://leetcode.cn/problems/cheapest-flights-within-k-stops/) 

2、股票买卖

labuladong [团灭 LeetCode 股票买卖问题](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247494095&idx=4&sn=7aed55b22e93c0e43b83172923b51acc&scene=21#wechat_redirect)

最多允许交易k次

3、[LeetCode-651. 4键键盘](https://leetcode.cn/problems/4-keys-keyboard/)

最多允许按n次键盘

4、[LeetCode-1155. 掷骰子的N种方法](https://leetcode.cn/problems/number-of-dice-rolls-with-target-sum/)



可以看到，它们都将K次加入到了状态转移方程。

### 经典算法

一些题目，需要在经典算法的基础上增加K次的限制，从而提升题目的难度，典型的就是之前做过的：

一、Dijkstra algorithm 增加 k 次限制 

[LeetCode-787. K 站中转内最便宜的航班](https://leetcode.cn/problems/cheapest-flights-within-k-stops/) 

二、monolithic algorithm增加 k 次限制

三、priority_queue来解top K的问题



## DP数组记录的状态和最优解

DP数组记录的是子问题的解，而不一定是最优解，有的用DP来求解的问题，它的最优解需要另外来进行计算，下面是典型的例子：

1、[LeetCode-53. 最大子数组和](https://leetcode.cn/problems/maximum-subarray/)

2、[LeetCode-446. 等差数列划分 II - 子序列](https://leetcode.cn/problems/arithmetic-slices-ii-subsequence/) 困难

3、[LeetCode-最大连续1的个数 II](https://leetcode.cn/problems/max-consecutive-ones-ii/solution/zui-da-lian-xu-1de-ge-shu-ii-by-leetcode-solution/)

题目要求的是最大的连续1的个数，dp table记录的是以`nums[i]`结尾的连续1的个数

## DP继承上一个状态

1、[LeetCode-787. K 站中转内最便宜的航班](https://leetcode.cn/problems/cheapest-flights-within-k-stops/) 

2、[LeetCode-198. 打家劫舍](https://leetcode.cn/problems/house-robber/)

3、labuladong [团灭 LeetCode 股票买卖问题](https://mp.weixin.qq.com/s/lQEj_K1lUY83QtIzqTikGA) 

如果选择rest，则直接继承上一个节点的状态



## dp分情况讨论列多个状态转移方程

需要为每种选择都建立一个专门都状态转移方程

### labuladong [团灭 LeetCode 股票买卖问题](https://mp.weixin.qq.com/s/lQEj_K1lUY83QtIzqTikGA) 

当前有两种状态：

1、持有股票

可以选择rest、sell

2、不持有股票

可以选择rest、buy

### [LeetCode-487. 最大连续1的个数 II](https://leetcode.cn/problems/max-consecutive-ones-ii/) 

[官方解题](https://leetcode.cn/problems/max-consecutive-ones-ii/solution/zui-da-lian-xu-1de-ge-shu-ii-by-leetcode-solution/)

定义 `dp[i][0]` 为考虑到以 `i` 为结尾未使用操作将 `[0,i]` 某个 `0` 变成 `1` 的最大的连续 `1` 的个数，`dp[i][1]` 为考虑到以 `i` 为结尾使用操作将 `[0,i]` 某个 `0` 变成 `1` 的最大的连续 `1` 的个数。则我们可以列出转移式：
$$
dp[i][0]=\left\{\begin{matrix} dp[i-1][0]+1,nums[i]=1\\ 0,nums[i]=0 \end{matrix}\right.
$$


和

$$
dp[i][1]=\left\{\begin{matrix} dp[i-1][1]+1,nums[i]=1\\ dp[i-1][0]+1,nums[i]=0 \end{matrix}\right.
$$


## DP table的最优值 和 无效值

这是我在阅读 labuladong [团灭 LeetCode 股票买卖问题](https://mp.weixin.qq.com/s/lQEj_K1lUY83QtIzqTikGA) 时发现的。

那如何来选取无效值呢？保证它在算法中被抛弃掉即可，比如在  labuladong [团灭 LeetCode 股票买卖问题](https://mp.weixin.qq.com/s/lQEj_K1lUY83QtIzqTikGA) 中将无效值定位 `INT_MIN / 2`，综合题目的数据范围、算法使用max来选取数据，都能够保证无效值会被抛弃掉。

