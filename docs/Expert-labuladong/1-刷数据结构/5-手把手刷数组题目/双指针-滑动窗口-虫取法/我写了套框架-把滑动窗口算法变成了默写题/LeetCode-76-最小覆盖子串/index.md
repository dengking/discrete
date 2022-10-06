# [LeetCode-76. 最小覆盖子串](https://leetcode.cn/problems/minimum-window-substring/) 困难



## 我的解题

按照 labuladong [我写了套框架，把滑动窗口算法变成了默写题](https://mp.weixin.qq.com/s/ioKXTMZufDECBUwRRp3zaA) 中的思路写出的:

```C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	string minWindow(string s, string t)
	{

		unordered_map<char, int> need, window;
		// 预处理字符串t，便于进行匹配
		for (auto &&c : t)
			need[c]++;
		int left = 0, right = 0; // 滑动窗口的左右
		int valid = 0; // 记录窗口中，已经满足了need中字符数量的字符的个数
		// 结果
		int start = 0; //结果的起始位置
		int len = INT_MAX; //结果的长度

		while (right < s.size())
		{
			char c = s[right];
			++right;

			// 更新window
			if (need.count(c)) // c是目标字符
			{
				window[c]++; // 更新window中的字符统计
				if (window[c] == need[c]) // 字符c已经满足了要求
				{
					++valid;
				}
			}
			while (valid == need.size()) // 需要收缩window
			{
				if (right - left < len) // 需要注意，窗口是[left, right)即左开右闭，需要注意的是，由于right不属于窗口，因此它的长度不能够是: right - left + 1，这是错误的
				{
					len = right - left + 1;
					start = left;
				}
				c = s[left];
				++left;
				// 更新window
				if (need.count(c)) // c是目标字符
				{
					if (window[c] == need[c]) // 是否需要停止shrink，显然如果当前 window[c] == need[c]，那么在减少后，就不满足了，需要停止shrink了
					{
						--valid;
					}
					window[c]--; // 更新window中的字符统计
				}
			}
		}
		return len == INT_MAX ? "" : s.substr(start, len);
	}
};
int main()
{
	std::string s { "aaaaaaaaaaaabbbbbcdd" };
	std::string t { "abcdd" };
	Solution solu;
	cout << solu.minWindow(s, t) << endl;
}

```

### 二刷写的代码

```C++
#include <string>
#include <unordered_map>
#include <algorithm>
#include <random>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Solution {
public:
	string minWindow(string s, string t) {
		unordered_map<char, int> need, window;
		for (auto&& c : t) {
			need[c]++;
		}
		int left = 0, right = 0;
		int validCount = 0; // window中已经符合预期的字符数量的字符的个数
		int subStrMinLen = INT_MAX;
		int subStrStartIndex = 0;
		while (right < s.size()) {
			char inChar = s[right++];
			if (need.count(inChar)) {
				window[inChar]++;
				if (window[inChar] == need[inChar]) {
					++validCount;
				}
			}
			while (validCount == need.size())
			{
				int subStrLen = right - left; // 左开右闭区间
				if (subStrLen < subStrMinLen) {
					subStrMinLen = subStrLen;
					subStrStartIndex = left;
				}
				char outChar = s[left++];
				if (need.count(outChar)) {
					
					if (window[outChar] == need[outChar]) {
						--validCount;
					}
					window[outChar]--;
				}
			}
		}
		return subStrMinLen == INT_MAX ? "" : s.substr(subStrStartIndex, subStrMinLen);
	}
};

int main()
{
	Solution s;
}

// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -Werror

```

