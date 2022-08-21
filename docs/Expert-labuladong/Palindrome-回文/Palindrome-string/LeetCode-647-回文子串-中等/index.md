# [LeetCode-647. 回文子串-中等](https://leetcode.cn/problems/palindromic-substrings/) 



## 我的解题

### 错误的

```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int countSubstrings(string s)
	{
		int res = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			res += palindrome(s, i, i);
			res += palindrome(s, i, i + 1);
		}
		return res;
	}
	int palindrome(string s, int l, int r)
	{
		while (l >= 0 && r < s.size() && s[l] == s[r])
		{
			--l;
			++r;
		}
		/**
		 * [l + 1, r - 1]
		 * 它的长度为: r - 1 - (l + 1) + 1 = r - l - 1;
		 */
		return (r - l - 1) > 0;
	}
};

int main()
{

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```



![](./为通过用例.png)

|       |      |
| ----- | ---- |
| `a`   | 0    |
| `aa`  | 01   |
| `aaa` | 012  |
| `aa`  | 12   |
| `a`   | 2    |

显然，遗漏了`a` (1)，这是因为`palindrome`函数本质上是贪心的，它尽可能地匹配更长的串。

### 正确的解法

```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int countSubstrings(string s)
	{
		int res = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			res += palindrome(s, i, i);
			res += palindrome(s, i, i + 1);
		}
		return res;
	}
	int palindrome(string s, int l, int r)
	{
		int count = 0; // 计数
		while (l >= 0 && r < s.size() && s[l] == s[r])
		{
			--l;
			++r;
			++count; 
		}

		return count;
	}
};

int main()
{

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```

