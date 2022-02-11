# leetcode [53. 最大子序和](https://leetcode-cn.com/problems/maximum-subarray/)



## 我的解题

```C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	int maxSubArray(vector<int> &nums)
	{
		int dp_0 = nums[0];
		int res = dp_0;

		int dp_1 = dp_0;
		int len = nums.size();
		for (int i = 1; i < len; ++i)
		{
			dp_1 = max(nums[i], dp_0 + nums[i]);
			dp_0 = dp_1;
			res = max(res, dp_1);
		}
		return res;
	}
};
// Driver code
int main()
{

	Solution solu;
	vector<int> nums = { 1, 3, 5, 4, 7 };
	return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```

