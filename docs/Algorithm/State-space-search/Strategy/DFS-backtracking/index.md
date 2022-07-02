# DFS-backtracking

"Backtracking"即"回溯法"，除了本章，在下面章节中，也对它进行了论述:

一、`Expert-labuladong\3.1-回溯算法(DFS算法)系列`

> 再看看回溯算法，前文 [回溯算法详解](http://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484709&idx=1&sn=1c24a5c41a5a255000532e83f38f2ce4&chksm=9bd7fb2daca0723be888b30345e2c5e64649fc31a00b05c27a0843f349e2dd9363338d0dac61&scene=21#wechat_redirect) 干脆直接说了，回溯算法就是个 N 叉树的前后序遍历问题，没有例外。

上面这段话其实总结得不错，回溯法就是树的 "深度优先遍历+先序+后序"

先序: 

1、判断是否搜索到了一个解

2、有借

后序:

1、有还

## LeetCode习题汇总

### 解数独系列

[LeetCode-37-解数独](https://leetcode.cn/problems/sudoku-solver/)



### N-皇后系列

LeetCode-51-N-皇后-Hard

LeetCode-52-N-皇后-II-Hard

LeetCode-面试题-08.12-八皇后



### 子集划分系列

[LeetCode-698-划分为k个相等的子集](https://leetcode.cn/problems/partition-to-k-equal-sum-subsets/)

```C++
class Solution
{
	int m_k { 0 }; // 桶的个数
	vector<int> m_buckets; // 所有的桶
	int m_target { 0 }; // 每个桶的目标装载量
public:
	bool canPartitionKSubsets(vector<int> &nums, int k)
	{
		int len = nums.size();
		m_k = k;
		if (m_k > len)
		{
			return false;
		}
		int sum = accumulate(nums.begin(), nums.end(), 0);

		if (sum % m_k != 0) // 无法均匀分配
			return false;
		m_target = sum / m_k;
		m_buckets.resize(k, 0); // 桶
		sort(nums.begin(), nums.end(), greater<int>()); // 降序
		return DFS(0, nums);
	}
	bool DFS(int index, vector<int> &nums)
	{
		if (index == nums.size()) // 所有的数都放完了
		{
			for (auto &&i : m_buckets)
			{
				if (i != m_target)
				{
					return false;
				}
			}
			return true;
		}
		for (int j = 0; j < m_k; ++j)
		{
			if (nums[index] + m_buckets[j] > m_target) // 第i个数，不应当放入 m_buckets[j] 中
				continue;
			m_buckets[j] += nums[index];
			if (DFS(index + 1, nums))
			{
				return true;
			}
			m_buckets[j] -= nums[index];
		}
		return false;
	}
};
```



### 子集系列

[LeetCode-78-子集-中等](https://leetcode.cn/problems/subsets/)

[LeetCode-90-子集-II-中等](https://leetcode.cn/problems/subsets-ii/) 



### 排列系列

[46. 全排列](https://leetcode.cn/problems/permutations/) 中等



### 查找、穷举所有的可能性

这类题目，章节要求查找所有的可能性，最直接的方法就是回溯法；

1、LeetCode [39. 组合总和](https://leetcode.cn/problems/combination-sum/) 中等

2、LeetCode [491. 递增子序列](https://leetcode.cn/problems/increasing-subsequences/) 中等





## 如何避免回溯

如何避免回溯？下面结合了例子进行了说明：

- KMP算法: https://www.cnblogs.com/dusf/p/kmp.html





## geeksforgeeks [top-20-backtracking-algorithm-interview-questions](https://www.geeksforgeeks.org/top-20-backtracking-algorithm-interview-questions/)



### Pattern Searching

在字符串（也叫主串）中的定位模式（pattern）问题可以使用回溯法进行解决，但是这种解法是naive的。优化方法是KMP算法，在下面两篇文章中对两种进行了比较分析：

1、cnblogs [详解KMP算法](https://www.cnblogs.com/yjiyjige/p/3263858.html)



### [Eight queens puzzle](https://en.wikipedia.org/wiki/Eight_queens_puzzle)



### [Crosswords](https://en.wikipedia.org/wiki/Crosswords)



### [Verbal arithmetic](https://en.wikipedia.org/wiki/Verbal_arithmetic)



### [Sudoku](https://en.wikipedia.org/wiki/Algorithmics_of_sudoku)



### [Parsing](https://en.wikipedia.org/wiki/Parsing) 

> NOTE:
>
> 参见[*Compilers: Principles, Techniques, and Tools*](https://en.wikipedia.org/wiki/Compilers:_Principles,_Techniques,_and_Tools)的4.4 Top-Down Parsing，其中介绍了使用backtrack来实现parsing。
>
> 在GitHub中，可以检索非常多的这种项目：
>
> https://github.com/search?utf8=%E2%9C%93&q=backtrack+parse&type=

