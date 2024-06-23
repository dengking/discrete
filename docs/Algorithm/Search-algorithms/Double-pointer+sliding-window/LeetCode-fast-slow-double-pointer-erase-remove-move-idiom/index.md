# LeetCode fast slow double pointer erase remove move idiom

## [LeetCode-27. 移除元素](https://leetcode.cn/problems/remove-element/)

用slow来表示非0区域(合法区域)，fast去probe(打探)



```C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	int removeElement(vector<int> &nums, int val)
	{
		int n = nums.size();
		int slow = 0, fast = 0;
		while (fast < n)
		{
			if (nums[fast] != val) // 需要保留的值
			{
				nums[slow] = nums[fast];
				++slow;
			}
			++fast;
		}
		return slow; // 需要注意，slow记录的是个数
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
	cout << s.removeElement(nums, 1) << endl;

	cout << nums << endl;
}
// g++ test.cpp -pedantic -Wall -Wextra --std=c++11

```





## 删除有序数组中的重复项系列



### [【宫水三叶】关于「删除有序数组重复项」的通解](https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/solutions/702970/gong-shui-san-xie-guan-yu-shan-chu-you-x-glnq/) 

为了让解法更具有一般性，我们将原问题 ([LeetCode-80. 删除排序数组中的重复项 II](https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/) ) 的「保留 2 位」修改为「保留 k 位」。

对于此类问题，我们应该进行如下考虑：

- 由于是保留 k 个相同数字，对于前 k 个数字，我们可以直接保留
- 对于后面的任意数字，能够保留的前提是：与当前写入的位置前面的第 k 个元素进行比较，不相同则保留

```python
from typing import *

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        def solve(k):
            slow = 0
            for x in nums: # fast
                if slow < k or nums[slow - k] != x:
                    nums[slow] = x
                    slow += 1
            return slow

        return solve(2)

```

> NOTE:
>
> 上述写法非常好，它本质也是fast slow double pointer

### [LeetCode-26. 删除有序数组中的重复项](https://leetcode.cn/problems/remove-duplicates-from-sorted-array/) 

1、在 labuladong  [双指针技巧秒杀四道数组/链表题目](https://mp.weixin.qq.com/s/55UPwGL0-Vgdh8wUEPXpMQ) 中发现的这道题

2、fast slow double pointer

slow保存有序、无重复的合法区域，fast不断去试探。

3、存在重复写的情况

#### C++

```C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	int removeDuplicates(vector<int> &nums)
	{
		int n = nums.size();
		if (n == 0)
		{
			return 0;
		}
		int slow = 0, fast = 1;
		while (fast < n)
		{
			if (nums[fast] != nums[slow])
			{
				++slow;
				nums[slow] = nums[fast];
			}
			++fast;
		}
		return slow + 1;
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
	cout << s.removeDuplicates(nums) << endl;

	cout << nums << endl;
}
// g++ test.cpp -pedantic -Wall -Wextra --std=c++11

```



#### Python

```python
from typing import *

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        slow, fast = 0, 1
        while fast < len(nums):
            if nums[slow] != nums[fast]:
                slow += 1
                nums[slow] = nums[fast]
            fast += 1
        return slow + 1

```



### [LeetCode-80. 删除排序数组中的重复项 II](https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/) 



#### Python1

```python

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        slow, fast = 0, 1
        while fast < len(nums):
            if nums[fast] != nums[slow]:
                slow += 1
                nums[slow] = nums[fast]
            else:
                if slow - 1 >= 0:
                    if nums[slow - 1] != nums[slow]:
                        slow += 1
                        nums[slow] = nums[fast]
                else:  # 第0个、第1个元素相等
                    slow += 1
            fast += 1
        return slow + 1

```



#### Python2

这是仿照 [【宫水三叶】关于「删除有序数组重复项」的通解](https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/solutions/702970/gong-shui-san-xie-guan-yu-shan-chu-you-x-glnq/) 写的

```python
from typing import *

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        def solve(k):
            slow = 0
            for x in nums: # fast
                if slow < k or nums[slow - k] != x:
                    nums[slow] = x
                    slow += 1
            return slow

        return solve(2)

```



## [LeetCode-283. 移动零](https://leetcode.cn/problems/move-zeroes/)

### [王尼玛](https://leetcode.cn/u/wang_ni_ma/) # [动画演示 283.移动零](https://leetcode.cn/problems/move-zeroes/solutions/90229/dong-hua-yan-shi-283yi-dong-ling-by-wang_ni_ma/) 

一次遍历:

这里参考了**快速排序**的思想，**快速排序**首先要确定一个待分割的元素做中间点 x(pivot)，然后把所有小于等于 x 的元素放到 x 的左边，大于 x 的元素放到其右边。这里我们可以用 0 当做这个中间点，把不等于 0(注意题目没说不能有负数)的放到中间点的左边，等于 0 的放到其右边。这的中间点就是 0 本身，所以实现起来比快速排序简单很多，我们使用两个指针 i 和 j，只要 `nums[i]!=0`，我们就交换 `nums[i]` 和 `nums[j]`，请对照动态图来理解：

我的理解:

这道题本质上是要将array划分为两个部分，显然，只要知道其中一个部分的数字的特征，然后让fast顺次去寻找这部分数据(目标数据)，只要碰到这样的数据，就将它交换到目标位置。目标位置是由 `slow` 来进行维护的(显然，每次往目标区域移入一个元素，slow也要move to next)。这样的做法能够保证目标数据的相对顺序保持不变。

具体来说:

- 对于    目标元素，slow和fast是同步走的(index同时加1), **自我交换**

- 对于非目标元素，fast是跨越过去，而slow则是停留

显然是**非目标元素**造成 slow 和 fast 的不同步，当两者不同步的时候，两者之间的就是**非目标元素**，slow指向的是**非目标元素**，fast指向的是**目标元素**，此时需要将两者进行交换

#### 变式

将所有的0移到数组的头部。



### C++



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



### Python

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
