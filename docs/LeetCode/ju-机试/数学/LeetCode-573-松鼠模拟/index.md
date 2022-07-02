# [573. 松鼠模拟](https://leetcode.cn/problems/squirrel-simulation/) 中等

现在有一棵树，一只松鼠和一些坚果。位置由二维网格的单元格表示。你的目标是找到松鼠收集所有坚果的**最小路程**，且坚果是一颗接一颗地被放在树下。松鼠一次最多只能携带**一颗**坚果，松鼠可以向上，向下，向左和向右四个方向移动到相邻的单元格。移动次数表示路程。

**输入 1:**

输入: 
高度 : 5
宽度 : 7
树的位置 : [2,2]
松鼠 : [4,4]
坚果 : [[3,0], [2,5]]
输出: 12
解释:

![img](https://assets.leetcode.com/uploads/2018/10/22/squirrel_simulation.png)

## 我的解题

### 思路

第一次出发，顺带一个到树上

后面都是往返与树和坚果

因此，最短距离是由第一次决定的

这样就比较好算了

计算每个坚果到树的距离

松鼠到每个坚果到距离

对于每个坚果，要么顺带，要么往返，需要比较两者的成本：

1、往返 >=顺带

选择顺带

2、往返 <=顺带

选择往返



### 暴力法

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
  int minDistance(int height, int width, vector<int> &tree, vector<int> &squirrel, vector<vector<int> > &nuts)
  {
    vector<int> nut2tree;
    vector<int> nut2squirrel;
    int N = nuts.size();

    // int start_nut_min_dist = INT_MAX;
    // int start_nut_i = 0;
    for (int i = 0; i < N; ++i)
    {
      int nut2tree_dist = cal_distance(nuts[i], tree);
      int nut2squirrel_dist = cal_distance(nuts[i], squirrel);
      // int dist = nut2tree_dist + nut2squirrel_dist;
      // if (dist < start_nut_min_dist)
      // {
      //   start_nut_min_dist = dist;
      //   start_nut_i = i;
      // }
      nut2tree.push_back(nut2tree_dist);
      nut2squirrel.push_back(nut2squirrel_dist);
    }
    int res = INT_MAX;

    for (int start_nut_i = 0; start_nut_i < N; ++start_nut_i)
    {
      int total_dist = nut2tree[start_nut_i] + nut2squirrel[start_nut_i];
      for (int i = 0; i < N; ++i)
      {
        if (i != start_nut_i)
        {
          total_dist += 2 * nut2tree[i];
        }
      }
      res = min(res, total_dist);
    }
    return res;
  }

  int cal_distance(vector<int> &start, vector<int> &stop)
  {
    return abs(start[0] - stop[0]) + abs(start[1] - stop[1]);
  }
};

int main()
{
  Solution s;
}

```

上述做法也是能够ac的。

#### 第二次解题

```c++
#include <iostream>
#include <vector>
#include <utility> // std::pair
#include <unordered_map>
#include <string>
#include <set>
#include <map>
#include <climits> // INT_MAX
using namespace std;

class Solution
{
public:
  int minDistance(int height, int width, vector<int> &tree, vector<int> &squirrel, vector<vector<int> > &nuts)
  {
    vector<int> wanfan_dist_v;
    vector<int> shundai_dist_v;
    int N = nuts.size();

    vector<int> shundai_set;
    for (int i = 0; i < N; ++i)
    {
      int nut2tree_dist = cal_distance(nuts[i], tree);
      int nut2squirrel_dist = cal_distance(nuts[i], squirrel);
      int shundai_dist = nut2tree_dist + nut2squirrel_dist;
      int wangfan_dist = nut2tree_dist * 2;
      if (wangfan_dist >= shundai_dist)
      {
        shundai_set.push_back(i);
      }
      wanfan_dist_v.push_back(wangfan_dist);
      shundai_dist_v.push_back(shundai_dist);
    }
    int start_nut_i = 0;

    if (shundai_set.size() == 0)
    {
      shundai_set.push_back(0);
    }

    int res = INT_MAX;

    for (auto &&start_nut_i : shundai_set)
    {
      int total_dist = shundai_dist_v[start_nut_i];
      for (int i = 0; i < N; ++i)
      {
        if (i != start_nut_i)
        {
          total_dist += wanfan_dist_v[i];
        }
      }
      res = min(res, total_dist);
    }
    return res;
  }

  int cal_distance(vector<int> &start, vector<int> &stop)
  {
    return abs(start[0] - stop[0]) + abs(start[1] - stop[1]);
  }
};

int main()
{
  Solution s;
}

```



## 官方解题

```c++
class Solution {
    int getDistance(vector<int>& a, vector<int>& b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int ans = 1e9;
        int sum_dis = 0;
        for (auto nut = nuts.begin(); nut != nuts.end(); ++nut)
            sum_dis += getDistance(*nut, tree) * 2;
        for (auto first_nut = nuts.begin(); first_nut != nuts.end(); ++first_nut) {
            int cur = sum_dis - getDistance(*first_nut, tree) + getDistance(*first_nut, squirrel);
            ans = min(cur, ans);
        }
        return ans;
    }
};
```

