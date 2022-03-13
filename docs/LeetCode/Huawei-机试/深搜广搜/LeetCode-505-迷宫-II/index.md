# leetcode [505. 迷宫 II](https://leetcode-cn.com/problems/the-maze-ii/) 中等

一、思路非常简单：在每个位置尝试上下左右四个方向。如果当前位置四个方向都无法移动，则表示进入了死胡同。

二、对于这种类型的图的问题，它面临的一个典型的问题就是dead loop。

三、在dfs中，需要保持当前节点的状态不变，需要使用临时变量，它让我想到了状态转移方程。
## 第一次解题

```C++
#include <iostream>
#include <vector>
#include <climits> // INT_MAXÒ
using namespace std;

class Solution
{
  int minSteps_{INT_MAX}; // 最小步数
  int curSteps_{0};       // 当前所花费的步数
  int rowCount_{0};
  int colCount_{0};

public:
  int shortestDistance(vector<vector<int> > &maze, vector<int> &start, vector<int> &destination)
  {
    rowCount_ = maze.size();
    colCount_ = maze[0].size();
    dfs(maze, destination, start[0], start[1]);
    if (minSteps_ == INT_MAX)
    {
      return -1;
    }
    else
    {
      return minSteps_;
    }
  }
  void dfs(vector<vector<int> > &maze, vector<int> &destination, int curX, int curY)
  {
    cout << __PRETTY_FUNCTION__ << __FILE__ << __LINE__ << endl;
    cout << curX << "," << curY << endl;
    if (curX == destination[0] && curY == destination[1])
    {
      minSteps_ = min(curSteps_, minSteps_);
      return;
    }
    //向上
    if (curX > 0 && maze[curX - 1][curY] != 1)
    {
      while (maze[curX - 1][curY] != 1)
      {
        --curX;
        if (curX == 0)
          break;
      }
      ++curSteps_;
      dfs(maze, destination, curX, curY);
    }
    //向下
    if (curX < rowCount_ - 1 && maze[curX + 1][curY] != 1)
    {
      while (maze[curX + 1][curY] != 1)
      {
        ++curX;
        if (curX == rowCount_ - 1)
          break;
      }
      ++curSteps_;
      dfs(maze, destination, curX, curY);
    }
    //向左
    if (curY > 0 && maze[curX][curY - 1] != 1)
    {
      while (maze[curX][curY - 1] != 1)
      {
        --curY;
        if (curY == 0)
          break;
      }
      ++curSteps_;
      dfs(maze, destination, curX, curY);
    }
    //向右
    if (curY < colCount_ - 1 && maze[curX][curY + 1] != 1)
    {
      while (maze[curX][curY + 1] != 1)
      {
        ++curY;
        if (curX == colCount_ - 1)
          break;
      }
      ++curSteps_;
      dfs(maze, destination, curX, curY);
    }
    // 回溯
    --curSteps_;
  }
};

int main()
{
  vector<vector<int> > maze{{0, 0, 1, 0, 0},
                            {0, 0, 0, 0, 0},
                            {0, 0, 0, 1, 0},
                            {1, 1, 0, 1, 1},
                            {0, 0, 0, 0, 0}};
  vector<int> des{4, 4};
  vector<int> start{0, 4};
  Solution s;
  s.shortestDistance(maze, start, des);
}

```

上述程序非常简单，但是在运行的时候会因为dead loop而发生stackoverflow，下面是日志输出:

```
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc30
0,4
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc30
2,4
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc30
0,4
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc30
2,4
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc30
0,4
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc30
2,4
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc30
0,4
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc30
2,4
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc30
0,4
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc30
2,4
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc30
0,4
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc30
2,4
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc30
0,4
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc30
2,4
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc30
0,4

```

通过上述日志可知，小球一直是在上下移动，其实就是死循环。

思考：如何避免这种情况？

避免连续两次相反发现的移动。
## 第二次解题

