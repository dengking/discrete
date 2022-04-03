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

相比于官方解题而言，我的解法非常暴力，更好的解法是使用"merge-append-double-pointer-first-second"。

## [区间列表的交集 # 官方解题](https://leetcode-cn.com/problems/interval-list-intersections/solution/qu-jian-lie-biao-de-jiao-ji-by-leetcode/)

> NOTE: 
>
> 两个区间相交后，显然其中终点跟小的就可以删除掉了，因为它已经被吃下了。

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
        int first = 0, second = 0;
        while (first < firstList.size() && second < secondList.size())
        {
            int left = max(firstList[first][0], secondList[second][0]);
            int right = min(firstList[first][1], secondList[second][1]);
            if (left <= right)
                res.push_back({left, right});
            if (firstList[first][1] < secondList[second][1])
            {
                ++first;
            }
            else
            {
                ++second;
            }
        }
        return res;
    }
};
```

> NOTE:
>
> 它的复杂度更低，因为我的解法中会不断地和已经相交过的再次求解交集，而这部分显然是没有交集的