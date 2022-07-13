# [LeetCode-797-所有可能的路径](https://leetcode.cn/problems/all-paths-from-source-to-target/)

是在阅读labuladong [图论算法基础（修订版）](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247494624&idx=1&sn=29b84ce2a1ba8115922179e207281e27&scene=21#wechat_redirect) 时发现的。

## 我的解题

它的stop condition是遇到了目标节点。

它需要保存path。

由于是无环的，因此它不需要visited array。

```c++
// #include <bits/ne_stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <cmath>
#include <numeric>
#include <climits>
#include <random>
#include <memory>

using namespace std;

class Solution
{
  vector<int> path_;
  vector<vector<int>> res_;

public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
  {
    dfs(0, graph);
    return res_;
  }
  void dfs(int node, vector<vector<int>> &graph)
  {
    if (node == graph.size() - 1)
    {
      path_.push_back(node);
      res_.push_back(path_);
      path_.pop_back();
    }
    else
    {
      path_.push_back(node);
      for (auto &&next : graph[node])
      {
        dfs(next, graph);
      }
      path_.pop_back();
    }
  }
};

int main()
{
}
// g++ test.cpp --ne_std=c++11 -pedantic -Wall -Wextra

```

