# LeetCode问题整理

## Fibonacci DP 计数问题

### Fibonacci DP

#### LeetCode [70. 爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/)

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



### LeetCode [62. 不同路径](https://leetcode-cn.com/problems/unique-paths/) 中等

#### 核心code

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

#### hightlight

一、这个问题没有空问题

二、来源

宫水三叶 [DP 路径问题](https://mp.weixin.qq.com/mp/appmsgalbum?__biz=MzU4NDE3MTEyMA==&action=getalbum&album_id=1773144264147812354&scene=173&from_msgid=2247485319&from_itemidx=1&count=3&uin=&key=&devicetype=Windows+10+x64&version=6303052a&lang=zh_CN&ascene=7&fontgear=2)