```C++
#include <iostream>
#include <vector>
#include <climits> // INT_MAXÒ
using namespace std;

class Solution
{
  int minSteps_{INT_MAX}; // 最小步数
  int curSteps_{0};       // 当前所花费的步数
  int rowCount_{0};
  int colCount_{0};
  //上次移动的方向
  // 向上0
  // 向下1
  // 向左2
  // 向右3
  int lastDirection{-1};

public:
  int shortestDistance(vector<vector<int> > &maze, vector<int> &start, vector<int> &destination)
  {
    rowCount_ = maze.size();
    colCount_ = maze[0].size();
    dfs(maze, destination, start[0], start[1]);
    if (minSteps_ == INT_MAX)
    {
      return -1;
    }
    else
    {
      return minSteps_;
    }
  }
  void dfs(vector<vector<int> > &maze, vector<int> &destination, int curX, int curY)
  {
    cout << __PRETTY_FUNCTION__ << __FILE__ << __LINE__ << endl;
    cout << curX << "," << curY << endl;
    if (curX == destination[0] && curY == destination[1])
    {
      minSteps_ = min(curSteps_, minSteps_);
      return;
    }
    //向上
    if (curX > 0 && lastDirection != 1 && maze[curX - 1][curY] != 1)
    {
      lastDirection = 0;
      while (maze[curX - 1][curY] != 1)
      {
        --curX;
        if (curX == 0)
          break;
      }
      ++curSteps_;
      dfs(maze, destination, curX, curY);
    }
    //向下
    if (curX < rowCount_ - 1 && lastDirection != 0 && maze[curX + 1][curY] != 1)
    {
      lastDirection = 1;

      while (maze[curX + 1][curY] != 1)
      {
        ++curX;
        if (curX == rowCount_ - 1)
          break;
      }
      ++curSteps_;
      dfs(maze, destination, curX, curY);
    }
    //向左
    if (curY > 0 && lastDirection != 3 && maze[curX][curY - 1] != 1)
    {
      lastDirection = 2;

      while (maze[curX][curY - 1] != 1)
      {
        --curY;
        if (curY == 0)
          break;
      }
      ++curSteps_;
      dfs(maze, destination, curX, curY);
    }
    //向右
    if (curY < colCount_ - 1 && lastDirection != 2 && maze[curX][curY + 1] != 1)
    {
      lastDirection = 3;

      while (maze[curX][curY + 1] != 1)
      {
        ++curY;
        if (curX == colCount_ - 1)
          break;
      }
      ++curSteps_;
      dfs(maze, destination, curX, curY);
    }
    // 回溯
    --curSteps_;
  }
};

int main()
{
  vector<vector<int> > maze{{0, 0, 1, 0, 0},
                            {0, 0, 0, 0, 0},
                            {0, 0, 0, 1, 0},
                            {1, 1, 0, 1, 1},
                            {0, 0, 0, 0, 0}};
  vector<int> des{4, 4};
  vector<int> start{0, 4};
  Solution s;
  s.shortestDistance(maze, start, des);
}
```

输出如下：
```
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc36
0,4
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc36
2,4
```
这次走入了另外一个极端，通过输出可以看出，在加上防止走回路后，程序就会退出，和我预期的在每个节点都会尝试四个方向不符合。那为什么会这样呢？理论上来说应该会尝试四个方向的呀。原因在于我是就地修改了`curX`、`curY`，显然这种做法是不便于递归的，只要进入了死胡同，则程序就会退出递归，显然修改方式也是比较简单的，不修改`curX`、`curY`。





## 第三次解题

