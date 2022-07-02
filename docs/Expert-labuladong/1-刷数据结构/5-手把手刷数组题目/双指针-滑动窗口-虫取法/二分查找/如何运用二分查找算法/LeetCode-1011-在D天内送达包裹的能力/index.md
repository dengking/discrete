# LeetCode [1011. 在 D 天内送达包裹的能力](https://leetcode.cn/problems/capacity-to-ship-packages-within-d-days/) 中等



## 我的解题

按照 labuladong [二分搜索只能用来查找元素吗？](https://mp.weixin.qq.com/s/QC24hyg0ZgjR7-LgnEzMYg) 中的思路编写的。

```C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	int shipWithinDays(vector<int> &weights, int days)
	{
		int left = *max_element(begin(weights), end(weights));
		int right = accumulate(begin(weights), end(weights), 0);
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (possible(weights, days, mid))
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
	bool possible(vector<int> &weights, int days, int cap)
	{
		int sum = 0;
		int real_days = 0;
		for (auto &&w : weights)
		{
			sum += w;
			if (sum > cap)
			{
				++real_days;
				sum = w;
			}
			else if (sum == cap)
			{
				++real_days;
				sum = 0;
			}
		}
		if (sum > 0)
		{
			++real_days;
		}
		return real_days <= days;
	}
};
int main()
{
	vector<int> nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	Solution s;
	s.shipWithinDays(nums, 5);
}

```

