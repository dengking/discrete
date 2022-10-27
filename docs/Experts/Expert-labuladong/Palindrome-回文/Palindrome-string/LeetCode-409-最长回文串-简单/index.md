# [LeetCode-409. 最长回文串-简单](https://leetcode.cn/problems/longest-palindrome/) 

## 我的解题

典型的贪心思路

需要注意的是，对于数量为奇数的字符，也是可以加入的，可以选取其中的部分加入。

## [官方解题](https://leetcode.cn/problems/longest-palindrome/solution/zui-chang-hui-wen-chuan-by-leetcode-solution/)

```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int longestPalindrome(string s)
	{
		unordered_map<char, int> count;
		for (auto &&c : s)
		{
			++count[c];
		}
		int res = 0;
		for (auto &&p : count)
		{
			res += (p.second / 2 * 2);
			if (res % 2 == 0 && p.second % 2 != 0)
			{
				res += 1;
			}
		}
		return res;
	}
};

int main()
{

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```

