# LeetCode [446. 等差数列划分 II - 子序列](https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/) 困难



## 我的解题

### 回溯法

使用回溯法进行穷举:

```c++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int numberOfArithmeticSlices(vector<int> &nums)
	{
		int count = 0;
		vector<int> track;
		track.reserve(nums.size());
		backtrace(nums, count, 0, track);
		return count;
	}
	void backtrace(vector<int> &nums, int &count, int index, vector<int> &track)
	{
		if (index == nums.size())
		{
			if (track.size() >= 3)
			{
				++count;
			}

			return;
		}
		if (track.size() >= 2)
		{
			// 选择第index个数
			if (long(nums[index]) - track.back() == long(track[1]) - track[0])
			{
				track.push_back(nums[index]);
				backtrace(nums, count, index + 1, track);
				track.pop_back();
			}
			// 不选择第index个数
			backtrace(nums, count, index + 1, track);
		}
		else
		{
			// 选择第index个数
			track.push_back(nums[index]);
			backtrace(nums, count, index + 1, track);
			track.pop_back();
			// 不选择第index个数
			backtrace(nums, count, index + 1, track);
		}
	}
};

int main()
{
	Solution s;
	vector<int> nums { 2, 4, 6, 8, 10 };
	s.numberOfArithmeticSlices(nums);
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g


```

#### 运行结果

|                                                              | 用例                                                    |
| ------------------------------------------------------------ | ------------------------------------------------------- |
| [超出时间限制](https://leetcode-cn.com/submissions/detail/205600008/) | `[1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]` |
|                                                              |                                                         |
|                                                              |                                                         |



### 二进制枚举

这是无法实现的，因为从题目意思可知:

```C++
1  <= nums.length <= 1000
```

没有长度为1000位的整数类型；



## [官方解题](https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/solution/deng-chai-shu-lie-hua-fen-ii-zi-xu-lie-b-77pl/)

我们首先考虑至少有两个元素的**等差子序列**，下文将其称作**弱等差子序列**。

由于尾项和公差可以确定一个等差数列，因此我们定义状态 $f[i][d]$ 



## [【宫水三叶】详解如何分析「序列 DP」问题（附序列 DP 问题目录）](https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/solution/gong-shui-san-xie-xiang-jie-ru-he-fen-xi-ykvk/)

动态规划 + 容斥原理

既然分析出是序列 DP 问题，我们可以先猜想一个基本的状态定义，看是否能够「不重不漏」的将状态通过转移计算出来。如果不行，我们再考虑引入更多的维度来进行求解。

先从最朴素的猜想出发，定义 $f[i]$ 为考虑下标不超过 $i$的所有数，并且以 $nums[i]$ 为结尾的等差序列的个数。

