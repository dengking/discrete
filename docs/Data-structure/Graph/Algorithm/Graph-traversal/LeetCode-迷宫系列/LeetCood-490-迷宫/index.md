# LeetCode [490. 迷宫](https://leetcode.cn/problems/the-maze/) 中等



## 我的解题

一、如何模拟**移动**？

"one-by-one"，即一次移动一格，这可以以循环的方式来实现，当遇到墙（边界墙和内部墙）的时候就需要停止移动，因此实现的方式有两种:

1、在移到目的地之前先判断目的地是不是墙，如果是墙，则不移动，如果不是，则移动

2、当移到墙上后再回退一步 ，下面的代码使用的是这种方式

二、回溯如何避免死循环？

将**到达的节点**标记为visited，每次在移动之前先判断**到达的节点**是否已经访问过了，如果已经访问过了，那么就不需要再次重复访问。

那对源点这个特殊节点如何处理呢？首先第一次运行的时候，源点不是**到达节点**，因此需要对源点按照一个活节点进行处理。一个特殊的情况是: 以题目给出的**示例 1**来说，从**源点**向下移动后，由于无法上移动，因此到达的节点就是源点本身，按照算法的，它是会首先将到达的节点即源点标记为visited然后继续从该点出发。

**示例 1：**

![img](https://assets.leetcode.com/uploads/2021/03/31/maze1-1-grid.jpg)

### 第一次解题

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
  // 迷宫大小
  int m_{0};
  int n_{0};

  // 移动
  vector<vector<int>> moves_{
      {0, -1}, // 上
      {0, 1},  // 下
      {-1, 0}, //左
      {1, 0}   // 右
  };
  // 目标位置
  int des_x_{0};
  int des_y_{0};

  vector<vector<int>> visted_; // flag
public:
  bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination)
  {
    m_ = maze.size();
    n_ = maze[0].size();

    visted_ = vector<vector<int>>(m_, vector<int>(n_, false));
    //
    des_x_ = destination[0];
    des_y_ = destination[1];
    return dfs(maze, start[0], start[1]);
  }

  bool dfs(vector<vector<int>> &maze, int x, int y)
  {
    if (x == des_x_ && y == des_y_)
    {
      return true;
    }
    else
    {
      for (auto &&m : moves_)
      {
        // 到达的节点
        auto next_x = x;
        auto next_y = y;
        while (
            next_x >= 0 && next_x < m_ && //
            next_y >= 0 && next_y < n_ && //
            maze[next_x][next_y] != 1     // 注意: 必须要放到这里，不能够放到前面，否则有越界风险
        )
        {
          next_x += m[0];
          next_y += m[1];
        }
        // 必须要退回到正确位置
        next_x -= m[0];
        next_y -= m[1];
        if (!visted_[next_x][next_y]) // 剪枝
        {
          visted_[next_x][next_y] = true; // 将到达的节点进行标记
          dfs(maze, next_x, next_y);
          visted_[next_x][next_y] = false; // 回溯
        }
      }
      return false;
    }
  }
};

int main()
{
  Solution s;
}

