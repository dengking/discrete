# [LeetCode-541. 反转字符串 II](https://leetcode.cn/problems/reverse-string-ii/)



## 我的解答

```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
	size_t m_len { 0 };
public:

	string reverseStr(string s, int k)
	{
		m_len = s.size();
		for (size_t i = 0; i < m_len; i += 2 * k)
		{
			reverseStr(s, i, i + k - 1);
		}
		return s;
	}
	void reverseStr(string &s, size_t left, size_t right)
	{
		if (right >= m_len)
		{
			right = m_len - 1;
		}
		while (left < right)
		{
			swap(s[left], s[right]);
			++left, --right;
		}
	}
};

int main()
{
	string str { "abcdefg" };
	Solution s;
	cout << s.reverseStr(str, 2) << endl;
}
// g++ test.cpp -pedantic -Wall -Wextra --std=c++11
```



## [官方解题](https://leetcode.cn/problems/reverse-string-ii/solution/fan-zhuan-zi-fu-chuan-ii-by-leetcode-sol-ua7s/)



```c++

#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string reverseStr(string s, int k)
    {
        int n = s.length();
        for (int i = 0; i < n; i += 2 * k)
        {
            reverse(s.begin() + i, s.begin() + min(i + k, n));
        }
        return s;
    }
};

int main()
{
}
```

