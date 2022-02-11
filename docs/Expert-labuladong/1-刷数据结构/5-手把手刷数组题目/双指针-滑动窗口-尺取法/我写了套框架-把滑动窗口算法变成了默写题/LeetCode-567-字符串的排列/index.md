# leetcode [567. 字符串的排列](https://leetcode-cn.com/problems/permutation-in-string/) 中等



## 我的解题

题目要求: "输入的字符串只包含小写字母"。

```C++
class Solution {
public:
bool checkInclusion(string s1, string s2)
	{
		int len1 = s1.length(), len2 = s2.length();
		if (len1 > len2)
		{
			return false;
		}
		vector<int> count1(26), count2(26);
		for (int i = 0; i < len1; ++i)
		{
			++count1[s1[i] - 'a'];
			++count2[s2[i] - 'a'];
		}
		if (count1 == count2)
		{
			return true;
		}
		for (int i = len1; i < len2; ++i)
		{
			char in = s2[i]; // 新进入的字符
			char out = s2[i - len1]; // 退出的字符
			--count2[out - 'a'];
			++count2[in - 'a'];
			if (count1 == count2)
			{
				return true;
			}
		}
		return false;
	}
};
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g

```



## labuladong [我写了套框架，把滑动窗口算法变成了默写题](https://mp.weixin.qq.com/s/ioKXTMZufDECBUwRRp3zaA)

按照其中的解法写的程序:

```C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	bool checkInclusion(string s1, string s2)
	{
		int len1 = s1.length(), len2 = s2.length();
		if (len1 > len2)
		{
			return false;
		}
		vector<int> need(26), window(26);

		for (int i = 0; i < len1; ++i)
		{
			++need[s1[i] - 'a'];
		}
		int need_valid = 0; // 不同字符的个数
		for (auto &&n : need)
		{
			if (n > 0)
				++need_valid;
		}
		int left = 0, right = 0;
		int valid = 0; //window中，有效字符的个数
		while (right < len2)
		{
			char c = s2[right]; // 新进入的字符
			++right;
			if (need[c - 'a'] > 0) // c是目标字符
			{
				++window[c - 'a'];
				if (window[c - 'a'] == need[c - 'a'])
				{
					++valid;
				}
			}
			while (right - left >= len1)
			{
				if (valid == need_valid) //
				{
					return true;
				}
				c = s2[left];
				++left;
				if (need[c - 'a'] > 0) // c是目标字符
				{
					if (window[c - 'a'] == need[c - 'a'])
					{
						--valid;
					}
					--window[c - 'a'];
				}
			}
		}
		return false;
	}
};
int main()
{
	std::string s1 { "abcdxabcde" };
	std::string s2 { "abcdeabcdx" };
	Solution solu;
	cout << solu.checkInclusion(s1, s2) << endl;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g

```

