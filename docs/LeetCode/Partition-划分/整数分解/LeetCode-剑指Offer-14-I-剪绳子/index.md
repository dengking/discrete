# leetcode [剑指 Offer 14- I. 剪绳子](https://leetcode-cn.com/problems/jian-sheng-zi-lcof/)

## 我的解题



### 动态规划解法

```C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	/**
	 * @brief dp[i] = max(dp[j] * dp[i-j], dp[j] * (i-j), j * dp[i-j], j * (i-j));
	 *
	 * @param n
	 * @return
	 */
	int cuttingRope(int n)
	{
		/*
		 *  三种特殊情况：
		 *  1、长度为1时，没法剪，最大乘积为0
		 *  2、长度为2时，最大乘积为1 × 1 = 1
		 *  3、长度为3时，最大乘积为1 × 2 = 2
		 */
		if (n <= 3)
			return n - 1;

		vector<int> dp(n + 1, 0);
		dp[1] = 1;
		dp[2] = 1;
		dp[3] = 2;
		for (int i = 4; i <= n; ++i)
		{
			for (int j = 2; j <= i / 2; ++j) // （j只需要遍历到i/2就可以了，两边对称的。比如4剪成 1|3 和 3|1 结果是一样的）
			{
				int opt1 = dp[j] * dp[i - j];
				int opt2 = j * (i - j);
				int opt3 = dp[j] * (i - j);
				int opt4 = j * dp[i - j];
				dp[i] = max( { dp[i], opt1, opt2, opt3, opt4 });
			}
		}
		return dp[n];
	}
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// Driver code
int main()
{

	Solution solu;
	vector<int> nums = { 1, 3, 5, 4, 7 };
	return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```



### 贪心算法

每次切掉3，记录有几个三，剩下的长度继续如法炮制！2-4不参与切

```C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	int cuttingRope(int n)
	{
		//return n <= 3 ? n - 1 : pow(3, n / 3) * 4 / (4 - n % 3);
		//
		if (n < 4)
			return n - 1;
		int result = 1;
		while (n > 4)
		{
			n -= 3;
			result *= 3;
		}
		return n * result;
	}

};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// Driver code
int main()
{

	Solution solu;
	vector<int> nums = { 1, 3, 5, 4, 7 };
	return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```



## 比较好的解释

[【注释型题解】动态规划--剑指14.剪绳子](https://leetcode-cn.com/problems/jian-sheng-zi-lcof/solution/zhu-shi-xing-ti-jie-dong-tai-gui-hua-jia-4xfp/)

```python
dp[i] = max(dp[j] * dp[i-j], dp[j] * (i-j), j * dp[i-j], j * (i-j));
```

共有四种可能性: 一刀下去，将绳子分为`j`、`i-j`两段，每一段都有两个选择: 

1、可以剪

2、不剪

组合起来，一共就有四种组合；

[剑指 Offer 14- I. 剪绳子，还是动态规划好理解，但是贪心真的快](https://leetcode-cn.com/problems/jian-sheng-zi-lcof/solution/jian-zhi-offer-14-i-jian-sheng-zi-huan-s-xopj/)

