# [LeetCode-18. 四数之和-中等](https://leetcode.cn/problems/4sum/)



## 我的解题

这是参考的 labuladong [一个函数秒杀 2Sum 3Sum 4Sum 问题](https://mp.weixin.qq.com/s/fSyJVvggxHq28a0SdmZm6Q) 写的: 

```c++
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void print(const vector<int> &nums)
{
    for (auto &&i : nums)
    {
        cout << i << endl;
    }
}

void print(const vector<vector<int>> &nums)
{
    for (auto &&n : nums)
    {
        print(n);
    }
}

/**
 * @brief 注意：调用这个函数之前一定要先给 nums 排序
 *
 * @param nums
 * @param n nsum的n
 * @param start nums的开始下标
 * @param target 目标值
 * @return vector<vector<int>>
 */
vector<vector<int>> nSumTarget(vector<int> &nums, int n, int start, long target)
{
    int sz = nums.size();
    if (n < 2 || n > sz)
    {
        return {};
    }
    vector<vector<int>> res;
    if (n == 2) // base case
    {
        int left = start, right = sz - 1;
        while (left < right)
        {
            int left_val = nums[left], right_val = nums[right];
            long sum = nums[left] + nums[right];
            if (sum < target)
            {
                while (left < right && nums[left] == left_val)
                {
                    ++left;
                }
            }
            else if (sum > target)
            {
                while (left < right && nums[right] == right_val)
                {
                    --right;
                }
            }
            else
            {
                res.push_back({left_val, right_val});
                while (left < right && nums[left] == left_val)
                {
                    ++left;
                }
                while (left < right && nums[right] == right_val)
                {
                    --right;
                }
            }
        }
    }
    else
    {
        for (int i = start; i < sz; ++i)
        {
            auto subs = nSumTarget(nums, n - 1, i + 1, target - nums[i]);
            for (auto &&sub : subs)
            {
                sub.push_back(nums[i]);
                res.push_back(sub);
            }
            while (i < sz - 1 && nums[i] == nums[i + 1])
            {
                ++i;
            }
        }
    }
    return res;
}

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        return nSumTarget(nums, 4, 0, target);
    }
};

int main()
{
    Solution s;

    vector<int> nums{-1, 0, 1, 2, -1, -4};
    print(s.fourSum(nums, 0));

    vector<int> nums1{0, 0, 0};
    print(s.fourSum(nums1, 0));

    vector<int> nums2{1, 2, -2, -1};
    print(s.fourSum(nums2, 0));
}

```

