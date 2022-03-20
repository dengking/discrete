# leetcode [494. 目标和](https://leetcode-cn.com/problems/target-sum/) 中等

x + y = sum

x - y = target

x = (sum + target) / 2



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
    
  }
};
```

