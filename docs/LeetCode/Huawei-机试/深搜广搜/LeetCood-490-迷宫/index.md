# [490. 迷宫](https://leetcode-cn.com/problems/the-maze/) 中等



## 我的解题

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
  vector<vector<int> > moves_{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  int col_{0};
  int row_{0};
  bool res_{false};
  vector<vector<int> > visited_;

public:
  bool hasPath(vector<vector<int> > &maze, vector<int> &start, vector<int> &destination)
  {
    row_ = maze.size();
    col_ = maze[0].size();
    visited_ = vector<vector<int> >(row_, vector<int>(col_, false));
    dfs(maze, destination, start[0], start[1]);
    return res_;
  }
  void dfs(vector<vector<int> > &maze, vector<int> &destination, int x, int y)
  {
    if (x == destination[0] && y == destination[1])
    {
      res_ = true;
      return;
    }
    for (auto &&m : moves_)
    {
      int next_x = x + m[0];
      int next_y = y + m[1];
      while (next_x >= 0 && next_x < row_ &&
             next_y >= 0 && next_y < col_ &&
             maze[next_x][next_y] != 1)
      {
        next_x += m[0];
        next_y += m[1];
      }
      next_x -= m[0];
      next_y -= m[1];
      if (!visited_[next_x][next_y]) // 剪枝
      {
        visited_[next_x][next_y] = true;
        dfs(maze, destination, next_x, next_y);
        visited_[next_x][next_y] = false;
      }
    }
  }
};

int main()
{
  Solution s;
}

```

上述程序会在如下用例超出时间限制：

https://leetcode-cn.com/submissions/detail/282258497/testcase/

### 第二次解题

由于是存在性问题，因此只要到达了目标，就可以直接提出递归了，所以改写为dfs  + return value的方式，这种方式的优势的能够及时地终止回溯

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
  vector<vector<int> > moves_{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  int col_{0};
  int row_{0};
  bool res_{false};
  vector<vector<int> > visited_;

public:
  bool hasPath(vector<vector<int> > &maze, vector<int> &start, vector<int> &destination)
  {
    row_ = maze.size();
    col_ = maze[0].size();
    visited_ = vector<vector<int> >(row_, vector<int>(col_, false));
    dfs(maze, destination, start[0], start[1]);
    return res_;
  }
  bool dfs(vector<vector<int> > &maze, vector<int> &destination, int x, int y)
  {
    if (x == destination[0] && y == destination[1])
    {
      res_ = true;
      return true;
    }
    for (auto &&m : moves_)
    {
      int next_x = x + m[0];
      int next_y = y + m[1];
      while (next_x >= 0 && next_x < row_ &&
             next_y >= 0 && next_y < col_ &&
             maze[next_x][next_y] != 1)
      {
        next_x += m[0];
        next_y += m[1];
      }
      next_x -= m[0];
      next_y -= m[1];
      if (!visited_[next_x][next_y]) // 剪枝
      {
        visited_[next_x][next_y] = true;
        if (dfs(maze, destination, next_x, next_y))
        {
          return true;
        }
        visited_[next_x][next_y] = false;
      }
    }
    return false;
  }
};

int main()
{
  Solution s;
}

```

