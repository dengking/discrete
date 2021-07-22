# LeetCode [1682. 最长回文子序列 II](https://leetcode-cn.com/problems/longest-palindromic-subsequence-ii/) 中等



## 我的解题

### 错误的尝试

```C++
// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

class Solution
{
	int max_len { 0 };
public:
	/**
	 * @brief dp[i][j] = dp[i+1][j-1] + 2 ; s[i] == s[j] && last_char != s[i]
	 * 					 max(dp[i][j-1], dp[i+1][j]) ; s[i] != s[j]
	 *
	 * 		需要知道序列，才能够
	 * @param s
	 * @return
	 */
	int longestPalindromeSubseq(string s)
	{
		int str_len = s.size();
		vector<vector<pair<char, int>>> dp(str_len, vector<pair<char, int>>(str_len, { 0, 0 }));
		for (int i = 0; i < str_len; ++i)
		{
			dp[i][i].second = 1;
		}
		for (int i = str_len - 2; i >= 0; --i)
		{
			for (int j = i + 1; j < str_len; ++j)
			{
				if (s[i] == s[j])
				{
					if (dp[i + 1][j - 1].first)
					{
						if (s[i] != dp[i + 1][j - 1].first)
						{
							dp[i][j].first = s[j];
							dp[i][j].second = 2 + dp[i + 1][j - 1].second;
						}
					}
					else
					{
						dp[i][j].first = s[j];
						dp[i][j].second = 2 + dp[i + 1][j - 1].second;
					}
				}
				else
				{
					dp[i][j].second = max(dp[i][j - 1].second, dp[i + 1][j].second);
				}
				if (dp[i][j].second % 2 == 0)
				{
					max_len = max(max_len, dp[i][j].second);
				}
			}
		}
		return max_len;
	}
};

// Driver code
int main()
{
	Solution s;
	s.longestPalindromeSubseq("bbabab");
	return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```



## LeetCode [动态规划](https://leetcode-cn.com/problems/longest-palindromic-subsequence-ii/solution/dong-tai-gui-hua-by-jason-2-9z6w/)

> NOTE: 
>
> 其中进行了比较好的分析

我一开始理解对题目的分析不透彻，走了弯路。

要求回文子序列是偶数长度。我一直尝试记录区间内的所有回文子序列，没有认识到，奇数长度的回文子序列，要变成偶数长度的回文子序列，必然要在首尾增加
单个字符，必然要求回文子序列中间部分出现连续相同的字符，这又与第四个条件相矛盾。

举例说明1：有一个回文子序列"aaa"，增加一个a，就变成"aaaa"，但是"aaa"是不满足条件四的。

举例说明2：有一个回文子序列"aba"，增加一个任何字母，都不能将其变成回文子序列。

这样就排除了任何奇数长度的回文子序列，大大简化了问题。满足条件的回文子序列，一定时偶数长度的回文子序列，加上首尾相同字符形成的。这样只需要记录偶数长度的回文子序列，同时记录回文子序列的首尾字符。

### 解法二 动态规划

**设`d[i][j][c]`表示区间[i,j]内首尾字符为c时的最长回文子序列。**

#### base case

初值：只记录相同相邻字符的子串，长度为2。其它为0.

#### 递推关系

如果 `s[i] == s[j]` 时，那么区间`[i+1,j-1]`内首尾不是`s[i]`的最长回文子序列对`d[i][j][s[i]]`的长度有贡献。也对区间`[i,j]`不是以`s[i]`为首尾的最长回文子序列的长度有贡献，

```java
for(c in ['a','z']){
    if(c == s[i]) pass;
    d[i][j][s[i]] = max(d[i][j][s[i]], d[i+1][j-1][c] + 2);
    d[i][j][c] = d[i+1][j-1][c];
}
```

