# LeetCode [392. 判断子序列](https://leetcode-cn.com/problems/is-subsequence/) 简单



## 我的解题

### double pointer

```c++
#include <iostream>
#include <vector>
#include <utility> // std::pair
#include <unordered_map>
#include <string>
#include <map>
#include <climits> // INT_MAX
using namespace std;
class Solution
{
public:
  bool isSubsequence(string s, string t)
  {
    int first = 0, seconde = 0;
    while (first < s.size() && seconde < t.size())
    {
      if (s[first] == t[seconde++])
        ++first;
    }
    return first == s.size();// 当循环退出的时候，肯定是条件不满足的时候
  }
};

int main()
{
  string s1 = "abc";
  string s2 = "ahbgdc";
  Solution s;
  cout << s.isSubsequence(s1, s2) << endl;
}
```



### binary search



这是按照 labuladong [二分查找的妙用：判定子序列](https://mp.weixin.qq.com/s/hWi2hTrQewL_YKioGkXQJg) 中的思路所写。

```C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	bool isSubsequence(string s, string t)
	{
		/**
		 * 首先预处理t
		 * index记录了t中字符的位置信息
		 */
		vector<vector<int>> index(256); // 共256个字符
		int n = t.size();
		for (int i = 0; i < n; ++i)
		{
			index[t[i]].push_back(i);
		}
		int j = 0;
		int m = s.size();
		for (int i = 0; i < m; ++i)
		{
			char c = s[i];
			if (index[c].size() == 0) // t中不包含c
			{
				return false;
			}
			else // t中包含c
			{
				int pos = left_bound(index[c], j); // 寻找t中的所有c中，位于j后的c的位置
				if (pos == index[c].size())
				{
					return false;
				}
				j = index[c][pos] + 1;
			}
		}
		return true;
	}
	/**
	 * @brief 二分查找左侧边界
	 *
	 * @param arr
	 * @param target
	 * @return
	 */
	int left_bound(std::vector<int> arr, int target)
	{
		int left = 0, right = arr.size() - 1;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (arr[mid] == target)
			{
				right = mid - 1;
			}
			else if (arr[mid] > target)
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
		return left;
	}
};

int main()
{
	std::string s = "abc", t = "ahbgdc";
	Solution solu;
	solu.isSubsequence(s, t);
}

```

