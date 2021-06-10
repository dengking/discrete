# LeetCode [516. 最长回文子序列](https://leetcode-cn.com/problems/longest-palindromic-subsequence/) 中等



## 我的解题

```C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	int longestPalindromeSubseq(string s)
	{
		int n = s.size();
		vector<vector<int>> dp(n, vector<int>(n, 0));
		for (int i = 0; i < n; ++i)
		{
			dp[i][i] = 1; // 对角线，一个字符是一个回文串
		}
		// 反着遍历保证正确的状态转移
		for (int i = n - 1; i >= 0; --i) // 行 是自底向上
			// 需要注意的是: i的初始值是 n-1，因此j的初始值是 n - 1 + 1 = n
			// 但是由于for循环有限制条件: j < n ，因此当i取n-1时，并不会进入下面的for循环
			for (int j = i + 1; j < n; ++j) // 列 是自左至右
			{
				if (s[i] == s[j])
				{
					dp[i][j] = dp[i + 1][j - 1] + 2;
				}
				else
				{
					dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
				}
			}
		return dp[0][n - 1];
	}
};
// Driver code
int main()
{

	Solution solu;
	auto s = "bbbab";
	solu.longestPalindromeSubseq(s);
	return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```

