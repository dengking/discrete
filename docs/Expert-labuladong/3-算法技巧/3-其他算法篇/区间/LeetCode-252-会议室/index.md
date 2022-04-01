# leetcode [252. 会议室](https://leetcode-cn.com/problems/meeting-rooms/)

给定一个会议时间安排的数组 intervals ，每个会议时间都会包括开始和结束的时间 `intervals[i] = [starti, endi]` ，请你判断一个人是否能够参加这里面的全部会议。

**示例 1：**

```c++
输入：intervals = [[0,30],[5,10],[15,20]]
输出：false
```

**示例 2：**

```c++
输入：intervals = [[7,10],[2,4]]
输出：true
```



## 我的解题

模拟正常的开会，显然，开始时间最早的会议最先开始，第一个会议的结束后才能够开始第二个会议，如果第二个会议的开始时间小于第一个会议的结束时间，则就串场了，则无法排出来，可以看到，下面的程序非常好的模拟这个过程。

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
  bool canAttendMeetings(vector<vector<int>> &intervals)
  {
    std::sort(intervals.begin(), intervals.end(), [](const vector<int> &left, const vector<int> &right) -> bool
              { return left[0] < right[0]; });
    for (int i = 1; i < intervals.size(); ++i)
    {
      if (intervals[i][0] < intervals[i - 1][1])
      {
        return false;
      }
    }
    return true;
  }
};

int main()
{
}
```

