# leetcode [198. 打家劫舍](https://leetcode-cn.com/problems/house-robber/)

## 我的解题



```C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	int rob(vector<int> &nums)
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
		for (int i = 1; i <= len; ++i)
		{
			dp_i_2 = max(nums[i - 1] + dp_i_0, dp_i_1);
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

### 第一次写的错误程序

我第一次的时候，是按照下面的方式写的:

```C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	int rob(vector<int> &nums)
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
		int dp_i_1 = nums[0];
		int dp_i_2 = 0;
		for (int i = 2; i <= len; ++i)
		{
			dp_i_2 = max(nums[i - 1] + dp_i_0, dp_i_1);
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

结果上述程序在`nums`长度为1，即只有一个物品的时候，返回是错误值`0`，我审视了一下代码，发现由于 `for (int i = 2; i <= len; ++i)` 中，`i`是从2开始的，因此，无法进入递推逻辑，这就导致了程序直接返回`dp_i_2`。

我这么写的原因是:

上述状态压缩的版本是根据前面被注释的未压缩的版本写的，在未压缩的版本中，采用的是"recurrence relation递归状态转移方程-DP-依赖前两项-从2开始遍历-防止越界"，由于存在一些细节的差异，在状态压缩的版本中，也"从2开始遍历"是行不通的；

一开始，我并不知道如何进行修改，因为只能够像 labuladong [团灭 LeetCode 打家劫舍问题](https://mp.weixin.qq.com/s/z44hk0MW14_mAQd7988mfw) 中的示例代码那样，反过来写，后来推敲了它的code，发现由于执行的是加法、加0等于空操作，就修改处了上面正确的程序。

这提示我，动态规划算法，一定要让返回值从递归结果中得到，最好不要不经递归直接返回；
