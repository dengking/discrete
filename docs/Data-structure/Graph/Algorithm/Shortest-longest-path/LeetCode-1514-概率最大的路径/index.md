# [LeetCode-1514. 概率最大的路径](https://leetcode.cn/problems/path-with-maximum-probability/)



## 我的解题

一、这道题要求解的是最大值，因此需要使用max heap

```c++
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

struct State
{
    int id_{0};
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
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
    {
        std::unordered_map<int, std::unordered_map<int, double>> g;

        for (int i = 0; i < edges.size(); ++i)
        {
            auto start = edges[i][0];
            auto stop = edges[i][1];
            auto weight = succProb[i];
            g[start][stop] = weight;
            g[stop][start] = weight;
        }
        std::priority_queue<State> q;
        q.push(State(start, 1));

        std::vector<double> dp(n, std::numeric_limits<double>::min());
        dp[start] = 1;
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
                auto next_cost = s.cost_ * g[s.id_][next_id];

                if (next_cost > dp[next_id])
                {
                    dp[next_id] = next_cost;
                    q.push(State(next_id, next_cost));
                }
            }
        }
        return dp[end] == std::numeric_limits<double>::min() ? 0 : dp[end];
    }
};

int main()
{
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

