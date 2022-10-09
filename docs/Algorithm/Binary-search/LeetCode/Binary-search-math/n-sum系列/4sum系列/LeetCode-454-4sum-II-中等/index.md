# [LeetCode-454. 四数相加 II](https://leetcode.cn/problems/4sum-ii/)



## 我的解题

这是典型的以空间换时间

```c++
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        unordered_map<int, int> counter12;
        for (auto &&n1 : nums1)
        {
            for (auto &&n2 : nums2)
            {
                ++counter12[n1 + n2];
            }
        }
        int res = 0;
        for (auto &&n3 : nums3)
        {
            for (auto &&n4 : nums4)
            {
                res += counter12[-n3 - n4];
            }
        }
        return res;
    }
};

int main()
{
    Solution s;

    vector<int> nums{-4, -1, 1, 2};
    int res = 0;
    cout << res << endl;
}

```

