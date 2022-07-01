# leetcode [53. 最大子序和](https://leetcode-cn.com/problems/maximum-subarray/)



## 我的解题

### DP原版

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
   * @brief 整体思路是穷举以nums[i]结尾的最大子数组和然后将这些子数组和打擂台选择出最优值
   *
   * @param nums
   * @return int
   */
  int maxSubArray(vector<int> &nums)
  {
    vector<int> dp(nums.size()); //以nums[i]结尾的最大子数组和
    dp[0] = nums[0];             // base case
    for (int i = 1; i < nums.size(); ++i)
    {
      if (dp[i - 1] + nums[i] > nums[i]) // 有增益则与前面的相连
      {
        dp[i] = nums[i] + dp[i - 1];
      }
      else
      {
        dp[i] = nums[i]; // 自成一家
      }
    }
    return *std::max_element(dp.begin(), dp.end()); // 取出最大值
  }
};

// Driver code
int main()
{

  Solution solu;
  vector<int> nums = {2, 4, 6, 8, 10};
  solu.maxSubArray(nums);
  return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```



### DP压缩版

```C++
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
   * @brief 整体思路是穷举以nums[i]结尾的最大子数组和然后将这些子数组和打擂台选择出最优值
   *
   * @param nums
   * @return int
   */
  int maxSubArray(vector<int> &nums)
  {
    int tmp_sum = nums[0], res = nums[0];

    for (int i = 1; i < nums.size(); ++i)
    {
      tmp_sum = max(tmp_sum + nums[i], nums[i]);
      res = max(res, tmp_sum);
    }
    return res;
  }
};

// Driver code
int main()
{

  Solution solu;
  vector<int> nums = {2, 4, 6, 8, 10};
  solu.maxSubArray(nums);
  return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

