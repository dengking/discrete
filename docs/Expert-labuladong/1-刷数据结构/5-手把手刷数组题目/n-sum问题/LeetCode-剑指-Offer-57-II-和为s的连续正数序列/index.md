# [LeetCode-剑指 Offer 57 - II. 和为s的连续正数序列](https://leetcode.cn/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/) 

输入一个正整数 `target` ，输出所有和为 `target` 的连续正整数序列（至少含有两个数）。

非常类似于二分查找。

## 我的解题



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
#include <climits>
#include <random>

using namespace std;

class Solution
{
public:
  vector<vector<int>> findContinuousSequence(int target)
  {
    vector<vector<int>> res;
    for (int i = 1; i < target; ++i)
    {
      int sum = 0;
      int start = i;
      vector<int> v;
      while (sum < target)
      {
        sum += start;
        v.push_back(start);
        start++;
      }
      if (sum == target && v.size() > 1)
      {
        res.push_back(move(v));
      }
    }
    return res;
  }
};

int main()
{
}
```



## [官方解题 # 滑动窗口](https://leetcode.cn/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/solution/mian-shi-ti-57-ii-he-wei-sde-lian-xu-zheng-shu-x-2/)

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
#include <climits>
#include <random>

using namespace std;

class Solution
{
public:
  vector<vector<int>> findContinuousSequence(int target)
  {
    vector<vector<int>> res;
    vector<int> v;
    for (int l = 1, r = 2; l < r;)
    {
      int sum = (l + r) * (r - l + 1) / 2;
      if (sum == target)
      {
        v.clear();
        for (int i = l; i <= r; ++i)
        {
          v.push_back(i);
        }
        res.push_back(v);
        ++l; // 此处千万不要忘记
      }
      else if (sum < target)
      {
        ++r;
      }
      else
      {
        ++l;
      }
    }
    return res;
  }
};

int main()
{
}
```

