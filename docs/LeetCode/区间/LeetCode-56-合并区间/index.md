# leetcode [56. 合并区间](https://leetcode.cn/problems/merge-intervals/) 中等



## 我的解题

```c++
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
  vector<vector<int>> merge(vector<vector<int>> &intervals)
  {
    std::sort(intervals.begin(), intervals.end(), [](const auto &left, const auto &right) //
              {                                                                           //
                return left[0] < right[0];                                                //
              }                                                                           //
    );
    vector<vector<int>> res;
    int start = intervals[0][0];
    int stop = intervals[0][1];
    for (int i = 1; i < intervals.size(); ++i)
    {
      if (intervals[i][0] <= stop)
      {
        start = min(start, intervals[i][0]);
        stop = max(stop, intervals[i][1]);
      }
      else
      {
        res.push_back({start, stop});
        start = intervals[i][0];
        stop = intervals[i][1];
      }
    }
    res.push_back({start, stop});
    return res;
  }
};

int main()
{
}
```

