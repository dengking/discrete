# LeetCode [413. 等差数列划分](https://leetcode-cn.com/problems/arithmetic-slices/) 中等

这个问题是典型的存在**重叠子问题**的: 

1、已知一个子数组的公差为`d`，如果一个新的元素与数组的最后一个元素的公差为`d`，那么它们就形成了一个更大的**等差子数组**。

例子是: `[1, 2, 3]` ，当新增一个元素 `4`，显然是可以形成一个更大的**等差子数组**。

2、已知一个子数组的公差为`d`，如果一个新的元素与数组的最后一个元素的公差**不**为`d`，那么它们就**无法**形成了一个更大的**等差子数组**。

例子是: `[1, 2, 3]` ，当新增一个元素 `5`，由于前面三个元素形成的子数组的公差`d`，下一个新的子数组应该是从前面的子数组的最后一个元素开始，即从`3`开始，显然，这是有助于我们缩小问题规模的。



对于存在重叠子问题的，我们在设计算法的时候，需要据此进行优化: 因此，一个直观的写法是: 保存当前的公差`d`。


## 我的解题-$O(N^3)$



```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int numberOfArithmeticSlices(vector<int> &nums)
	{
		int count = 0;
		int len = nums.size();
		for (int start = 0; start <= len - 3; ++start)
		{
			for (int end = start + 2; end < len; ++end)
			{
				bool match = true;
				int diff = nums[start] - nums[start + 1];
				for (int i = start + 1; i < end; ++i)
				{
					if (nums[i] - nums[i + 1] == diff)
					{
						continue;
					}
					else
					{
						match = false;
						break;
					}
				}
				if (match)
				{
					++count;
				}
			}
		}
		return count;
	}
};
int main()
{
	Solution s;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g


```

上述冗余计算在于: 每次都需要重新计算公差。

## 官方解题

### 方法一: 差分 + 计数-$O(N^2)$





### 优化: $O(N)$

