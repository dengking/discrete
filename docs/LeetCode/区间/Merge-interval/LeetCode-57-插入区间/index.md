# [LeetCode-57. 插入区间-中等](https://leetcode.cn/problems/insert-interval/) 

## 我的解题

### 思路：找到插入位置

其实思路和按照 [LeetCode-56. 合并区间](https://leetcode.cn/problems/merge-intervals/) 的思路一样，非常简单，先找到 `newInterval` 的插入位置，然后按照 LeetCode [56. 合并区间](https://leetcode.cn/problems/merge-intervals/) 中的解法进行求解，其实最最简单的方式如下:

#### 插入+sort+merge



```c++
#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <iostream>
#include <variant>
using namespace std;

class Solution
{

public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> res;
        intervals.push_back(newInterval);
        std::sort(intervals.begin(), intervals.end(), [](const auto &left, const auto &right) //
                  {                                                                           //
                      return left[0] < right[0];
                  } //
        );
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
    }
};
```

上述算法在如下用例失败：

```c++
输入
[[1,2],[3,5],[6,7],[8,10],[12,16]]
[4,8]
输出
[[1,2],[3,7],[8,10],[12,16]]
预期结果
[[1,2],[3,10],[12,16]]
```

通过查看可知，原因在将 `newInterval` 插入后，再merge 后，生成新的interval，这个新的interval再次进行merge，而前面的算法显然无法实现这一步骤。







### 使用栈机

使用栈机可以保存活状态，也就是当前区间，因为:

当下一个区间和当前区间存在交集的时候，它需要进行merge

当下一个区间和当前区间不存在交集的时候，它不需要merge，此时它可以将当前区间flush到结果集中

其实 [LeetCode-56. 合并区间](https://leetcode.cn/problems/merge-intervals/) 和本题都是基于上述思路，由于它仅仅涉及两个区间，因此它不需要显示地使用一个stack。

其实这两道题能够体现append-to-tail&flush和stack machine之间的关联。

