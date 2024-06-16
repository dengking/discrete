# [LeetCode-438. 找到字符串中所有字母异位词-中等](https://leetcode.cn/problems/find-all-anagrams-in-a-string/) 

## 我的解题

```C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	vector<int> findAnagrams(string s, string p)
	{

		unordered_map<char, int> need, window;
		for (auto &&c : p)
		{
			++need[c];
		}
		int str_len = s.size();
		int p_len = p.size();
		int left = 0, right = 0;
		int valid = 0; //window中，有效字符的个数
		int start = 0;
		vector<int> res;
		while (right < str_len)
		{
			char c = s[right]; // 新进入的字符
			++right;
			if (need.count(c))
			{
				++window[c];
				if (window[c] == need[c])
				{
					++valid;
				}
			}
			while (right - left >= p_len) //
			{
				if (valid == need.size())
				{
					res.push_back(left);
				}
				char d = s[left];
				++left;
				if (window[d] > 0) // c是目标字符
				{
					if (window[d] == need[d])
					{
						--valid;
					}
					--window[d];
				}
			}
		}
		return res;
	}
};
int main()
{
	std::string s { "cbaebabacd" };
	std::string p { "abc" };
	Solution solu;
	auto res = solu.findAnagrams(s, p);
	for (auto &&v : res)
	{
		cout << v << endl;
	}
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g

```

