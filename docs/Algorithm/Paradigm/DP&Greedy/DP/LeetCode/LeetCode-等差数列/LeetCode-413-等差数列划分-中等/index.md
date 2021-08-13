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

> NOTE: 
>
> 一、这种思路还是动态规划的思路，需要从"divide-and-conquer-原问题和子问题"的思想来进行思考， $t_i$ 记录的是以第 $i$ 个元素结尾的等差子数组的个数，那如何根据  $t_i$ 推导出 $t_{i+1}$ 呢？
>
> 下面的回答对这个问题进行了解答。

如果我们已经求出了 $\textit{nums}[i - 1]$​ 以及 $\textit{nums}[i]$​ 作为等差数列的最后两项时，答案增加的次数 $t_i$​，那么能否快速地求出 $t_{i+1}$ 呢？

答案是可以的：

如果 $\textit{nums}[i] - \textit{nums}[i + 1] = d$，那么在这一轮遍历中，$j$ 会遍历到与上一轮相同的位置，答案增加的次数相同，并且额外多出了 $\textit{nums}[i-1], \textit{nums}[i], \textit{nums}[i+1]$ 这一个等差数列，因此有：

$$
t_{i+1} = t_{i} + 1
$$
如果 $\textit{nums}[i] - \textit{num}[i + 1] \neq d$，那么 $j$ 从初始值 $i-1$ 开始就会直接退出遍历，答案不会增加，因此有：
$$
t_{i+1} = 0
$$
这样一来，我们通过上述简单的递推，即可在 $O(1)$ 的时间计算等差数列数量的增量，总时间复杂度减少至 $O(n)$。

