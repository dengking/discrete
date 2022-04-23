# leetcode [321. 拼接最大数](https://leetcode-cn.com/problems/create-maximum-number/)

## [一招吃遍力扣四道题，妈妈再也不用担心我被套路啦～](https://leetcode-cn.com/problems/create-maximum-number/solution/yi-zhao-chi-bian-li-kou-si-dao-ti-ma-ma-zai-ye-b-7/)

> NOTE: 
>
> 一、这个解题是非常好的，它是"divide-and-conquer-and-merge"非常经典的例题
>
> 

和第一道题类似，只不不过这一次是两个**数组**，而不是一个，并且是求最大数。

最大最小是无关紧要的，关键在于是两个数组，并且要求从两个数组选取的元素个数加起来一共是 k。

然而在一个数组中取 k 个数字，并保持其最小（或者最大），我们已经会了。但是如果问题扩展到两个，会有什么变化呢？

实际上，问题本质并没有发生变化。假设我们从 nums1 中取了 k1 个，从 num2 中取了 k2 个，其中 k1 + k2 = k。而 k1 和 k2 这 两个子问题我们是会解决的。由于这两个子问题是相互独立的，因此我们只需要分别求解，然后将结果合并即可。

假如 k1 和 k2 个数字，已经取出来了。那么剩下要做的就是将这个长度分别为 k1 和 k2 的数字，合并成一个长度为 k 的数组合并成一个最大的数组。



## 我的解答

```C++
#include <bits/stdc++.h>
using namespace std;

using index_t = size_t;
class Solution
{
public:
	/**
	 * @brief 从 nums 中挑出k个最大的，并保持相对位置不变
	 *
	 * @param nums
	 * @return
	 */
	vector<int> pickMax(vector<int> &nums, size_t k)
	{
		vector<int> ret;
		size_t len = nums.size();
		size_t delete_count = len - k;

		for (auto &&num : nums)
		{
			while (ret.size() > 0 && delete_count > 0 && ret.back() < num)
			{
				ret.pop_back();
				--delete_count;
			}
			ret.push_back(num);
		}
		for (; delete_count > 0; --delete_count)
		{
			ret.pop_back();
		}
		return ret;

	}
	vector<int> merge(const vector<int> &nums1, const vector<int> &nums2)
	{
		vector<int> ret;
		index_t i1 = 0, i2 = 0;
		while (i1 < nums1.size() && i2 < nums2.size())
		{
			if (nums1[i1] > nums2[i2])
			{
				ret.push_back(nums1[i1]);
				++i1;
			}
			else
			{
				ret.push_back(nums2[i2]);
				++i2;
			}
		}
		while (i1++ < nums1.size())
		{
			ret.push_back(nums1[i1]);
		}
		while (i2++ < nums2.size())
		{
			ret.push_back(nums2[i2]);
		}
		return ret;
	}
	friend bool operator>(const vector<int> &nums1, const vector<int> &nums2)
	{
		if (nums1.size() == nums2.size())
		{
			for (index_t i = 0; i < nums1.size(); ++i)
			{
				if (nums1[i] > nums2[i])
				{
					return true;
				}
			}
			return false;
		}
		else if (nums1.size() > nums2.size())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, size_t k)
	{
		vector<int> max;
		for (index_t i = 0; i < k; ++i)
		{
			if (i <= nums1.size() && k - i <= nums2.size())
			{
				auto temp = merge(pickMax(nums1, i), pickMax(nums2, k - i));
				if (max < temp)
				{
					max = temp;
				}
			}
		}
		return max;
	}
};
ostream& operator<<(ostream &s, vector<int> v)
{
	for (auto &&i : v)
	{
		s << i;
	}
	return s;
}

// Driven Program
int main()
{
	Solution s;
	vector<int> nums1 = { 3, 4, 6, 5 };
	vector<int> nums2 = { 9, 1, 2, 5, 8, 3 };
	size_t k = 5;
	cout << s.maxNumber(nums1, nums2, k) << endl;

	nums1 = { 6, 7 };
	nums2 = { 6, 0, 4 };
	k = 5;
	cout << s.maxNumber(nums1, nums2, k) << endl;

	nums1 = { 3, 9 };
	nums2 = { 8, 9 };
	k = 3;
	cout << s.maxNumber(nums1, nums2, k) << endl;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```

