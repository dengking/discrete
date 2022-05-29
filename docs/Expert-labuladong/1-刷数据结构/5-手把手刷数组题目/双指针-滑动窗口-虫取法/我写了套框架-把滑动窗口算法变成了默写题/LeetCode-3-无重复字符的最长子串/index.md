# LeetCode [3. 无重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/) 中等



## 我的解题

```C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	int lengthOfLongestSubstring(string s)
	{

		unordered_map<char, int> window;
		int str_len = s.size();

		int left = 0, right = 0;
		int valid = 0; //window中，有效字符的个数
		int len = 0; //
		int start = 0;
		while (right < str_len)
		{
			char c = s[right]; // 新进入的字符
			++right;
			++window[c];

			while (window[c] > 1) // 包含了重复字符
			{
				char d = s[left];
				++left;
				if (window[d] > 0) // c是目标字符
				{
					--window[d];
				}
			}
			// 在这里更新答案
			len = max(len, right - left);
		}
		return len;
	}
};
int main()
{
	std::string s { "abcabcbb" };
	Solution solu;
	cout << solu.lengthOfLongestSubstring(s) << endl;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g

```

