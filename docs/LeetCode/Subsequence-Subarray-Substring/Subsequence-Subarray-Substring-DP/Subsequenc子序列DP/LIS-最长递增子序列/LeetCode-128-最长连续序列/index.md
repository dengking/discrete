# [LeetCode-128. 最长连续序列-中等](https://leetcode.cn/problems/longest-consecutive-sequence/)



这是在阅读 robinliu gitbooks [Sweep Line (Intervals)](https://robinliu.gitbooks.io/leetcode/content/Sweep_Line.html) 时发现的。

## double pointer 从中间向两边扩散

这个写法是参考的  robinliu gitbooks [Sweep Line (Intervals)](https://robinliu.gitbooks.io/leetcode/content/Sweep_Line.html) 。

```c++
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> sets(nums.begin(), nums.end());
        int max_len = 0;

        for (auto n : nums)
        {
            if (sets.find(n) == sets.end())
                continue;
            int i = n - 1;
            int j = n + 1;

            while (sets.find(i) != sets.end())
                sets.erase(i--);
            while (sets.find(j) != sets.end())
                sets.erase(j++);
            int cur_len = j - i - 1;
            max_len = max(cur_len, max_len);
        }

        return max_len;
    }
};

int main()
{
}
```

