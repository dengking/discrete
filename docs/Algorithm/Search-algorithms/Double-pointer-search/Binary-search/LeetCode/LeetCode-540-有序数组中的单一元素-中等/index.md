# [LeetCode-540. 有序数组中的单一元素-中等](https://leetcode.cn/problems/single-element-in-a-sorted-array/) 



## 我的解题

假定target的下标为`x`，

在`x`的左边: 

1、如果y为偶数，a[y] == a[y+1]

2、如果y为奇数，a[y] == a[y-1]

在`x`的右边:

1、如果y为偶数，a[y] == a[y-1]

2、如果y为奇数，a[y] == a[y+1]

何时判断找到了目标呢？

二分查找来判断当前位于目标的左边还是右边。

```C++
#include <vector>
#include <iostream>
#include <exception>
using namespace std;

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums.front();
        }
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (mid == 0 || mid == nums.size() - 1)
            {
                return nums[mid];
            }

            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
            {
                return nums[mid];
            }
            else
            {
                if (mid % 2 == 0) // 偶数
                {
                    if (nums[mid] == nums[mid + 1]) // 位于target的左边
                    {
                        left = mid + 1;
                    }
                    else if (nums[mid] == nums[mid - 1]) // 位于target的右边
                    {
                        right = mid - 1;
                    }
                    else
                    {
                        throw std::runtime_error("未处理的情况");
                    }
                }
                else // 奇数
                {
                    if (nums[mid] == nums[mid + 1]) // 位于target的右边
                    {
                        right = mid - 1;
                    }
                    else if (nums[mid] == nums[mid - 1]) // 位于target的左边
                    {
                        left = mid + 1;
                    }
                    else
                    {
                        throw std::runtime_error("未处理的情况");
                    }
                }
            }
        }
        return -1;
    }
};

int main()
{

    Solution s;
    vector<int> nums{1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << s.singleNonDuplicate(nums) << endl;
    vector<int> nums1{3, 3, 7, 7, 10, 11, 11};
    cout << s.singleNonDuplicate(nums1) << endl;
    vector<int> nums2{1, 2, 2, 3, 3};
    cout << s.singleNonDuplicate(nums2) << endl;
    vector<int> nums3{2, 2, 3, 3, 1};
    cout << s.singleNonDuplicate(nums3) << endl;
}
```

