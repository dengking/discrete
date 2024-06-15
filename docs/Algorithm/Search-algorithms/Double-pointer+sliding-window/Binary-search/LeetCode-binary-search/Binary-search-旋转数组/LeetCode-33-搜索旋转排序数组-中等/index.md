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



## 第二次解题

这是参考的 [官方解题](https://leetcode.cn/problems/search-in-rotated-sorted-array/solution/sou-suo-xuan-zhuan-pai-xu-shu-zu-by-leetcode-solut/) 写的，它的核心思想是: 将数组从中间(`mid`)分开成左右两部分的时候，一定有一部分的数组是有序的，通过比较target和端点的关系是可以判断出哪边是有序的。根据 `target` 和 有序部分端点值大小的关系，可以决定丢弃哪边。

```c++
#include <vector>
#include <iostream>
using namespace std;

class Solution
{

public:
    int search(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }

            if (nums[mid] >= nums.front()) // 左边是有序的
            {
                if (target < nums[mid]) // 0 是小于nums[3]的，按照这种错误的写法会认为target在左半段，但是实际上是在右半段
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else // 右边是有序的
            {
                if (target < nums[mid])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
        }
        return -1;
    }
};

int main()
{

    Solution s;
    vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    cout << s.search(nums, 0) << endl;
}
```



## 第三次解题



```c++
#include <vector>
#include <iostream>
using namespace std;

class Solution
{

public:
    int search(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }

            if (nums[mid] >= nums.front()) // 左边是单调递增的
            {
                if (nums.front() <= target && target < nums[mid])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else // 右边是单调递增的
            {
                if (nums[mid] < target && target <= nums.back())
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main()
{

    Solution s;
    vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    cout << s.search(nums, 0) << endl;
}
```

