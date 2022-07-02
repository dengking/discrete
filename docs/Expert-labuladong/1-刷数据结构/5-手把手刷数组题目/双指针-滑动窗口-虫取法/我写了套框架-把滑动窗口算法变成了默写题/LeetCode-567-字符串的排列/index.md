# leetcode [567. 字符串的排列](https://leetcode.cn/problems/permutation-in-string/) 中等

## 我的解题

### 解法一

labuladong [我写了套框架，把滑动窗口算法变成了默写题](https://mp.weixin.qq.com/s/ioKXTMZufDECBUwRRp3zaA) 中的解法写的程序:

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

labuladong 给出的解法是比较复杂的，它没有应用题目的条件排列，这要求字符串连续，但是并不需要保持相对顺序，其实说白了就是: 窗口的大小是固定的，因此这个问题可以使用更加简单的滑动窗口写法，这种写法其实可以叫做"尺取法"，参见 LeetCode [567. 字符串的排列](https://leetcode.cn/problems/permutation-in-string/)  的官方解题。



### 解法二

```c++
#include <iostream>
#include <vector>
#include <queue>
#include <utility> // std::pair
#include <unordered_map>
#include <string>
#include <set>
#include <map>
#include <climits> // INT_MAX
using namespace std;

class Solution
{
public:
  bool checkInclusion(string s1, string s2)
  {
    int len1 = s1.size();
    int len2 = s2.size();
    if (len2 < len1)
    {
      return false;
    }
    vector<int> need(26);
    vector<int> window(26);
    for (int i = 0; i < len1; ++i)
    {
      ++need[s1[i] - 'a'];
      ++window[s2[i] - 'a'];
    }
    if (need == window)
      return true;
    for (int i = len1; i < len2; ++i)
    {
      ++window[s2[i] - 'a'];
      --window[s2[i - len1] - 'a'];
      if (window == need)
        return true;
    }
    return false;
  }
};

int main()
{
  Solution s;
}

```

上述解法三参考 官方解题 # [滑动窗口](https://leetcode.cn/problems/permutation-in-string/solution/zi-fu-chuan-de-pai-lie-by-leetcode-solut-7k7u/) 写的。



## 官方解题 # [滑动窗口](https://leetcode.cn/problems/permutation-in-string/solution/zi-fu-chuan-de-pai-lie-by-leetcode-solut-7k7u/)



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

> NOTE:
>
> 显然上述写法非常简单易懂，在面试过程中，这种简单易懂的程序能够节省更多的时间。





### 错误程序

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
	bool checkInclusion(string s1, string s2) {
		int s1Size = s1.size();
		int s2Size = s2.size();
		if (s1Size > s2Size) {
			return false;
		}
		unordered_map<char, int> need, window;
		
		for (int i = 0; i < s1Size; ++i) { // 初始化窗口
			++need[s1[i]];
			++window[s2[i]];
		}
		if (need == window) {
			return true;
		}
		for (int i = s1Size; i < s2Size; ++i) {
			char in = s2[i];
			char out = s2[i - s1Size];
			++window[in]; // s2[i] 被滑进窗口
			--window[out]; // s2[i - s1Size] 被滑出窗口
			if (need == window) {
				return true;
			}
		}
		return false;
	}
};
int main()
{
	string s1 = "ab", s2 = "eidbaooo";
	Solution s;
	cout << s.checkInclusion(s1, s2);
}

// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -Werror

```

