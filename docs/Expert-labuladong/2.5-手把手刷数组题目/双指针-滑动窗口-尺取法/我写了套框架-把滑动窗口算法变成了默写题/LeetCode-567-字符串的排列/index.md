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

