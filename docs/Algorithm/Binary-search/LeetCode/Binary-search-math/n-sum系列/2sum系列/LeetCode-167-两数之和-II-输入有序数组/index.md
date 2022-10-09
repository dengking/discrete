# [LeetCode-167. Two Sum II - Input array is sorted](https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/)



## 我的解题



### 双指针

```C++
/* Program to implement a stack
 using two queue */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	vector<int> twoSum(vector<int> &numbers, int target)
	{
		int lo = 0, hi = numbers.size() - 1;
		int sum = 0;
		while (lo < hi)
		{
			sum = numbers[lo] + numbers[hi];
			if (sum < target)
			{
				++lo;
			}
			else if (sum > target)
			{
				--hi;
			}
			else
			{
				return
				{	lo+1, hi+1};
			}
		}
		return
		{};
	}
};

ostream& operator<<(ostream &stream, vector<int> v)
{
	for (auto &&i : v)
		stream << i;
	return stream;
}
// Driver code
int main()
{

	Solution s;
	vector<int> nums { 2, 7, 11, 15 };
	cout << s.twoSum(nums, 9) << endl;
	nums = { 2, 3, 4 };
	cout << s.twoSum(nums, 6) << endl;
	return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```