```c++
#include <iostream>
#include <vector>
#include <climits> // INT_MAXÒ
using namespace std;

class Solution
{
  int minSteps_{INT_MAX}; // 最小步数
  int curSteps_{0};       // 当前所花费的步数
  int rowCount_{0};
  int colCount_{0};
  //上次移动的方向
  // 向上0
  // 向下1
  // 向左2
  // 向右3
  int lastDirection{-1};

public:
  int shortestDistance(vector<vector<int> > &maze, vector<int> &start, vector<int> &destination)
  {
    rowCount_ = maze.size();
    colCount_ = maze[0].size();
    dfs(maze, destination, start[0], start[1]);
    if (minSteps_ == INT_MAX)
    {
      return -1;
    }
    else
    {
      return minSteps_;
    }
  }
  void dfs(vector<vector<int> > &maze, vector<int> &destination, int curX, int curY)
  {
    cout << __PRETTY_FUNCTION__ << __FILE__ << __LINE__ << endl;
    cout << curX << "," << curY << endl;
    if (curX == destination[0] && curY == destination[1])
    {
      minSteps_ = min(curSteps_, minSteps_);
      return;
    }
    //向上
    if (curX > 0 && lastDirection != 1 && maze[curX - 1][curY] != 1)
    {
      lastDirection = 0;
      int nextX = curX;
      while (maze[nextX - 1][curY] != 1)
      {
        --nextX;
        if (nextX == 0)
          break;
      }
      ++curSteps_;
      dfs(maze, destination, nextX, curY);
    }
    //向下
    if (curX < rowCount_ - 1 && lastDirection != 0 && maze[curX + 1][curY] != 1)
    {
      lastDirection = 1;
      int nextX = curX;
      while (maze[nextX + 1][curY] != 1)
      {
        ++nextX;
        if (nextX == rowCount_ - 1)
          break;
      }
      ++curSteps_;
      dfs(maze, destination, nextX, curY);
    }
    //向左
    if (curY > 0 && lastDirection != 3 && maze[curX][curY - 1] != 1)
    {
      lastDirection = 2;
      int nextY = curY;
      while (maze[curX][nextY - 1] != 1)
      {
        --nextY;
        if (nextY == 0)
          break;
      }
      ++curSteps_;
      dfs(maze, destination, curX, nextY);
    }
    //向右
    if (curY < colCount_ - 1 && lastDirection != 2 && maze[curX][curY + 1] != 1)
    {
      lastDirection = 3;
      int nextY = curY;

      while (maze[curX][nextY + 1] != 1)
      {
        ++nextY;
        if (nextY == colCount_ - 1)
          break;
      }
      ++curSteps_;
      dfs(maze, destination, curX, nextY);
    }
    // 回溯
    --curSteps_;
  }
};

int main()
{
  vector<vector<int> > maze{{0, 0, 1, 0, 0},
                            {0, 0, 0, 0, 0},
                            {0, 0, 0, 1, 0},
                            {1, 1, 0, 1, 1},
                            {0, 0, 0, 0, 0}};
  vector<int> des{4, 4};
  vector<int> start{0, 4};
  Solution s;
  s.shortestDistance(maze, start, des);
}
```
### 输出如下
```
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc36
0,4
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc36
2,4
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc36
0,3
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc36
1,3
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc36
1,0
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc36
0,0
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc36
0,1
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc36
2,1
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc36
2,0
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc36
0,0
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc36
0,1
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc36
2,1
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc36
2,0
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc36
0,0
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc36
0,1
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc36
2,1
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc36
2,0
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc36
0,0
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc36
0,1
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc36
2,1
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc36
2,0
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc36
0,0
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc36
0,1
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc36
2,1
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc36
2,0
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc36
0,0
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc36
0,1
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc36
2,1
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc36
2,0
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc36
0,0
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc36
0,1
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc36
2,1
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc36
2,0
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc36
0,0
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc36
0,1
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc36
2,1
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc36
2,0
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc36
0,0
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc36
0,1
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc36
2,1
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc36
2,0
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc36
0,0
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc36
0,1
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc36
2,1
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc36
2,0
void Solution::dfs(vector<vector<int>> &, vector<int> &, int, int)example.cc36
0,0
```

dead loop是由于兜圈子。

## 第四次解题
如果目的地之前去过，则标记一下，下次不再去了。

