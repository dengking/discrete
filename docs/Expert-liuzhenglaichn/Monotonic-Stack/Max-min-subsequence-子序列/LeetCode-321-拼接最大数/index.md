# leetcode [321. 拼接最大数](https://leetcode-cn.com/problems/create-maximum-number/)

## [一招吃遍力扣四道题，妈妈再也不用担心我被套路啦～](https://leetcode-cn.com/problems/create-maximum-number/solution/yi-zhao-chi-bian-li-kou-si-dao-ti-ma-ma-zai-ye-b-7/)

> NOTE: 
>
> 一、这个解题是非常好的，它详细说明了思路:
>
> 1、divide-and-conquer-and-merge
>
> 



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

