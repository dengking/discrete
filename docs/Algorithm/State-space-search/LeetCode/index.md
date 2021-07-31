# LeetCode试题

## 回溯法

一、[37. 解数独](https://leetcode-cn.com/problems/sudoku-solver/)

还未完成



二、N-皇后

LeetCode-51-N-皇后-Hard

LeetCode-52-N-皇后-II-Hard

LeetCode-面试题-08.12-八皇后



三、LeetCode [698-划分为k个相等的子集](https://leetcode-cn.com/problems/partition-to-k-equal-sum-subsets/)

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



四、 子集

[78. 子集](https://leetcode-cn.com/problems/subsets/) 中等



[90. 子集 II](https://leetcode-cn.com/problems/subsets-ii/) 中等



五、排列

[46. 全排列](https://leetcode-cn.com/problems/permutations/) 中等



## 二进制迭代枚举、穷举

下面是使用了二进制枚举的题目。

LeetCode [51. N 皇后](https://leetcode-cn.com/problems/n-queens/)

LeetCode [52. N皇后 II](https://leetcode-cn.com/problems/n-queens-ii/)

LeetCode [37. 解数独](https://leetcode-cn.com/problems/sudoku-solver/)



#### LeetCode [77. 组合](https://leetcode-cn.com/problems/combinations/)

非递归（字典序法）实现组合型枚举

> NOTE: 
>
> 这道题是非常典型的



#### LeetCode [78. 子集](https://leetcode-cn.com/problems/subsets/)

> NOTE: 
>
> 非常典型，非常巧妙



#### LeetCode [90. 子集 II](https://leetcode-cn.com/problems/subsets-ii/)

回答: [【宫水三叶】一题双解：「回溯」&「状态压缩」解法](https://leetcode-cn.com/problems/subsets-ii/solution/gong-shui-san-xie-yi-ti-shuang-jie-hui-s-g77q/)

值得一读



## 对重复元素的处理

处理方法:

通过排序将重复元素放到一起，将重复元素看做是同一个元素，然后判断相邻的相同元素



下面两道题都是与重复元素有关的:

#### LeetCode [90. 子集 II](https://leetcode-cn.com/problems/subsets-ii/)



#### LeetCode [47. 全排列 II](https://leetcode-cn.com/problems/permutations-ii/)

