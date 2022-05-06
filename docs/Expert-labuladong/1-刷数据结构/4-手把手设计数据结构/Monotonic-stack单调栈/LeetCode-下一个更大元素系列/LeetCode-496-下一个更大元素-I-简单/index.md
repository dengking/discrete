# LeetCode [496. 下一个更大元素 I](https://leetcode-cn.com/problems/next-greater-element-i/) 简单

## 我的解题

### 使用单调栈

是参考 labuladong [单调栈 Monotonic Stack 的使用](https://mp.weixin.qq.com/s/_b_QzXkL4e0y5241betVSg) 写出的



```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
	{
		int len = nums2.size();
		unordered_map<int, int> nge; //nge是next greater number的缩写
		stack<int> st;
		for (int i = len - 1; i >= 0; --i)
		{
			while (!st.empty() && st.top() <= nums2[i])
			{
				st.pop();
			}
			nge[nums2[i]] = st.empty() ? -1 : st.top();
			st.push(nums2[i]);
		}
		vector<int> ret;
		for (auto &&n : nums1)
		{
			ret.push_back(nge[n]);
		}
		return ret;
	}
};

int main()
{
	Solution s;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g


```



### 使用 wikipedia [All nearest smaller values](https://en.wikipedia.org/wiki/All_nearest_smaller_values)  中的DP解法

```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
	{
		int len = nums2.size();
		unordered_map<int, int> nge; //nge是next greater number的缩写
		vector<int> next_greater_index(len, -1);
		for (int i = len - 2; i >= 0; --i)
		{
			int j = i + 1;
			while (j >= 0 && j < len && nums2[j] <= nums2[i])
			{
				j = next_greater_index[j];
			}
			next_greater_index[i] = j;
			nge[nums2[i]] = j == -1 ? -1 : nums2[j];
		}
		vector<int> ret;
		for (auto &&n : nums1)
		{
			ret.push_back(nge[n]);
		}
		return ret;
	}
};

int main()
{
	Solution s;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g


```



## 二刷

```c++
// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>
#include <list>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <cmath>
#include <numeric>
#include <climits>
#include <random>
// example1.cpp
// new-delete-type-mismatch error
#include <memory>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
  {
    stack<int> stk;
    unordered_map<int, int> index;
    for (int i = nums2.size() - 1; i >= 0; --i)
    {
      while (!stk.empty() && (stk.top() <= nums2[i]))
      {
        stk.pop();
      }
      if (stk.empty())
      {
        index[nums2[i]] = -1;
      }
      else
      {
        index[nums2[i]] = stk.top();
      }
      stk.push(nums2[i]);
    }
    vector<int> res;
    for (auto &&num : nums1)
    {
      res.push_back(index[num]);
    }
    return res;
  }
};

int main()
{
  Solution s;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g

```

