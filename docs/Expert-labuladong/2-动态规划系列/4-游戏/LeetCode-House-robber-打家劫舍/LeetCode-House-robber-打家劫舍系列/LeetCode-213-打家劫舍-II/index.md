# [LeetCode-213. 打家劫舍 II](https://leetcode.cn/problems/house-robber-ii/)



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



### 二刷

```c++
// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>
#include <list>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <cmath>
#include <numeric>
#include <climits>
#include <random>
// example1.cpp
// new-delete-type-mismatch error
#include <memory>
#include <vector>
using namespace std;

class Solution
{
public:
  /**
   * @brief 使用divide-and-conquer思想，[0, n-2]，[1, n-2] 中选择最优的
   *
   * @param nums
   * @return int
   */
  int rob(vector<int> &nums)
  {
    int len = nums.size();
    if (len == 1)
    {
      return nums[0];
    }
    else if (len == 2)
    {
      return max(nums[0], nums[1]);
    }
    else
    {
      return max(rob(nums, 0, len - 2), //
                 rob(nums, 1, len - 1)  //
      );
    }
  }
  // dp[n] = max(dp[n-1], dp[n-2] + nums[n])
  int rob(vector<int> &nums, int start, int stop)
  {
    int len = stop - start + 1;
    vector<int> dp(len + 2);
    for (int i = start; i <= stop; ++i)
    {
      int dp_index = i - start + 2;
      dp[dp_index] = max(dp[dp_index - 1], dp[dp_index - 2] + nums[i]);
    }
    return dp[len + 1]; // 返回最后一个元素
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