```c++

class Solution
{
  int minSteps_{INT_MAX}; // 最小步数
  int curSteps_{0};       // 当前所花费的步数
  int rowCount_{0};
  int colCount_{0};
  vector<vector<bool> > visited_;

public:
  int shortestDistance(vector<vector<int> > &maze, vector<int> &start, vector<int> &destination)
  {
    visited_ = vector<vector<bool> >(maze.size(), vector<bool>(maze[0].size(), false));
    rowCount_ = maze.size();
    colCount_ = maze[0].size();
    dfs(maze, destination, start[0], start[1]);
    if (minSteps_ == INT_MAX)
    {
      return -1;
    }
    else
    {
      return minSteps_;
    }
  }
  void dfs(vector<vector<int> > &maze, vector<int> &destination, int curX, int curY)
  {
    visited_[curX][curY] = true; // 标记当前位置已经访问了

    cout << __PRETTY_FUNCTION__ << __FILE__ << __LINE__ << endl;
    cout << curX << "," << curY << endl;
    if (curX == destination[0] && curY == destination[1])
    {
      minSteps_ = min(curSteps_, minSteps_);
      return;
    }
    //向上
    if (curX > 0 && maze[curX - 1][curY] != 1)
    {
      int nextX = curX;
      while (maze[nextX - 1][curY] != 1)
      {
        --nextX;
        if (nextX == 0)
          break;
      }
      if (visited_[nextX][curY])
      {
        // return;
      }
      else
      {
        ++curSteps_;
        dfs(maze, destination, nextX, curY);
      }
    }
    //向下
    if (curX < rowCount_ - 1 && maze[curX + 1][curY] != 1)
    {
      int nextX = curX;
      while (maze[nextX + 1][curY] != 1)
      {
        ++nextX;
        if (nextX == rowCount_ - 1)
          break;
      }
      if (visited_[nextX][curY])
      {
        // return;
      }
      else
      {
        ++curSteps_;
        dfs(maze, destination, nextX, curY);
      }
    }
    //向左
    if (curY > 0 && maze[curX][curY - 1] != 1)
    {
      int nextY = curY;
      while (maze[curX][nextY - 1] != 1)
      {
        --nextY;
        if (nextY == 0)
          break;
      }
      if (visited_[curX][nextY])
      {
        // return;
      }
      else
      {
        ++curSteps_;
        dfs(maze, destination, curX, nextY);
      }
    }
    //向右
    if (curY < colCount_ - 1 && maze[curX][curY + 1] != 1)
    {
      int nextY = curY;

      while (maze[curX][nextY + 1] != 1)
      {
        ++nextY;
        if (nextY == colCount_ - 1)
          break;
      }
      if (visited_[curX][nextY])
      {
        // return;
      }
      else
      {
        ++curSteps_;
        dfs(maze, destination, curX, nextY);
      }
    }
    // 回溯
    --curSteps_;
  }
};
```
## 第五次解题

```c++
#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <climits> // INT_MAXÒ
using namespace std;

class Solution
{
  int minSteps_{INT_MAX}; // 最小步数
  int curSteps_{0};       // 当前所花费的步数
  int rowCount_{0};
  int colCount_{0};
  vector<vector<bool> > visited_;

public:
  int shortestDistance(vector<vector<int> > &maze, vector<int> &start, vector<int> &destination)
  {
    visited_ = vector<vector<bool> >(maze.size(), vector<bool>(maze[0].size(), false));
    rowCount_ = maze.size();
    colCount_ = maze[0].size();
    dfs(maze, destination, start[0], start[1]);
    if (minSteps_ == INT_MAX)
    {
      return -1;
    }
    else
    {
      return minSteps_;
    }
  }
  void dfs(vector<vector<int> > &maze, vector<int> &destination, int curX, int curY)
  {
    visited_[curX][curY] = true; // 标记当前位置已经访问了

    cout << __PRETTY_FUNCTION__ << __FILE__ << __LINE__ << endl;
    cout << curX << "," << curY << endl;
    if (curX == destination[0] && curY == destination[1])
    {
      minSteps_ = min(curSteps_, minSteps_);
      cout << "到达目的地" << endl;
      cout << "到达目的地,花费步数:" << minSteps_ << endl;
      return;
    }
    //向上
    if (curX > 0 && maze[curX - 1][curY] != 1)
    {
      int nextX = curX;
      while (maze[nextX - 1][curY] != 1)
      {
        --nextX;
        if (nextX == 0)
          break;
      }
      int step = abs(curX - nextX);
      if (!visited_[nextX][curY])
      {
        curSteps_ += step;
        dfs(maze, destination, nextX, curY);
        curSteps_ -= step;
      }
    }
    //向下
    if (curX < rowCount_ - 1 && maze[curX + 1][curY] != 1)
    {
      int nextX = curX;
      while (maze[nextX + 1][curY] != 1)
      {
        ++nextX;
        if (nextX == rowCount_ - 1)
          break;
      }
      int step = abs(curX - nextX);
      if (!visited_[nextX][curY])
      {
        curSteps_ += step;
        dfs(maze, destination, nextX, curY);
        curSteps_ -= step;
      }
    }
    //向左
    if (curY > 0 && maze[curX][curY - 1] != 1)
    {
      int nextY = curY;
      while (maze[curX][nextY - 1] != 1)
      {
        --nextY;
        if (nextY == 0)
          break;
      }
      int step = abs(curY - nextY);
      if (!visited_[curX][nextY])
      {
        curSteps_ += step;
        dfs(maze, destination, curX, nextY);
        curSteps_ -= step;
      }
    }
    //向右
    if (curY < colCount_ - 1 && maze[curX][curY + 1] != 1)
    {
      int nextY = curY;

      while (maze[curX][nextY + 1] != 1)
      {
        ++nextY;
        if (nextY == colCount_ - 1)
          break;
      }
      int step = abs(curY - nextY);
      if (!visited_[curX][nextY])
      {
        curSteps_ += step;
        dfs(maze, destination, curX, nextY);
        curSteps_ -= step;
      }
    }
    cout << "死胡同" << endl;
    cout << "死胡同,花费步数:" << curSteps_ << endl;
  }
};

int main()
{
  vector<vector<int> > maze{{0, 0, 1, 0, 0},
                            {0, 0, 0, 0, 0},
                            {0, 0, 0, 1, 0},
                            {1, 1, 0, 1, 1},
                            {0, 0, 0, 0, 0}};
  vector<int> des{4, 4};
  vector<int> start{0, 4};
  Solution s;
  cout << s.shortestDistance(maze, start, des) << endl;
}
```