```

上述程序会在如下用例超出时间限制：

https://leetcode.cn/submissions/detail/282258497/testcase/

### 第二次解题

由于是存在性问题，因此只要到达了目标，就可以直接提出递归了，所以改写为dfs  + return value的方式，这种方式的优势的能够及时地终止回溯，但是这种方式仍然会在如下用例超出时间限制：

https://leetcode.cn/submissions/detail/282258497/testcase/

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
  // 迷宫大小
  int m_{0};
  int n_{0};

  // 移动
  vector<vector<int>> moves_{
      {0, -1}, // 上
      {0, 1},  // 下
      {-1, 0}, //左
      {1, 0}   // 右
  };
  // 目标位置
  int des_x_{0};
  int des_y_{0};

  vector<vector<int>> visted_; // flag
public:
  bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination)
  {
    m_ = maze.size();
    n_ = maze[0].size();

    visted_ = vector<vector<int>>(m_, vector<int>(n_, false));
    //
    des_x_ = destination[0];
    des_y_ = destination[1];
    return dfs(maze, start[0], start[1]);
  }

  bool dfs(vector<vector<int>> &maze, int x, int y)
  {
    if (x == des_x_ && y == des_y_)
    {
      return true;
    }
    else
    {
      for (auto &&m : moves_)
      {
        // 到达的节点
        auto next_x = x;
        auto next_y = y;
        while (
            next_x >= 0 && next_x < m_ && //
            next_y >= 0 && next_y < n_ && //
            maze[next_x][next_y] != 1     // 注意: 必须要放到这里，不能够放到前面，否则有越界风险
        )
        {
          next_x += m[0];
          next_y += m[1];
        }
        // 必须要退回到正确位置
        next_x -= m[0];
        next_y -= m[1];
        if (!visted_[next_x][next_y]) // 剪枝
        {
          visted_[next_x][next_y] = true; // 将到达的节点进行标记
          if (dfs(maze, next_x, next_y))
          {
            return true;
          }
          visted_[next_x][next_y] = false; // 回溯
        }
      }
      return false;
    }
  }
};


int main()
{
  Solution s;
}

```

### 第三次解题



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
  // 迷宫大小
  int m_{0};
  int n_{0};

  // 移动
  vector<vector<int>> moves_{
      {0, -1}, // 上
      {0, 1},  // 下
      {-1, 0}, //左
      {1, 0}   // 右
  };
  // 目标位置
  int des_x_{0};
  int des_y_{0};

  vector<vector<int>> visted_; // flag
public:
  bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination)
  {
    m_ = maze.size();
    n_ = maze[0].size();

    visted_ = vector<vector<int>>(m_, vector<int>(n_, false));
    //
    des_x_ = destination[0];
    des_y_ = destination[1];
    return dfs(maze, start[0], start[1]);
  }

  bool dfs(vector<vector<int>> &maze, int x, int y)
  {
    if (x == des_x_ && y == des_y_)
    {
      return true;
    }
    else
    {
      for (auto &&m : moves_)
      {
        // 到达的节点
        auto next_x = x;
        auto next_y = y;
        while (
            next_x >= 0 && next_x < m_ && //
            next_y >= 0 && next_y < n_ && //
            maze[next_x][next_y] != 1     // 注意: 必须要放到这里，不能够放到前面，否则有越界风险
        )
        {
          next_x += m[0];
          next_y += m[1];
        }
        // 必须要退回到正确位置
        next_x -= m[0];
        next_y -= m[1];
        if (!visted_[next_x][next_y]) // 剪枝
        {
          visted_[next_x][next_y] = true; // 将到达的节点进行标记
          if (dfs(maze, next_x, next_y))
          {
            return true;
          }
          // 不回溯的原因是: 如果执行到这里，说明dfs的返回值是false，说明[next_x][next_y]这个点是无法到达目标节点的，那么就可以直接将[next_x][next_y]标记为死节点
          // visted_[next_x][next_y] = false; // 回溯
        }
      }
      return false;
    }
  }
};

int main()
{
  Solution s;
}

```

上述解法相比于第二次解题而言，修改如下：

```c++
// visited_[next_x][next_y] = false;
```

即它取消了回溯，那这样做正确吗？

这是我看[Hanxin](https://leetcode.cn/u/code_learner/) [c++/python3 法1：BFS 法2：回溯 法3：DFS](https://leetcode.cn/problems/the-maze/solution/c-python3-fa-1bfs-fa-2hui-su-fa-3dfs-by-ibtg5/) 时，其中介绍的写法：

> 这个题只用一个visited数组，还不回溯，只dfs
> 从这个点作为起点，已经搜索过了，是不行的。其他的路径到了这里，再从这里出发二次，是没有意义的。无畏的循环。
>