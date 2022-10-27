# [LeetCode-5. 最长回文子串](https://leetcode.cn/problems/longest-palindromic-substring/) 中等



## 我的解题

```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	string longestPalindrome(string s)
	{
		string res;
		for (int i = 0; i < s.size(); ++i)
		{
			string s1 = palindrome(s, i, i);
			if (s1.size() > res.size())
			{
				res = move(s1);
			}
			string s2 = palindrome(s, i, i + 1);
			if (s2.size() > res.size())
			{
				res = move(s2);
			}
		}
		return res;
	}
	string palindrome(string s, int l, int r)
	{
		while (l >= 0 && l < s.size() && s[l] == s[r])
		{
			--l;
			++r;
		}
		/**
		 * [l + 1, r - 1]
		 * 它的长度为: r - 1 - (l + 1) + 1 = r - l - 1;
		 */
		return s.substr(l + 1, r - l - 1);
	}
};

int main()
{

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```

