# [LeetCode-283. 移动零](https://leetcode.cn/problems/move-zeroes/)

## [王尼玛](https://leetcode.cn/u/wang_ni_ma/) # [动画演示 283.移动零](https://leetcode.cn/problems/move-zeroes/solutions/90229/dong-hua-yan-shi-283yi-dong-ling-by-wang_ni_ma/) 

一次遍历:

这里参考了**快速排序**的思想，**快速排序**首先要确定一个待分割的元素做中间点 x(pivot)，然后把所有小于等于 x 的元素放到 x 的左边，大于 x 的元素放到其右边。这里我们可以用 0 当做这个中间点，把不等于 0(注意题目没说不能有负数)的放到中间点的左边，等于 0 的放到其右边。这的中间点就是 0 本身，所以实现起来比快速排序简单很多，我们使用两个指针 i 和 j，只要 `nums[i]!=0`，我们就交换 `nums[i]` 和 `nums[j]`，请对照动态图来理解：

我的理解:

这道题本质上是要将array划分为两个部分，显然，只要知道其中一个部分的数字的特征，然后让fast顺次去寻找这部分数据(目标数据)，只要碰到这样的数据，就将它交换到目标位置。目标位置是由 `slow` 来进行维护的(显然，每次往目标区域移入一个元素，slow也要move to next)。这样的做法能够保证目标数据的相对顺序保持不变。

具体来说:

- 对于    目标元素，slow和fast是同步走的(index同时加1), **自我交换**

- 对于非目标元素，fast是跨越过去，而slow则是停留

显然是**非目标元素**造成 slow 和 fast 的不同步，当两者不同步的时候，两者之间的就是**非目标元素**，slow指向的是**非目标元素**，fast指向的是**目标元素**，此时需要将两者进行交换

### 变式

将所有的0移到数组的头部。



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



