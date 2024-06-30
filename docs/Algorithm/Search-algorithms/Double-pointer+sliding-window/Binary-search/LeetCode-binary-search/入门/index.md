# Binary search入门



## [LeetCode-34. Find First and Last Position of Element in Sorted Array](https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/)

LeetCode-剑指-Offer53-在排序数组中查找数字-I

### Python

```python
from typing import *

class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        return [self.left_bound(nums, target), self.right_bound(nums, target)]

    def left_bound(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1
        while l <= r:
            mid = l + (r - l) // 2
            if nums[mid] == target:
                r = mid - 1
            elif nums[mid] > target:
                r = mid - 1
            else:
                l = mid + 1
        if l < len(nums) and nums[l] == target:
            return l
        else:
            return -1

    def right_bound(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1
        while l <= r:
            mid = l + (r - l) // 2
            if nums[mid] == target:
                l = mid + 1
            elif nums[mid] > target:
                r = mid - 1
            else:
                l = mid + 1
        if r >= 0 and nums[r] == target:
            return r
        else:
            return -1


if __name__ == '__main__':
    pass

```



### C++

```C++
// C++ program to implement recursive Binary Search
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		return { leftBound(nums, target), rightBound(nums, target) };
	}
	int leftBound(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] == target) {
				right = mid - 1;
			}
			else if (nums[mid] > target) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		if (left < nums.size() && nums[left] == target) {
			return left;
		else {
			return -1;
		}
	}
	int rightBound(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] == target) {
				left = mid + 1;
			}
			else if (nums[mid] > target) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		if (right >= 0 && nums[right] == target) {
			return right;
		else {
			return -1;
		}
	}
};

int main(void)
{
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -Werror
```

## [LeetCode-35. 搜索插入位置-简单](https://leetcode.cn/problems/search-insert-position/) 

使用binary search left bound，这个程序所要的就是left的值。

### C++

```C++
// C++ program to implement recursive Binary Search
#include <vector>
using namespace std;
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] == target) {
				right = mid - 1;
			}
			else if (nums[mid] > target) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		return left;
	}
};

int main(void)
{
	
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -Werror
```



## [LeetCode-704. 二分查找-简单](https://leetcode.cn/problems/binary-search/) 



### C++

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



