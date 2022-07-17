# [LeetCode-1631. 最小体力消耗路径](https://leetcode.cn/problems/path-with-minimum-effort/)



## 我的解题

这是在阅读 labuladong [我写了一个模板，把 Dijkstra 算法变成了默写题](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247492167&idx=1&sn=bc96c8f97252afdb3973c7d760edb9c0&scene=21#wechat_redirect)  时发现的，显然这道题是可以使用Dijkstra来进行解决的。



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
    int row_{0};
    int col_{0};
    int cost_{0};

    State(int row, int col, int cost) : row_(row), col_(col), cost_{cost}
    {
    }
};

class Solution
{
    std::vector<std::tuple<int, int>> moves_{
        {-1, 0}, // 上
        {1, 0},  // 下
        {0, -1}, // 左
        {0, 1},  // 右
    };

public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        static constexpr int INF = INT_MAX / 2;
        vector<vector<int>> dp(heights.size(), vector<int>(heights[0].size(), INF));
        dp[0][0] = 0;
        auto cmp = [](const State &left, const State &right)
        {
            return left.cost_ > right.cost_;
        };
        std::priority_queue<State, std::vector<State>, decltype(cmp)> q(cmp);
        q.push(State(0, 0, 0));
        while (!q.empty())
        {
            auto s = q.top();
            q.pop();
            if (s.cost_ > dp[s.row_][s.col_])
            {
                continue;
            }
            for (auto &&[row_move, col_move] : moves_)
            {
                auto next_row = s.row_ + row_move;
                auto next_col = s.col_ + col_move;
                if (next_row < 0 || next_row >= heights.size() || next_col < 0 || next_col >= heights.front().size()) // 校验下一个节点是否是合法的位置
                {
                    continue;
                }

                auto cost = abs(heights[next_row][next_col] - heights[s.row_][s.col_]);
                auto next_cost = max(cost, dp[s.row_][s.col_]); // 到达下一个节点的cost
                if (next_cost < dp[next_row][next_col])
                {
                    dp[next_row][next_col] = next_cost;
                    q.push(State(
                        next_row,
                        next_col,
                        next_cost));
                }
            }
        }
        return dp.back().back();
    }
};

int main()
{
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

一、一个节点有多重方式可以到达，这一点是和dijkstra一样的，并且由于有四个发现移动，因此第一次思考这个问题的时候，我担心可能是会出现饶了一圈有回到原点从而成环而导致dead loop当时我考虑使用visited set。实际上: 这个题是不需要visited array的，虽然一个节点是可以多次被访问的，但是我们要取多次的最小值，对于dijkstra算法，由于它的贪心选择特性，显然当一个节点绕过一周再次回到原处的时候，这条路径肯定不是更好的，所以此时它是不会有机会再次进入queue的，因此就不会出现成环的情况，所以就不需要visited array。
二、

```C++
            if (s.cost_ > dp[s.row_][s.col_])
            {
                continue;
            }
```
上述不能够包含等号，否则对于第一个`dp[0][0]`，它的cost也是0，那么如果带上等号，则会导致直接continue，从而使queue machine无法启动成功。



三、这道题使用到了C++17 structure binding的语法特性，其中使用了
```C++
std::vector<std::tuple<int, int>> moves_{
        {-1, 0}, // 上
        {1, 0},  // 下
        {0, -1}, // 左
        {0, 1},  // 右
    };
		
for (auto &&[row_move, col_move] : moves_)
```