# [LeetCode-1854. 人口最多的年份-简单](https://leetcode.cn/problems/maximum-population-year/)





## 我的解题

"注意，人不应当计入他们死亡当年的人口中" 说明要在死亡的年份将它给扣除掉。

```c++
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maximumPopulation(vector<vector<int>> &logs)
    {
        vector<pair<int, int>> events;
        for (auto &&log : logs)
        {
            events.emplace_back(log[0], 1);
            events.emplace_back(log[1], -1);
        }
        sort(events.begin(), events.end());
        int cnt = 0;
        int max_cnt = 0;
        int max_year = 0;
        for (auto &&event : events)
        {
            cnt += event.second;
            if (cnt > max_cnt)
            {
                max_cnt = cnt;
                max_year = event.first;
            }
        }
        return max_year;
    }
};

int main()
{
}
```

