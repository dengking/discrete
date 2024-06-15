# 删除有序数组中的重复项系列



## [【宫水三叶】关于「删除有序数组重复项」的通解](https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/solutions/702970/gong-shui-san-xie-guan-yu-shan-chu-you-x-glnq/) 

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

## [LeetCode-26. 删除有序数组中的重复项](https://leetcode.cn/problems/remove-duplicates-from-sorted-array/) 

1、在 labuladong  [双指针技巧秒杀四道数组/链表题目](https://mp.weixin.qq.com/s/55UPwGL0-Vgdh8wUEPXpMQ) 中发现的这道题

2、fast slow double pointer

slow保存有序、无重复的合法区域，fast不断去试探。

3、存在重复写的情况

### C++

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



### Python

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



## [LeetCode-80. 删除排序数组中的重复项 II](https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/) 



### Python1

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



### Python2

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

