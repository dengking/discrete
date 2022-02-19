# LeetCode [35. 搜索插入位置](https://leetcode-cn.com/problems/search-insert-position/) 简单

使用binary search left bound，这个程序所要的就是left的值，解法如下:

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



相关分析参见 **labuladong** [我作了首诗，保你闭着眼睛也能写对二分查找](https://mp.weixin.qq.com/s/M1KfTfNlu4OCK8i9PSAmug) 。