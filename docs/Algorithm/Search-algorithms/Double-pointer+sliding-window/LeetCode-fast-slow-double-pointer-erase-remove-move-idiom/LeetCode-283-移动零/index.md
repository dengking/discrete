# [LeetCode-283. 移动零](https://leetcode.cn/problems/move-zeroes/)

一次遍历:

这里参考了**快速排序**的思想，**快速排序**首先要确定一个待分割的元素做中间点 x(pivot)，然后把所有小于等于 x 的元素放到 x 的左边，大于 x 的元素放到其右边。这里我们可以用 0 当做这个中间点，把不等于 0(注意题目没说不能有负数)的放到中间点的左边，等于 0 的放到其右边。这的中间点就是 0 本身，所以实现起来比快速排序简单很多，我们使用两个指针 i 和 j，只要 `nums[i]!=0`，我们就交换 `nums[i]` 和 `nums[j]`，请对照动态图来理解：



## C++



```C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	void moveZeroes(vector<int> &nums)
	{
		int n = nums.size(), left = 0, right = 0;
		while (right < n)
		{
			if (nums[right])
			{
				swap(nums[left], nums[right]);
				left++;
			}
			right++;
		}
	}
};

template<typename ...Args>
ostream& operator <<(ostream &stream, vector<Args...> &v)
{
	for (auto &&i : v)
	{
		stream << i << " ";
	}
	return stream;
}
int main()
{
	vector<int> nums { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };

	Solution s;
	s.moveZeroes(nums);

	cout << nums << endl;
}
// g++ test.cpp -pedantic -Wall -Wextra --std=c++11

```



## Python

```c++
from typing import *


class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        slow = 0
        for fast in range(len(nums)):
            num = nums[fast]
            if num != 0:
                nums[slow], nums[fast] = nums[fast], nums[slow]
                slow += 1

```

