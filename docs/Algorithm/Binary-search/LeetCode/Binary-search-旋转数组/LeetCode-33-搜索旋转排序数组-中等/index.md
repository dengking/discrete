# [LeetCode-33. 搜索旋转排序数组-中等](https://leetcode.cn/problems/search-in-rotated-sorted-array/)



## 第一次解题



```c++
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
    enum Pos
    {
        Front,
        Back
    };

public:
    int
    search(vector<int> &nums, int target)
    {
        if (nums.empty())
            return -1;
        Pos pos;
        if (target >= nums.front()) // target位于前半段
        {
            pos = Pos::Front;
        }
        else if (target <= nums.back()) // target位于后半段
        {
            pos = Pos::Back;
        }
        else
        {
            return -1;
        }
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] > target)
            {
                if (nums[mid] > nums.back()) // mid位于前半段
                {
                    if (pos == Pos::Front) // target 和 mid 都位于前半段
                    {
                        right = mid - 1;
                    }
                    else // target位于后半段，mid位于前半段
                    {
                        left = mid + 1;
                    }
                }
                else // mid位于后半段
                {
                    if (pos == Pos::Front) // target位于前半段，mid位于后半段
                    {
                        return -1;
                    }
                    else // target 和 mid 都位于后半段
                    {
                        right = mid - 1;
                    }
                }
            }
            else // nums[mid] < target
            {
                if (nums[mid] > nums.back()) // mid位于前半段
                {
                    if (pos == Pos::Front) // target 和 mid 都位于前半段
                    {
                        left = mid + 1;
                    }
                    else // target位于后半段，mid位于前半段
                    {
                        return -1;
                    }
                }
                else // mid位于后半段
                {
                    if (pos == Pos::Front) // target位于前半段，mid位于后半段
                    {
                        right = mid - 1;
                    }
                    else // target 和 mid 都位于后半段
                    {
                        left = mid + 1;
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
    vector<int> nums{1, 3};
    cout << s.search(nums, 3) << endl;
}
```



### 无法通过的用例

输入：

```c++
[1,3] 
3
```



输出：

```c++
-1
```



预期结果：

```c++
1
```

