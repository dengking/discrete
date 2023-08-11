# [LeetCode-1207. 独一无二的出现次数-简单](https://leetcode.cn/problems/unique-number-of-occurrences/)



## 我的解题

```c++
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> frequency;
        for (auto &&num : arr)
        {
            ++frequency[num];
        }
        unordered_set<int> s;
        for (auto &&[num, cnt] : frequency)
        {
            if (s.count(cnt))
            {
                return false;
            }
            s.insert(cnt);
        }
        return true;
    }
};

// Driver code
int main()
{
}

```

