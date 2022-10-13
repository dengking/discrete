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



## [江不知](https://leetcode.cn/u/jalan/) # [【动态规划】Python 题解](https://leetcode.cn/problems/longest-consecutive-sequence/solution/dong-tai-gui-hua-python-ti-jie-by-jalan/)

题目要求 $O(n)$ 复杂度。

一、用哈希表存储每个端点值对应连续区间的长度

二、若数已在哈希表中：跳过不做处理

三、若是新数加入：

1、取出其左右相邻数已有的连续区间长度 `left` 和 `right`

2、算当前数的区间长度为：`cur_length = left + right + 1`

3、根据 `cur_length` 更新最大长度 `max_length` 的值

4、更新区间两端点的长度值



```c++
class Solution(object):
    def longestConsecutive(self, nums):
        hash_dict = dict()
        
        max_length = 0
        for num in nums:
            if num not in hash_dict:
                left = hash_dict.get(num - 1, 0)
                right = hash_dict.get(num + 1, 0)
                
                cur_length = 1 + left + right
                if cur_length > max_length:
                    max_length = cur_length
                
                hash_dict[num] = cur_length
                hash_dict[num - left] = cur_length
                hash_dict[num + right] = cur_length
                
        return max_length

```

