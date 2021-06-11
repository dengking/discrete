# leetcode [213. 打家劫舍 II](https://leetcode-cn.com/problems/house-robber-ii/)



## 我的解题

```C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	int rob(vector<int> &nums)
	{
		int len = nums.size();
		if (len == 0)
		{
			return 0;
		}
		else if (len == 1)
		{
			return nums[0];
		}
		else
		{
			return max(rob(nums, 0, len - 2), rob(nums, 1, len - 1));
		}
	}
	/**
	 * @brief
	 *
	 * @param nums
	 * @param start 起始索引
	 * @param end 终止索引
	 * @return
	 */
	int rob(vector<int> &nums, int start, int end)
	{
//		int len = nums.size();
//		vector<int> dp(len + 1, 0);
//		dp[0] = 0;
//		dp[1] = nums[0];
//		for (int i = 2; i <= len; ++i)
//		{
//			dp[i] = max(nums[i - 1] + dp[i - 2], dp[i - 1]);
//		}
//		return dp[len];
		// 状态压缩的写法
		int len = nums.size();
		int dp_i_0 = 0;
		int dp_i_1 = 0;
		int dp_i_2 = 0;
		for (int i = start; i <= end; ++i)
		{
			dp_i_2 = max(nums[i] + dp_i_0, dp_i_1);
			dp_i_0 = dp_i_1;
			dp_i_1 = dp_i_2;
		}
		return dp_i_2;
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

