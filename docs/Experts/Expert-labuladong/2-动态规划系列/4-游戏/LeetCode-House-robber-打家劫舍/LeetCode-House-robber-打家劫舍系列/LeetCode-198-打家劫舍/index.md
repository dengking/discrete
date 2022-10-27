# [LeetCode-198. 打家劫舍](https://leetcode.cn/problems/house-robber/)

## 我的解题



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
  // dp[n] = max(dp[n-1], dp[n-2] + nums[n])
  int rob(vector<int> &nums)
  {
    int len = nums.size();
    vector<int> dp(len + 2);
    for (int i = 0; i < len; ++i)
    {
      int dp_index = i + 2;
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



### 状态压缩

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


