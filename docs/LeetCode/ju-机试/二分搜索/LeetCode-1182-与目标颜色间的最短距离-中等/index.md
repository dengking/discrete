# [1182. 与目标颜色间的最短距离](https://leetcode.cn/problems/shortest-distance-to-target-color/) 中等

给你一个数组 `colors`，里面有 `1`、`2`、 `3` 三种颜色。

我们需要在 `colors` 上进行一些查询操作 `queries`，其中每个待查项都由两个整数 `i` 和 `c` 组成。

现在请你帮忙设计一个算法，查找从索引 `i` 到具有目标颜色 `c` 的元素之间的最短距离。

如果不存在解决方案，请返回 `-1`。

**示例 1：**

```
输入：colors = [1,1,2,1,3,2,2,3,3], queries = [[1,3],[2,2],[6,1]]
输出：[3,0,3]
解释： 
距离索引 1 最近的颜色 3 位于索引 4（距离为 3）。
距离索引 2 最近的颜色 2 就是它自己（距离为 0）。
距离索引 6 最近的颜色 1 位于索引 3（距离为 3）。
```

**示例 2：**

```
输入：colors = [1,2], queries = [[0,3]]
输出：[-1]
解释：colors 中没有颜色 3。
```

## 我的解题

### binary search

这道题和labuladong [二分查找的妙用：判定子序列](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484479&idx=1&sn=31a3fc4aebab315e01ea510e482b186a&scene=21#wechat_redirect) 中提出的解法有些类似：

1、接口会被反复调用，因此提醒我可能需要以空间换时间

2、保存每个节点的位置信息，然后left-bound binary search或者right- bound binary search距离它的最近位置，需要注意的是，这一步做完后，还需要进行特殊的处理。

#### 第一次解题

```c++
#include <iostream>
#include <vector>
#include <utility> // std::pair
#include <unordered_map>
#include <string>
#include <map>
#include <climits> // INT_MAX
using namespace std;

class Solution
{
public:
  vector<int> shortestDistanceColor(vector<int> &colors, vector<vector<int> > &queries)
  {
    unordered_map<int, vector<int> > color2indexes;
    for (int i = 0; i < colors.size(); ++i)
    {
      color2indexes[colors[i]].push_back(i);
    }
    vector<int> res;
    for (auto &&q : queries)
    {
      int color = q[1];
      int index = q[0];
      if (color2indexes.count(color))
      {
        if (colors[index] == color) // 颜色相等，则距离为0
        {
          res.push_back(0);
        }
        else
        {
          auto lower = lower_bound(color2indexes[color].begin(), color2indexes[color].end(), index);
          if (lower == color2indexes[color].end()) // 不存在
          {
            res.push_back(index - color2indexes[color].back());
          }
          else if (lower == color2indexes[color].begin())
          {
            res.push_back(color2indexes[color].front() - index);
          }
          else
          {
            int minDis = INT_MAX;
            int lowerIndex = std::distance(color2indexes[color].begin(), lower);
            if (lowerIndex - 1 >= 0)
            {
              minDis = min(minDis, color2indexes[color][lowerIndex] - color2indexes[color][lowerIndex - 1]);
            }
            if (lowerIndex + 1 < color2indexes[color].size())
            {
              minDis = min(minDis, color2indexes[color][lowerIndex + 1] - color2indexes[color][lowerIndex]);
            }
            res.push_back(minDis);
          }
        }
      }
      else
      {
        res.push_back(-1);
      }
    }
    return res;
  }
};

int main()
{
  Solution s;
  vector<int> colors{2, 1, 2, 2, 1};
  vector<vector<int> > queries{{1, 1}, {4, 3}, {1, 3}, {4, 2}, {2, 1}};
  s.shortestDistanceColor(colors, queries);
}

```

上述算法在如下测试用例错误：

```
输入
[2,1,2,2,1]
[[1,1],[4,3],[1,3],[4,2],[2,1]]
输出
[0,-1,-1,1,3]
预期结果
[0,-1,-1,1,1]
```

显然问题出在最后一个最后一个查询 `[2,1]` 上。

首先验证一下:

颜色1的index：`[1, 4]`

```c++
#include <iostream>
#include <vector>
#include <utility> // std::pair
#include <unordered_map>
#include <string>
#include <map>
#include <climits> // INT_MAX
using namespace std;

int main()
{
  vector<int> colors{1,4};

  auto lower = lower_bound(colors.begin(), colors.end(), 2);
  if(lower == colors.end()){
    cout<<"未查到"<<endl;
  }else{
    cout<<std::distance(colors.begin(), lower)<<endl;
  }
}

```

输出为： 1；显然是能够找到的。

 

#### 第二次解题

```c++
class Solution
{
public:
  vector<int> shortestDistanceColor(vector<int> &colors, vector<vector<int> > &queries)
  {
    unordered_map<int, vector<int> > color2indexes;
    for (int i = 0; i < colors.size(); ++i)
    {
      color2indexes[colors[i]].push_back(i);
    }
    vector<int> res;
    for (auto &&q : queries)
    {
      int color = q[1];
      int index = q[0];
      if (color2indexes.count(color))
      {
        if (colors[index] == color) // 颜色相等，则距离为0
        {
          res.push_back(0);
        }
        else
        {
          auto lower = lower_bound(color2indexes[color].begin(), color2indexes[color].end(), index);// lower指向的是大于等于index的第一个元素
          if (lower == color2indexes[color].end()) // index比所有的都要大，显然此时index距离最后一个元素最近
          {
            res.push_back(index - color2indexes[color].back()); 
          }
          else if (lower == color2indexes[color].begin()) // index比所有的都要小，显然，此时index距离第一个最近
          {
            res.push_back(color2indexes[color].front() - index);
          }
          else
          {
            int minDis = *lower - index;
            if (std::distance(lower, color2indexes[color].begin()) >= 1)
            {
              minDis = min(minDis, index - *(lower - 1);
            }
            res.push_back(minDis);
          }
        }
      }
      else
      {
        res.push_back(-1);
      }
    }
    return res;
  }
};

```

上述算法能够ac。

#### 第三次解题

```c++
#include <iostream>
#include <vector>
#include <utility> // std::pair
#include <unordered_map>
#include <string>
#include <map>
#include <climits> // INT_MAX
using namespace std;

class Solution
{
public:
  vector<int> shortestDistanceColor(vector<int> &colors, vector<vector<int> > &queries)
  {
    unordered_map<int, vector<int> > color2indexes;
    for (int i = 0; i < colors.size(); ++i)
    {
      color2indexes[colors[i]].push_back(i);
    }
    vector<int> res;
    for (auto &&q : queries)
    {
      int color = q[1];
      int index = q[0];
      if (color2indexes.count(color))
      {
        if (colors[index] == color) // 颜色相等，则距离为0
        {
          res.push_back(0);
        }
        else
        {
          auto lower = lower_bound(color2indexes[color].begin(), color2indexes[color].end(), index); // lower指向的是大于等于index的第一个元素
          if (lower == color2indexes[color].end())                                                   // index比所有的都要大，显然此时index距离最后一个元素最近
          {
            res.push_back(index - color2indexes[color].back());
          }
          else if (lower == color2indexes[color].begin()) // index比所有的都要小，显然，此时index距离第一个最近
          {
            res.push_back(color2indexes[color].front() - index);
          }
          else
          {
            int minDis = *lower - index;
            if (std::distance(color2indexes[color].begin(), lower) >= 1)
            {
              minDis = min(minDis, index - *(lower - 1));
            }
            res.push_back(minDis);
          }
        }
      }
      else
      {
        res.push_back(-1);
      }
    }
    return res;
  }
};

int main()
{
}

```

