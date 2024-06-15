# [LeetCode-875. 爱吃香蕉的珂珂](https://leetcode.cn/problems/koko-eating-bananas/) 中等



## 我的解题

是按照 labuladong [二分搜索只能用来查找元素吗？](https://mp.weixin.qq.com/s/QC24hyg0ZgjR7-LgnEzMYg) 中给出的思路写的。



```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int minEatingSpeed(vector<int> &piles, int h)
	{
		int left = 1; // 最小速度
		int right = *max_element(std::begin(piles), std::end(piles)); // 最大速度
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			/**
			 * 以mid为speed可以吃完，但是目标是寻找最小speed，
			 * 因此，需要继续在左侧区间寻找，这好比找最左侧元素
			 */
			if (canFinish(piles, h, mid))
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

	bool canFinish(vector<int> &piles, int h, int speed)
	{
		int total = 0; // 总耗时
		for (auto &&p : piles)
		{
			total += timeOf(p, speed);
			if (total > h)
			{
				return false;
			}
		}
		return true;
	}
	int timeOf(int p, int speed)
	{
		// 三元条件运算符必须要加括号，因为它的优先级较低
		return p / speed + (p % speed > 0 ? 1 : 0);
	}
};

int main()
{
	vector<int> nums = { 30, 11, 23, 4, 20 };
	Solution s;
	s.minEatingSpeed(nums, 6);
}

```



## [官方解题](https://leetcode.cn/problems/koko-eating-bananas/solution/ai-chi-xiang-jiao-de-ke-ke-by-leetcode/)

```C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	int minEatingSpeed(vector<int> &piles, int H)
	{
		int lo = 1, hi = pow(10, 9);
		while (lo < hi)
		{
			int mi = lo + (hi - lo) / 2;
			if (!possible(piles, H, mi))
				lo = mi + 1;
			else
				hi = mi;
		}

		return lo;
	}

	// Can Koko eat all bananas in H hours with eating speed K?
	bool possible(vector<int> &piles, int H, int K)
	{
		int time = 0;
		for (int p : piles)
			time += (p - 1) / K + 1;
		return time <= H;
	}
};

int main()
{
	vector<int> nums = { 30, 11, 23, 4, 20 };
	Solution s;
	s.minEatingSpeed(nums, 6);
}

```

需要学习的是向上取整公式。