# LeetCode [986. 区间列表的交集](https://leetcode-cn.com/problems/interval-list-intersections/) 中等



## 我的解题

是在阅读 emre [Coding Patterns: Merge Intervals](https://emre.me/coding-patterns/merge-intervals/) 时，发现的这个问题。

```c++
#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <iostream>
#include <variant>
using namespace std;

class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList)
    {
        vector<vector<int>> res;
        for (auto &&first : firstList)
        {
            for (auto &&second : secondList)
            {
                if (first[1] < second[0]) // 肯定没有交集
                {
                    break;
                }
                else
                {
                    auto intersection = getIntersection(first, second);
                    if (!intersection.empty())
                    {
                        res.push_back(intersection);
                    }
                }
            }
        }
        return res;
    }
    vector<int> getIntersection(vector<int> first, vector<int> &second)
    {
        int left = max(first[0], second[0]);
        int right = min(first[1], second[1]);
        if (left <= right)
        {
            return {left, right};
        }
        else
        {
            return {};
        }
    }
};
```

相比于官方解题而言