这次掌握了回溯法：向下的时候加上，回溯的时候撤销，这就好比沿着树进行遍历。

## 第六次解题

```c++
#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <climits> // INT_MAXÒ
using namespace std;

class Solution
{
  int minSteps_{INT_MAX}; // 最小步数
  int curSteps_{0};       // 当前所花费的步数
  int rowCount_{0};
  int colCount_{0};
  vector<vector<bool> > visited_;

public:
  int shortestDistance(vector<vector<int> > &maze, vector<int> &start, vector<int> &destination)
  {
    visited_ = vector<vector<bool> >(maze.size(), vector<bool>(maze[0].size(), false));
    rowCount_ = maze.size();
    colCount_ = maze[0].size();
    dfs(maze, destination, start[0], start[1]);
    if (minSteps_ == INT_MAX)
    {
      return -1;
    }
    else
    {
      return minSteps_;
    }
  }
  void dfs(vector<vector<int> > &maze, vector<int> &destination, int curX, int curY)
  {

    cout << __PRETTY_FUNCTION__ << __FILE__ << __LINE__ << endl;
    cout << curX << "," << curY << endl;
    if (curX == destination[0] && curY == destination[1])
    {
      minSteps_ = min(curSteps_, minSteps_);
      cout << "到达目的地" << endl;
      cout << "到达目的地,花费步数:" << minSteps_ << endl;
      return;
    }
    //向上
    if (curX > 0 && maze[curX - 1][curY] != 1)
    {
      int nextX = curX;
      while (maze[nextX - 1][curY] != 1)
      {
        --nextX;
        if (nextX == 0)
          break;
      }
      int step = abs(curX - nextX);
      if (!visited_[nextX][curY])
      {
        visited_[curX][curY] = true; // 标记当前位置已经访问了
        curSteps_ += step;
        dfs(maze, destination, nextX, curY);
        visited_[curX][curY] = false;
        curSteps_ -= step;
      }
    }
    //向下
    if (curX < rowCount_ - 1 && maze[curX + 1][curY] != 1)
    {
      int nextX = curX;
      while (maze[nextX + 1][curY] != 1)
      {
        ++nextX;
        if (nextX == rowCount_ - 1)
          break;
      }
      int step = abs(curX - nextX);
      if (!visited_[nextX][curY])
      {
        visited_[curX][curY] = true; // 标记当前位置已经访问了
        curSteps_ += step;
        dfs(maze, destination, nextX, curY);
        visited_[curX][curY] = false;
        curSteps_ -= step;
      }
    }
    //向左
    if (curY > 0 && maze[curX][curY - 1] != 1)
    {
      int nextY = curY;
      while (maze[curX][nextY - 1] != 1)
      {
        --nextY;
        if (nextY == 0)
          break;
      }
      int step = abs(curY - nextY);
      if (!visited_[curX][nextY])
      {
        visited_[curX][curY] = true; // 标记当前位置已经访问了

        curSteps_ += step;
        dfs(maze, destination, curX, nextY);
        visited_[curX][curY] = false;
        curSteps_ -= step;
      }
    }
    //向右
    if (curY < colCount_ - 1 && maze[curX][curY + 1] != 1)
    {
      int nextY = curY;

      while (maze[curX][nextY + 1] != 1)
      {
        ++nextY;
        if (nextY == colCount_ - 1)
          break;
      }
      int step = abs(curY - nextY);
      if (!visited_[curX][nextY])
      {
        visited_[curX][curY] = true; // 标记当前位置已经访问了
        curSteps_ += step;
        dfs(maze, destination, curX, nextY);
        visited_[curX][curY] = false;
        curSteps_ -= step;
      }
    }
    cout << "死胡同" << endl;
    cout << "死胡同,花费步数:" << curSteps_ << endl;
  }
};

int main()
{
  vector<vector<int> > maze{{0, 0, 1, 0, 0},
                            {0, 0, 0, 0, 0},
                            {0, 0, 0, 1, 0},
                            {1, 1, 0, 1, 1},
                            {0, 0, 0, 0, 0}};
  vector<int> des{4, 4};
  vector<int> start{0, 4};
  Solution s;
  cout << s.shortestDistance(maze, start, des) << endl;
}
```
上述解法在如下用例中会超过时间限制：

