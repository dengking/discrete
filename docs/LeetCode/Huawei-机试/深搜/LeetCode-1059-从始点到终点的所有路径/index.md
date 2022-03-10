# [1059. 从始点到终点的所有路径](https://leetcode-cn.com/problems/all-paths-from-source-lead-to-destination/)

## 我的解题

思路：验证从起点出发的每一条路径，核实它能否到达终点。需要处理环问题。



如何来表示最终结果？

### 第一次解题

```C++
#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <climits> // INT_MAXÒ
using namespace std;

class Solution
{
  unordered_map<int, vector<int> > graph_;
  bool res_{true};
  vector<bool> visited_;
  int countReach_{0}; //到达终点的次数
public:
  bool leadsToDestination(int n, vector<vector<int> > &edges, int source, int destination)
  {
    for (auto &&e : edges)
    {
      graph_[e[0]].push_back(e[1]);
    }
    visited_ = vector<bool>(n, false);
    visited_[source] = true;
    dfs(source, destination);
    return graph_[source].size() == countReach_;
  }
  void dfs(int source, int destination)
  {
    if (source == destination)
    {
      ++countReach_;
      return;
    }
    for (auto &&n : graph_[source])
    {
      if (!visited_[n])
      {
        visited_[n] = true;
        dfs(n, destination);
        visited_[n] = false;
      }
    }
  }
};
int main()
{
  Solution s;
}
```

上述算法在如下用例无法通过:

```c++
输入：
3
[[0,1],[1,1],[1,2]]
0
2
输出：
true
预期结果：
false
```

显然，只要有环，就false；

### 第二次解题

修改为，

```c++
#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <climits> // INT_MAXÒ
using namespace std;

class Solution
{
  unordered_map<int, vector<int> > graph_;
  bool hasCircle{false};
  vector<bool> visited_;
  int countReach_{0}; //到达终点的次数
public:
  bool leadsToDestination(int n, vector<vector<int> > &edges, int source, int destination)
  {
    for (auto &&e : edges)
    {
      graph_[e[0]].push_back(e[1]);
    }
    visited_ = vector<bool>(n, false);
    visited_[source] = true;
    dfs(source, destination);
    return hasCircle ? false : graph_[source].size() == countReach_;
  }
  void dfs(int source, int destination)
  {
    if (source == destination)
    {
      ++countReach_;
      return;
    }
    for (auto &&n : graph_[source])
    {

      if (!visited_[n])
      {
        visited_[n] = true;
        dfs(n, destination);
        visited_[n] = false;
      }
      else
      {
        hasCircle = true;
        return;
      }
    }
  }
};
int main()
{
  Solution s;
}
```

上述算法在如下用例无法通过:

```c++
输入：
2
[[0,1],[1,1]]
0
1
输出：
true
预期结果：
false
```

### 第三次解题

```c++
#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <climits> // INT_MAXÒ
using namespace std;

class Solution
{
  unordered_map<int, vector<int> > graph_;
  bool hasCircle{false};
  vector<bool> visited_;
  int countReach_{0}; //到达终点的次数
public:
  bool leadsToDestination(int n, vector<vector<int> > &edges, int source, int destination)
  {
    for (auto &&e : edges)
    {
      if (e[0] == e[1]) // 成环则章节判定为false
        return false;
      graph_[e[0]].push_back(e[1]);
    }
    visited_ = vector<bool>(n, false);
    visited_[source] = true;
    dfs(source, destination);
    if (hasCircle)
    {
      return false;
    }
    else if (graph_[source].size())
    {
      return graph_[source].size() <= countReach_;
    }
    else
    {
      return false;
    }
  }
  void dfs(int source, int destination)
  {
    if (source == destination)
    {

      ++countReach_;
      return;
    }
    for (auto &&n : graph_[source])
    {
      if (!visited_[n])
      {
        visited_[n] = true;
        dfs(n, destination);
        visited_[n] = false;
      }
      else
      {
        hasCircle = true;
        return;
      }
    }
  }
};

int main()
{
  Solution s;
}
```



上述算法在下面用例无法通过：

```
输入：
7
[[0,1],[0,2],[1,3],[2,4],[3,5],[4,5],[2,6]]
0
5
输出：
true
预期结果：
false
```



## 更优秀的解法

### [c++/python3 回溯+记忆化 判断图中有没有环 判断叶节点](https://leetcode-cn.com/problems/all-paths-from-source-lead-to-destination/solution/cpython3-hui-su-ji-yi-hua-pan-duan-tu-zh-qmqx/)