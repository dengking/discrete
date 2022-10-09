# [LeetCode-16. 最接近的三数之和-中等](https://leetcode.cn/problems/3sum-closest/)



## 我的解题



```c++
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class Solution
{

public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        return nSumTargetClosest(nums, 3, 0, target);
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
    int nSumTargetClosest(vector<int> &nums, int n, int start, long target)
    {
        int sz = nums.size();
        long sum = INT_MAX;

        if (n == 2) // base case
        {
            int left = start, right = sz - 1;
            while (left < right)
            {
                int left_val = nums[left], right_val = nums[right];
                sum = nums[left] + nums[right];
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
                else // sum == target
                {
                    break;
                }
            }
            return sum;
        }
        else
        {
            for (int i = start; i < sz; ++i)
            {
                int sub_sum = nSumTargetClosest(nums, n - 1, i + 1, target - nums[i]);
                long new_sum = sub_sum + nums[i];

                if (abs(new_sum - target) < abs(sum - target))
                {
                    sum = new_sum;
                }
            }
        }
        return sum;
    }
};

int main()
{
    Solution s;

    vector<int> nums{ -4,-1, 1, 2};
    int res = s.threeSumClosest(nums, 1);
    cout << res << endl;
}

```

