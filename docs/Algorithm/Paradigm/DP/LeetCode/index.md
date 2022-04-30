# LeetCode DP问题整理



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



## 子序列、子串、子数组

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



## K次

1、LeetCode [787. K 站中转内最便宜的航班](https://leetcode-cn.com/problems/cheapest-flights-within-k-stops/)

2、股票买卖

labuladong [团灭 LeetCode 股票买卖问题](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247494095&idx=4&sn=7aed55b22e93c0e43b83172923b51acc&scene=21#wechat_redirect)



可以看到，它们都将K次加入到了状态转移方程。