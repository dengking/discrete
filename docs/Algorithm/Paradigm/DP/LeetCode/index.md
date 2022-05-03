# LeetCode DP问题整理

## 最优值问题

可以把所有的**最优值问题**一起拿起来进行对比。

## Fibonacci DP 

跟背包DP一样，Fibonacci DP 也可以分为计数问题、最优值问题。

### 原问题

#### leetcode [509. 斐波那契数](https://leetcode-cn.com/problems/fibonacci-number/) 简单 

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

二、LeetCode [62. 不同路径](https://leetcode-cn.com/problems/unique-paths/) 和 LeetCode [1155. 掷骰子的N种方法](https://leetcode-cn.com/problems/number-of-dice-rolls-with-target-sum/) 比较类似。

三、计数问题，本质上是罗列所有的可能性、穷举，因此对于这种问题，基本上是都可以通过回溯法来解决的，一个典型的案例就是在 LeetCode [1155. 掷骰子的N种方法](https://leetcode-cn.com/problems/number-of-dice-rolls-with-target-sum/) # [Java题解 动态规划法](https://leetcode-cn.com/problems/number-of-dice-rolls-with-target-sum/solution/javati-jie-cong-jian-dan-di-gui-dao-ya-s-3jg7/) 中所总结的，它首先使用回溯法，然后使用DP。

#### LeetCode [70. 爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/) 

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



#### leetcode [91. 解码方法](https://leetcode-cn.com/problems/decode-ways/) 中等

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







#### LeetCode [62. 不同路径](https://leetcode-cn.com/problems/unique-paths/) 中等

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

leetcode [746. 使用最小花费爬楼梯](https://leetcode-cn.com/problems/min-cost-climbing-stairs/) 和 leetcode [198. 打家劫舍](https://leetcode-cn.com/problems/house-robber/) 非常类似



#### leetcode [746. 使用最小花费爬楼梯](https://leetcode-cn.com/problems/min-cost-climbing-stairs/) 

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



#### LeetCode [64. 最小路径和](https://leetcode-cn.com/problems/minimum-path-sum/) 中等



## 子序列、子串、子数组

### DP 子序列 VS DP 子数组

两者的相同点: **DP方程**的定义都是以`nums[i]` 结尾的，算法过程都是 `nums[i]` 和它前面的**子序列**/**子数组**进行**连接**，所不同的是**子序列**不要求连续，但是**子数组**要求连续，因此子序列会遍历它前面的所有的元素，而子数组只需要考虑它紧邻的一个元素，其实这就决定了两者的复杂度: $O(N^2)$ VS $O(N)$。

关于两者对比的最最经典的例子就是:

一、**LIS** 和 **最大子数组和**

在下面的文章中进行了非常好的描述：

1、[446. 等差数列划分 II - 子序列](https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/) # [【负雪明烛】揭秘子序列动态规划的套路](https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/solution/fu-xue-ming-zhu-jie-mi-zi-xu-lie-dong-ta-gepk/)

2、[446. 等差数列划分 II - 子序列](https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/) # [动态规划（Java）](https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/solution/dong-tai-gui-hua-java-by-liweiwei1419-jc84/)

二、LeetCode [413. 等差数列划分](https://leetcode-cn.com/problems/arithmetic-slices/) 中等、LeetCode [446. 等差数列划分 II - 子序列](https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/) 困难

#### complexity: $O(N^2)$ VS $O(N)$

对于子序列问题，追求 $O(N^2)$ 的复杂度；

对于子数组问题，追求 $O(N)$ 的复杂度； 

### 最优值问题

#### LIS、最长递增子序列

LeetCode [300. 最长递增子序列](https://leetcode-cn.com/problems/longest-increasing-subsequence/) 

```c++
class Solution
{
public:
	int lengthOfLIS(vector<int> &nums)
	{
		int n = nums.size();
		vector<int> dp(n, 1);
		for (int i = 1; i < n; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if (nums[j] < nums[i])
				{
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
		}
		int res = *max_element(dp.begin(), dp.end());
		return res;
	}
};
```

一、`dp[i]` 表示 以 `nums[i]` 结尾的最长递增子序列长度。

二、上述算法是典型的穷举求解最值的算法。

#### 最大子数组和



### 计数问题

#### LeetCode [446. 等差数列划分 II - 子序列](https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/) 困难



## K次

1、LeetCode [787. K 站中转内最便宜的航班](https://leetcode-cn.com/problems/cheapest-flights-within-k-stops/) 

2、股票买卖

labuladong [团灭 LeetCode 股票买卖问题](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247494095&idx=4&sn=7aed55b22e93c0e43b83172923b51acc&scene=21#wechat_redirect)



可以看到，它们都将K次加入到了状态转移方程。



## graph DP

### 最优值问题

#### LeetCode [787. K 站中转内最便宜的航班](https://leetcode-cn.com/problems/cheapest-flights-within-k-stops/) 

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

可以看到，上述求解最优值的过程，其实和前面的LeetCode [746. 使用最小花费爬楼梯](https://leetcode-cn.com/problems/min-cost-climbing-stairs/) 、LeetCode [300. 最长递增子序列](https://leetcode-cn.com/problems/longest-increasing-subsequence/) 非常类似。



## 背包DP

### 零钱兑换

LeetCode [322. 零钱兑换](https://leetcode-cn.com/problems/coin-change/)

LeetCode [518. 零钱兑换 II](https://leetcode-cn.com/problems/coin-change-2/)



## 计数问题

### base case

DP解计数问题的base case对于empty problem，它一般会初始化为1，下面是例子：

1、leetcode [91. 解码方法](https://leetcode-cn.com/problems/decode-ways/) 中等

2、LeetCode [62. 不同路径](https://leetcode-cn.com/problems/unique-paths/) 中等

3、leetcode [416. 分割等和子集](https://leetcode-cn.com/problems/partition-equal-subset-sum/) # [星晴pro](https://leetcode-cn.com/u/eh-xing-qing/) # [一篇文章吃透背包问题！（细致引入+解题模板+例题分析+代码呈现](https://leetcode-cn.com/problems/partition-equal-subset-sum/solution/yi-pian-wen-zhang-chi-tou-bei-bao-wen-ti-a7dd/) 



LeetCode [552. 学生出勤记录 II](https://leetcode-cn.com/problems/student-attendance-record-ii/) 困难

### Fibonacci DP



## DP数组和最优解

DP数组记录的是子问题的解，而不一定是最优解，有的用DP来求解的问题，它的最优解需要另外来进行计算，下面是典型的例子：

1、LeetCode [53. 最大子数组和](https://leetcode-cn.com/problems/maximum-subarray/)

2、LeetCode [446. 等差数列划分 II - 子序列](https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/) 困难