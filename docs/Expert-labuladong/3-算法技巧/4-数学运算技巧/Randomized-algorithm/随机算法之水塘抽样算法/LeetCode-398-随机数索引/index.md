# LeetCode [398. 随机数索引](https://leetcode.cn/problems/random-pick-index/)

这个题目没有说明的是这个数组是单调递增的。

## 我的解题



```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
	vector<int> &m_nums;
	size_t m_len;
public:
	/** @param head The linked list's head.
	 Note that the head is guaranteed to be not null, so it contains at least one node. */
	Solution(vector<int> &nums) :
					m_nums { nums }, m_len { nums.size() }
	{

	}

	int pick(int target)
	{
		int res = 0;
		int k = 1;
		for (int i = 0; i < m_len; ++i)
		{
			int val = m_nums[i];
			if (val == target)
			{
				if (rand() % k == 0)
				{
					res = i;
				}
				++k;
			}
		}
		return res;
	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

int main()
{

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```

