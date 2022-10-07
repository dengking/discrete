# [LeetCode-704. 二分查找-简单](https://leetcode.cn/problems/binary-search/)





```c++
#include <vector>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        if (nums.empty())
            return -1;
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - mid) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] > target)
            {
                right = right - 1;
            }
            else
            {
                left = left + 1;
            }
        }
        return -1;
    }
};

int main()
{
}
```



