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





## robinliu.gitbooks [Sweep Line (Intervals)](https://robinliu.gitbooks.io/leetcode/content/Sweep_Line.html)



```c++
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> res;

        size_t i = 0;
        for (; i < intervals.size(); ++i)
        {
            // 比较intervals[i]和newInterval之间的位置关系
            if (intervals[i][1] < newInterval[0]) // intervals[i]在newInterval的左侧
            {
                res.push_back(intervals[i]);
            }
            else if (intervals[i][0] <= newInterval[1]) // 相交
            {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
            else // intervals[i][0] > newInterval[1] // intervals[i]在newInterval的右侧，不在相交，此时需要flush
            {
                break;
            }
        }
        res.push_back(newInterval);

        for (; i < intervals.size(); ++i)
            res.push_back(intervals[i]);
        return res;
    }
};

int main()
{
}
```

> NOTE:
>
> 一、上述这种写法的优势是充分运用了 intervals 已经sorted的事实。
>
> 