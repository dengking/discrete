# [LeetCode-1514. 概率最大的路径](https://leetcode.cn/problems/path-with-maximum-probability/)



## 我的解题

一、这道题要求解的是最大值，因此需要使用max heap

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

#include <iostream>
#include <string>
#include <unordered_map>
#include <array>
#include <vector>
#include <queue>
#include <algorithm>
#include <iterator>
#include <cstdlib>

using namespace std;

/**
 * @brief
 *
 */
struct State
{
  /**
   * @brief 节点ID
   *
   */
  int id_{0};
  /**
   * @brief 到达该节点的cost
   *
   */
  double cost_{0};
  State(int id, double cost) : id_{id}, cost_{cost}
  {
  }
  bool operator<(const State &right) const
  {
    return cost_ < right.cost_;
  }
};

class Solution
{
  std::priority_queue<State> q;
  std::vector<double> dp;
  std::unordered_map<int, std::unordered_map<int, double>> g;

public:
  double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
  {
    /**
     * @brief 构造出graph
     *
     */
    for (int i = 0; i < edges.size(); ++i)
    {
      auto start = edges[i][0];
      auto stop = edges[i][1];
      auto weight = succProb[i];
      g[start][stop] = weight;
      g[stop][start] = weight;
    }
    q.push(State(start, 1));

    dp = std::vector<double>(n, std::numeric_limits<double>::min());
    dp[start] = 1;
    //
    while (!q.empty())
    {
      auto s = q.top();
      q.pop();
      if (s.cost_ < dp[s.id_])
      {
        continue;
      }
      auto &adjacency = g[s.id_];
      for (auto &&[next_id, cost] : adjacency)
      {
        relax(s, next_id);
      }
    }
    return dp[end] == std::numeric_limits<double>::min() ? 0 : dp[end];
  }
  /**
   * @brief edge relaxation
   *
   */
  void relax(const State &src, int next_id)
  {
    auto next_cost = src.cost_ * g[src.id_][next_id];

    if (next_cost > dp[next_id])
    {
      dp[next_id] = next_cost;
      q.push(State(next_id, next_cost));
    }
  }
};

int main()
{
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

// g++ test.cpp --ne_std=c++11 -pedantic -Wall -Wextra

```

