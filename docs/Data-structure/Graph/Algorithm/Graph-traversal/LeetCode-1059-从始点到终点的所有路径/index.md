# [1059. 从始点到终点的所有路径](https://leetcode-cn.com/problems/all-paths-from-source-lead-to-destination/)

## 我的解题

思路：验证从起点出发的每一条路径，核实它能否到达终点。需要处理环问题。

如何来表示最终结果？

这是典型的存在性问题，只要发现有一条不能到达终点，则立即判定为false。这种题目是比较

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

`[2,6]` 这条边显然是无法到达目标节点的。

### 第四次解题

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
  unordered_map<int, vector<int> > graph_;
  bool hasCircle{false};
  vector<bool> visited_;
  int countReach_{0}; //到达终点的次数
public:
  bool leadsToDestination(int n, vector<vector<int> > &edges, int source, int destination)
  {
    for (auto &&e : edges)
    {
      if (e[0] == e[1])
        return false;
      graph_[e[0]].push_back(e[1]);
    }
    if (graph_.count(destination) > 0) //终点还有后继结点，必不行
      return false;
    visited_ = vector<bool>(n, false);
    visited_[source] = true;
    return dfs(source, destination);
  }
  bool dfs(int source, int destination)
  {
    if (source == destination)
    {
      return true;
    }
    if (!graph_.count(source))
    {
      return false;
    }
    for (auto &&n : graph_[source])
    {
      if (!visited_[n])
      {
        visited_[n] = true;
        if (dfs(n, destination))
        {
          visited_[n] = false;
          continue;
        }
        else
        {
          return false;
        }
      }
      else
      {
        return false;
      }
    }
    return true; // 这里是需要注意的
  }
};

int main()
{
  Solution s;
}

```

上述程序在如下用例无法通过：

```
50
[[5,15],[38,34],[29,5],[6,32],[46,2],[34,22],[2,25],[1,18],[10,10],[26,46],[40,46],[36,19],[16,13],[46,6],[19,32],[7,41],[14,32],[20,13],[0,43],[17,14],[42,41],[40,12],[28,7],[36,35],[18,2],[28,11],[14,32],[4,9],[26,6],[7,17],[49,41],[17,2],[36,34],[18,0],[26,15],[27,10],[26,46],[41,14],[47,19],[19,14],[6,3],[16,14],[21,43],[4,15],[5,2],[31,2],[5,30],[7,33],[18,2],[9,33],[21,44],[1,43],[37,17],[8,24],[21,33],[46,45],[29,14],[22,32],[14,14],[22,32],[42,6],[7,14],[35,13],[36,35],[5,25],[2,3],[23,22],[44,33],[24,13],[35,19],[20,14],[14,32],[35,5],[44,13],[32,32],[32,32],[28,46],[32,32],[37,10],[38,46],[30,30],[0,3],[15,9],[39,15],[42,44],[2,20],[47,0],[49,44],[45,4],[36,22],[13,13],[14,30],[13,14],[31,31],[45,3],[45,5],[34,14],[44,9],[30,30],[40,12],[13,30],[25,20],[34,14],[41,22],[12,34],[5,33],[20,22],[48,5],[48,7],[46,0],[14,32],[32,30],[38,46],[30,30],[35,15],[37,20],[42,2],[26,13],[8,48],[20,30],[37,33],[28,18],[32,30],[10,10],[48,44],[24,14],[8,9],[0,14],[1,43],[14,14],[20,22],[31,10],[1,0],[4,7],[27,41],[41,22],[0,22],[17,19],[8,16],[18,38],[37,23],[5,22],[35,23],[14,30],[30,30],[13,32],[28,23],[24,25],[45,2],[25,22]]
15
33
```

经过调试发现，它是在如下语句退出的：

```c++
      if (e[0] == e[1])
        return false;
```

查看测试用例，的确存在 `[14,14]` 这样的数据。将上面这条语句删除，即可通过。

### 第五次提交

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
    if (graph_.count(destination) > 0) //终点还有后继结点，必不行
      return false;
    visited_ = vector<bool>(n, false);
    visited_[source] = true;
    return dfs(source, destination);
  }
  bool dfs(int source, int destination)
  {
    if (source == destination)
    {
      return true;
    }
    if (!graph_.count(source))
    {
      return false;
    }
    for (auto &&n : graph_[source])
    {
      if (!visited_[n])
      {
        visited_[n] = true;
        if (dfs(n, destination))
        {
          visited_[n] = false;
          continue;
        }
        else
        {
          return false;
        }
      }
      else
      {
        return false;
      }
    }
    return true; // 这里是需要注意的
  }
};

int main()
{
  Solution s;
}

```



## 更优秀的解法

### [c++/python3 回溯+记忆化 判断图中有没有环 判断叶节点](https://leetcode-cn.com/problems/all-paths-from-source-lead-to-destination/solution/cpython3-hui-su-ji-yi-hua-pan-duan-tu-zh-qmqx/)

```c++
class Solution 
{
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        unordered_map<int, vector<int>> adjvex; //邻接表
        for (auto & v: edges)
            adjvex[v[0]].push_back(v[1]);
        if (adjvex.count(destination) > 0)  //终点还有后继结点，必不行
            return false;
        vector<bool> visited(n, false);     //记忆化

        std::function<bool (int)> backtrace = [&] (int x)
        {
            if (adjvex.count(x) == 0)       //是叶节点
                return x == destination;
            for (int & y: adjvex[x])
            {
                if (visited[y] == true)     //之前已经visit了，有环
                    return false;
                visited[y] = true;          //借
                if (backtrace(y) == false)
                    return false;
                visited[y] = false;         //回溯。有借有还
            }
            return true;
        };

        visited[source] = true;             //从source出发
        return backtrace(source);
    }
};

```



## 拓扑排序

### [灵剑2012](https://leetcode-cn.com/u/ling-jian-2012/) [标准的拓扑排序应用](https://leetcode-cn.com/problems/all-paths-from-source-lead-to-destination/solution/biao-zhun-de-tuo-bu-pai-xu-ying-yong-by-jy6wb/)



### [梦璃夜·天星![img](https://assets.leetcode-cn.com/contest/level/Guardian_sm.png)](https://leetcode-cn.com/u/muriyatensei/) [【C++】普通拓扑排序](https://leetcode-cn.com/problems/all-paths-from-source-lead-to-destination/solution/c-pu-tong-tuo-bu-pai-xu-by-muriyatensei-zo9z/)

从结尾向起点找，能到起点就证明可以

> NOTE:
>
> 从下面的实现来看，它将图反过来了

```c++
class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int so, int de) {
        vector<vector<int>> e(n);
        vector<int> d(n);
        for(auto&& x: edges){
            e[x[1]].push_back(x[0]);
            d[x[0]]++;
        }        
        if(d[de]) return false; // 目标节点有入度，说明它后面有节点
        queue<int> q;
        q.push(de);
        while(q.size()){
            int now = q.front(); q.pop();
            if(now == so) return true;
            for(int next: e[now]){
                if(--d[next] == 0){
                    q.push(next);
                }
            }
        }
        return false;
    }
};

```

