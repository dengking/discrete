# LeetCode [300. 最长递增子序列](https://leetcode-cn.com/problems/longest-increasing-subsequence/)



## 我的解题

参考 labuladong [动态规划设计之最长递增子序列](https://mp.weixin.qq.com/s/02o_OPgePjaz3dXnw9TA1w)。

### 动态规划



```C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	int lengthOfLIS(vector<int> &nums)
	{
		int n = nums.size();
		vector<int> dp(n, 1);
		for (int i = 1; i < n; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if (nums[j] < nums[i])
				{
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
		}
		int res = *max_element(dp.begin(), dp.end());
		return res;
	}
};
// Driver code
int main()
{

	Solution solu;
	return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```

它和最大子段和是非常类似的。

