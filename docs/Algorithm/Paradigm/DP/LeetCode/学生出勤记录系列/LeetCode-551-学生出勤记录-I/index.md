# LeetCode [551. 学生出勤记录 I](https://leetcode.cn/problems/student-attendance-record-i/) 简单

## 我的解题

```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	bool checkRecord(string s)
	{
		int absentCount = 0;
		int lateCount = 0;
		int len = s.size();

		for (int i = 0; i < len; ++i)
		{
			if (s[i] == 'A')
			{
				if (++absentCount == 2)
				{
					return false;
				}
			}
			if (s[i] == 'L')
			{
				if (i - 1 >= 0 && s[i - 1] == 'L') // 前一天也是迟到
				{
					if (++lateCount == 3)
					{
						return false;
					}
				}
				else
				{
					lateCount = 1;
				}
			}
		}
		return true;
	}
};

int main()
{
	Solution s;
	string str = "ALP";
	s.checkRecord(str);
}

// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g


```

