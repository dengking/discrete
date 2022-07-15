# LeetCode [34. 在排序数组中查找元素的第一个和最后一个位置](https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/) 中等

## 我的解题

```C++
// C++ program to implement recursive Binary Search
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int left = leftBound(nums, target);
		int right = rightBound(nums, target);
		return { left, right };
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
		if (left >= nums.size()) {
			return -1;
		}
		else if (nums[left] != target) {
			return -1;
		}
		else {
			return left;
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
		if (right < 0) {
			return -1;
		}
		else if (nums[right] != target) {
			return -1;
		}
		else {
			return right;
		}
	}
};

int main(void)
{

}

// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -Werror

```

