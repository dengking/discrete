# leetcode [491. 递增子序列](https://leetcode-cn.com/problems/increasing-subsequences/) 中等



## LeetCode [官方解题](https://leetcode-cn.com/problems/increasing-subsequences/solution/di-zeng-zi-xu-lie-by-leetcode-solution/)

### 方法二：递归枚举 + 减枝

> NOTE: 
>
> 典型的子集树

我们也可以用递归的方法实现二进制枚举，像「方法一」那样枚举出所有的子序列，然后判断是否合法。直接把方法一变成递归形式，我们可以得到这样的代码：



```C++
class Solution
{
	vector<vector<int>> ans;
	vector<int> temp;
public:
	void dfs(int cur, vector<int> &nums)
	{
		if (cur == nums.size())
		{
			// 判断是否合法，如果合法判断是否重复，将满足条件的加入答案
			if (isValid() && notVisited())
			{
				ans.push_back(temp);
			}
			return;
		}
		// 如果选择当前元素
		temp.push_back(nums[cur]);
		dfs(cur + 1, nums);
		temp.pop_back();
		// 如果不选择当前元素
		dfs(cur + 1, nums);
	}
};
```

这是一个递归枚举子序列的通用模板，即用一个临时数组 $\rm temp$ 来保存当前选出的子序列，使用 $\rm cur$ 来表示当前位置的下标，在 `dfs(cur, nums)` 开始之前，$[0, {\rm cur} - 1]$ 这个区间内的所有元素都已经被考虑过，而 $[{\rm cur}, n]$ 这个区间内的元素还未被考虑。在执行 `dfs(cur, nums)` 时，我们考虑 ${\rm cur}$ 这个位置选或者不选，如果选择当前元素，那么把当前元素加入到 $\rm temp$ 中，然后递归下一个位置，在递归结束后，应当把 $\rm temp$ 的最后一个元素删除进行回溯；如果不选当前的元素，直接递归下一个位置。

当然，如果我们简单地这样枚举，对于每一个子序列，我们还需要做一次 $O(n)$ 的合法性检查和哈希判重复，在执行整个程序的过程中，我们还需要使用一个空间代价 $O(2^n)$ 的哈希表来维护已经出现的子序列的哈希值。我们可以对选择和不选择做一些简单的限定，就可以让枚举出来的都是合法的并且不重复：

一、使序列合法的办法非常简单，即给「选择」做一个限定条件，只有当前的元素大于等于上一个选择的元素的时候才能选择这个元素，这样枚举出来的所有元素都是合法的

二、那如何保证没有重复呢？我们需要给「不选择」做一个限定条件，只有当当前的元素不等于上一个选择的元素的时候，才考虑不选择当前元素，直接递归后面的元素。因为如果有两个相同的元素，我们会考虑这样四种情况：

1、前者被选择，后者被选择

2、前者被选择，后者不被选择

3、前者不被选择，后者被选择

4、前者不被选择，后者不被选择