https://leetcode-cn.com/submissions/detail/280379831/testcase/

## 第七次解题

```c++
#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <climits> // INT_MAXÒ
using namespace std;

class Solution
{
  int minSteps_{INT_MAX}; // 最小步数
  int curSteps_{0};       // 当前所花费的步数
  int rowCount_{0};
  int colCount_{0};
  vector<vector<int> > distance_; // 记录到当前节点的最短距离
  vector<vector<int> > fourDirections_{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
  int shortestDistance(vector<vector<int> > &maze, vector<int> &start, vector<int> &destination)
  {
    distance_ = vector<vector<int> >(maze.size(), vector<int>(maze[0].size(), INT_MAX));
    distance_[start[0]][start[1]] = 0;
    rowCount_ = maze.size();
    colCount_ = maze[0].size();
    dfs(maze, destination, start[0], start[1]);
    if (minSteps_ == INT_MAX)
    {
      return -1;
    }
    else
    {
      return minSteps_;
    }
  }
  void dfs(vector<vector<int> > &maze, vector<int> &destination, int curX, int curY)
  {
    if (curX == destination[0] && curY == destination[1])
    {
      minSteps_ = min(distance_[curX][curY], minSteps_);
      return;
    }
    for (auto &&direction : fourDirections_)
    {
      int x = curX + direction[0];
      int y = curY + direction[1];
      int step = 0;
      while (x >= 0 && y >= 0 && x < rowCount_ && y < colCount_ && maze[x][y] != 1)
      {
        ++step;
        x += direction[0];
        y += direction[1];
      }
      x -= direction[0];
      y -= direction[1];
      if (distance_[x][y] > distance_[curX][curY] + step) // 及时剪枝
      {
        distance_[x][y] = distance_[curX][curY] + step;
        dfs(maze, destination, x, y);
      }
    }
  }
};

int main()
{
  vector<vector<int> > maze{{0, 0, 1, 0, 0},
                            {0, 0, 0, 0, 0},
                            {0, 0, 0, 1, 0},
                            {1, 1, 0, 1, 1},
                            {0, 0, 0, 0, 0}};
  vector<int> des{4, 4};
  vector<int> start{0, 4};
  Solution s;
  cout << s.shortestDistance(maze, start, des) << endl;
}
```

它能够通过所有的测试用例，它是我参考[官方解题](https://leetcode-cn.com/problems/the-maze-ii/solution/mi-gong-ii-by-leetcode/)写的，上述写法相比于我的写法的优势在于它积极进行剪纸。