如果 `s[i] != s[j]` 时，那么区间`[i,j-1]`内首尾是`s[i]`的**最长回文子序列**对`d[i][j][s[i]]`的长度有贡献。
那么区间`[i+1,j]`内首尾是`s[j]`的最长回文子序列对`d[i][j][s[j]]`的长度有贡献。区间`[i+1,j-1]`内首尾不是`s[i]`也不是`s[j]`的字符`c`的最长回文子序列对`d[i][j][c]`的长度有贡献。



## LeetCode [O(n^2)复杂度dp](https://leetcode-cn.com/problems/longest-palindromic-subsequence-ii/solution/on2fu-za-de-dp-by-xhzhang-l83r/)

下面是可以AC的代码:

```Java
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public int longestPalindromeSubseq(String s)
	{
		int len = s.length();
		if (len < 2) return 0;
		int[][] dp = new int[len][len];
		char[][] noChar = new char[len][len]; // 边界字母，即下一次状态转移不能选择的字母
		for (int i=len-2; i>=0; i--)
		{
			for (int j=i+1; j<len; j++)
			{
				if (s.charAt(i) == s.charAt(j)) // 两端字母相等，可扩展长度
				{ 
					dp[i][j] = i == j - 1 ? 2:// 长度为2的回文子序列
					noChar[i+1][j-1] == s.charAt(i) ? dp[i+1][j-1] :// 当前字母与上次的边界字母相等
					dp[i+1][j-1] + 2;// 当前字母与上次的边界字母不等
					noChar[i][j] = s.charAt(i);// 更新边界字母
				}
				else
				{ // 两端字母不等，不扩展长度
					dp[i][j] = Math.max(dp[i][j-1], dp[i+1][j]);
					noChar[i][j] = dp[i][j-1] > dp[i+1][j] ? noChar[i][j-1] :
					dp[i][j-1] < dp[i+1][j] ? noChar[i+1][j] :
					noChar[i][j-1] == noChar[i+1][j] ? noChar[i][j-1] : 0;
					// 状态(i,j)可从(i+1,j)或(i,j-1)状态转移而来，(i+1,j)与(i,j-1)状态的边界字母不等时，(i,j)可取任一个，那么下次扩展长度便可以以任意字母扩展
				}
			}
		}
		return dp[0][len-1];
	}
};

int main()
{

}

```



### 简化的版本



```Java
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public int longestPalindromeSubseq(String s)
	{
		int len = s.length();
		if (len < 2) return 0;
		int[][] dp = new int[len][len];
		char[][] noChar = new char[len][len]; // 边界字母，即下一次状态转移不能选择的字母
		for (int i=len-2; i>=0; i--)
		{
			for (int j=i+1; j<len; j++)
			{
				if (s.charAt(i) == s.charAt(j)) // 两端字母相等，可扩展长度
				{
					if(i == j - 1)
					{
						dp[i][j] = 2; // 长度为2的回文子序列
					}
					else if(noChar[i+1][j-1] == s.charAt(i)) // 当前字母与上次的边界字母相等
					{
						dp[i][j] = dp[i+1][j-1]; // 长度为2的回文子序列
					}
					else
					{
						dp[i][j] = dp[i+1][j-1] + 2; // 当前字母与上次的边界字母不等
					}
					noChar[i][j] = s.charAt(i); // 更新边界字母
				}
				else // 两端字母不等，不扩展长度
				{
					dp[i][j] = Math.max(dp[i][j-1], dp[i+1][j]);
					if(dp[i][j-1] > dp[i+1][j] )
					{
						noChar[i][j] = noChar[i][j-1];
					}
					else if(dp[i][j-1] < dp[i+1][j])
					{
						noChar[i][j] = noChar[i+1][j];
					}
					else if(noChar[i][j-1] == noChar[i+1][j] )
					{
						noChar[i][j] = noChar[i][j-1];
					}
					else
					{
						noChar[i][j] = 0;
					}
					// 状态(i,j)可从(i+1,j)或(i,j-1)状态转移而来，(i+1,j)与(i,j-1)状态的边界字母不等时，(i,j)可取任一个，那么下次扩展长度便可以以任意字母扩展
				}
			}
		}
		return dp[0][len-1];
	}
};

int main()
{

}

```

