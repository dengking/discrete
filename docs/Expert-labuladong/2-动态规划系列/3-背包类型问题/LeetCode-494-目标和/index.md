# leetcode [494. 目标和](https://leetcode-cn.com/problems/target-sum/) 中等

## leetcode [一篇文章吃透背包问题！（细致引入+解题模板+例题分析+代码呈现](https://leetcode-cn.com/problems/partition-equal-subset-sum/solution/yi-pian-wen-zhang-chi-tou-bei-bao-wen-ti-a7dd/) 

x + y = sum

x - y = target

x = (sum + target) / 2



## 第一次提交

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
  int findTargetSumWays(vector<int> &nums, int target)
  {
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if ((sum + target) % 2 != 0 || sum < target)
    {
      return 0;
    }
    int x = (sum + target) / 2;
    if (x < 0)
    {
      return 0;
    }
    vector<vector<int>> dp(nums.size() + 1, vector<int>(x + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= nums.size(); ++i) // 物品
    {
      for (int j = 1; j <= x; ++j) // 背包的重量
      {
        dp[i][j] = dp[i - 1][j];

        if (j >= nums[i - 1])
        {
          dp[i][j] += dp[i - 1][j - nums[i - 1]];
        }
      }
    }
    return dp[nums.size()][x];
  }
};

```

上述程序的输出结果错误:

```
输入
[1,1,1,1,1]
3
输出
4
预期结果
5
```

刚看到这个错误一头雾水，后来看了标准答案，发现其中的 `j` 的起始值是 0，而我的上述出现的起始值是 1，这是因为：

如果背包容量为0，有多种物品可选，那么这种情况下，是有一种方案的：即什么都不选择，所以dp table第一列的初始值应该是1，而不是0，但是在后面的算法中有没有对它进行计算，所以就导致了问题。

## 第二次提交

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
  int findTargetSumWays(vector<int> &nums, int target)
  {
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if ((sum + target) % 2 != 0 || sum < target)
    {
      return 0;
    }
    int x = (sum + target) / 2;
    if (x < 0)
    {
      return 0;
    }
    vector<vector<int>> dp(nums.size() + 1, vector<int>(x + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= nums.size(); ++i) // 物品
    {
      for (int j = 0; j <= x; ++j) // 背包的重量
      {
        dp[i][j] = dp[i - 1][j];

        if (j >= nums[i - 1])
        {
          dp[i][j] += dp[i - 1][j - nums[i - 1]];
        }
      }
    }
    return dp[nums.size()][x];
  }
};

```



## [官方解题](https://leetcode-cn.com/problems/target-sum/solution/mu-biao-he-by-leetcode-solution-o0cp/)

### 方法一：回溯

```c++
class Solution {
public:
    int count = 0;

    int findTargetSumWays(vector<int>& nums, int target) {
        backtrack(nums, target, 0, 0);
        return count;
    }

    void backtrack(vector<int>& nums, int target, int index, int sum) {
        if (index == nums.size()) {
            if (sum == target) {
                count++;
            }
        } else {
            backtrack(nums, target, index + 1, sum + nums[index]);
            backtrack(nums, target, index + 1, sum - nums[index]);
        }
    }
};

```

> NOTE:
>
> 上述代码非常精简