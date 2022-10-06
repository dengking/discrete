# [LeetCode-416. 分割等和子集](https://leetcode.cn/problems/partition-equal-subset-sum/) 中等



## 我的解题

按照 labuladong [经典动态规划：0-1背包问题的变体](https://mp.weixin.qq.com/s/OzdkF30p5BHelCi6inAnNg) 中，给出的思路编写的。

### 未状态压缩

```C++
/* Program to implement a stack
 using two queue */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	bool canPartition(vector<int> &nums)
	{
		int sum = accumulate(begin(nums), end(nums), 0);
		if (sum % 2 != 0) // 不是偶数，显然无法划分为两个等份
		{
			return false;
		}
		int count = nums.size();
		int cap = sum / 2; // 背包的容量
		vector<vector<bool>> dp(count + 1, vector<int>(cap + 1, false)); // dp table，一个二维矩阵
		// base case，初始化dp table: 背包容量为0，无论有多少个物品，都认为是能够实现划分为两个等和子集的
		for (int i = 0; i <= count; ++i)
		{
			dp[i][0] = true;
		}

		for (int i = 1; i <= count; ++i)
		{
			for (int j = 1; j <= cap; ++j)
			{
				if (j - nums[i - 1] < 0)
				{
					dp[i][j] = dp[i - 1][j]; //  取决于前i-1个物品是否能够凑足j
				}
				else
				{
					dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i - 1]];
				}
			}
		}
		return dp[count][cap];
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
	cout << s.canPartition(nums) << endl;

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
	bool canPartition(vector<int> &nums)
	{
		int sum = accumulate(begin(nums), end(nums), 0);
		if (sum % 2 != 0) // 不是偶数，显然无法划分为两个等份
		{
			return false;
		}
		int count = nums.size();
		int cap = sum / 2; // 背包的容量
		vector<bool> dp(cap + 1, false); // dp table，一个二维矩阵
		// base case，初始化dp table
		dp[0] = true;

		for (int i = 1; i <= count; ++i)
		{
			for (int j = cap; j >= 0; j--) // 需要注意的是: 此处是从后往前进行计算，这样才能够使用"上一行"的值
			{
				if (j - nums[i - 1] >= 0)
				{
					dp[j] = dp[j] || dp[j - nums[i - 1]];
				}
			}
		}
		return dp[cap];
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
	cout << s.canPartition(nums) << endl;

	return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```



## [LeetCode-一篇文章吃透背包问题！（细致引入+解题模板+例题分析+代码呈现）](https://leetcode.cn/problems/partition-equal-subset-sum/solution/yi-pian-wen-zhang-chi-tou-bei-bao-wen-ti-a7dd/)



## 二刷

```c++
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <numeric>

using namespace std;

class Solution
{
public:
  bool canPartition(vector<int> &nums)
  {
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0)
    {
      return false;
    }
    int len = nums.size();
    int target = sum / 2;
    vector<vector<bool>> dp(len + 1, vector<bool>(target + 1, false));
    dp[0][0] = true; // 空问题
    for (int i = 1; i <= len; ++i)
    {
      int cur_num = nums[i - 1];
      for (int j = 0; j <= target; ++j)
      {
        if (j >= cur_num)
        {
          dp[i][j] = dp[i][j] || dp[i - 1][j] || dp[i - 1][j - cur_num];
        }
        else
        {
          dp[i][j] = dp[i][j] || dp[i - 1][j];
        }
      }
    }
    return dp[len][target];
  }
};
```

