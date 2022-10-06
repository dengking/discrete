# [LeetCode-47. 全排列 II](https://leetcode.cn/problems/permutations-ii/)



## 我的分析

### 不能够简单地将重复元素看做是一个整体

```C++
[1,2,2]
```

不能够简单地将所有的重复元素看做是一个整体，因为存在如下的可能性:

```c++
[2, 1, 2]
```



## 重复的情况(需要剪枝)



### 最最基本的情况

| 情况一 | 重复   |
| ------ | ------ |
| `122'` | `12'2` |
| `212'` | `2'12` |



### 一些比较复杂的情况

| 情况1     | 情况2(重复) | 情况3(重复) |
| --------- | ----------- | ----------- |
| `122'2''` | `12'22''`   | `12''2'2`   |



## 解题思路

观察上面的"重复的情况"，自然而然的思路是: 在所有的情况中选择一个，将其他重复的情况剪枝掉；那问题是: 如何来进行有效的甄别？

下面是我根据[LeetCode-[HOT 100]47.全排列II Python3 回溯 考虑重复 --> 46.全排列](https://leetcode.cn/problems/permutations-ii/solution/hot-100-47quan-pai-lie-ii-python3-hui-su-kao-lu-zh/) 、LeetCode [官方解题](https://leetcode.cn/problems/permutations-ii/solution/quan-pai-lie-ii-by-leetcode-solution/) 、LeetCode [90. 子集 II](https://leetcode.cn/problems/subsets-ii/) 中的思路所总结的: 

一、[LeetCode-[HOT 100]47.全排列II Python3 回溯 考虑重复 --> 46.全排列](https://leetcode.cn/problems/permutations-ii/solution/hot-100-47quan-pai-lie-ii-python3-hui-su-kao-lu-zh/) 和 LeetCode [官方解题](https://leetcode.cn/problems/permutations-ii/solution/quan-pai-lie-ii-by-leetcode-solution/) 中，给出的去重的思路其实和 LeetCode [90. 子集 II](https://leetcode.cn/problems/subsets-ii/) 中的思路是非常类似的:

> 选择 `10` 模式，剪枝 `01` 模式(即当前元素和上一个元素相同，并且上一个元素没有被选中)

二、对于重复的元素，通过排序，让它们成为相邻的元素；

通过 `vis` 来记录它们被选中的状态；

三、只选择 "情况一"，即 `122'` 、`212'` 、`122'2''`  

在 [LeetCode-[HOT 100]47.全排列II Python3 回溯 考虑重复 --> 46.全排列](https://leetcode.cn/problems/permutations-ii/solution/hot-100-47quan-pai-lie-ii-python3-hui-su-kao-lu-zh/) 中，对此有着非常好的总结:

> 首先我们得使用**第一个元素**，因为这时候是第一次使用，还没有重复，并且所有情况都回溯搜索答案，除了用过的元素不再使用，其余不做剪枝，直到我们遇到第一个重复元素，我们才要考虑剪枝，但是考虑剪枝的时候还要考虑跟它重复的元素有没有被用过



## [官方解题](https://leetcode.cn/problems/permutations-ii/solution/quan-pai-lie-ii-by-leetcode-solution/)

> NOTE: 
>
> 官方解题给出的是"抽取法"算法来生成排列



```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
	vector<int> vis;

public:
	void backtrack(vector<int> &nums, vector<vector<int>> &ans, int idx, vector<int> &perm)
	{
		if (idx == nums.size())
		{
			ans.emplace_back(perm);
			return;
		}
		for (int i = 0; i < (int) nums.size(); ++i)
		{
			if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1]))
			{
				continue;
			}
			perm.emplace_back(nums[i]);
			vis[i] = 1;
			backtrack(nums, ans, idx + 1, perm);
			vis[i] = 0;
			perm.pop_back();
		}
	}

	vector<vector<int>> permuteUnique(vector<int> &nums)
	{
		vector<vector<int>> ans;
		vector<int> perm;
		vis.resize(nums.size());
		sort(nums.begin(), nums.end());
		backtrack(nums, ans, 0, perm);
		return ans;
	}
};

int main()
{
	Solution s;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g

```



## [LeetCode-[HOT 100]47.全排列II Python3 回溯 考虑重复 --> 46.全排列](https://leetcode.cn/problems/permutations-ii/solution/hot-100-47quan-pai-lie-ii-python3-hui-su-kao-lu-zh/)

> NOTE: 
>
> 在生成排列的时候，就将重复的剪枝掉

重复即为：存在相同数字，比如 [1,2,2']，那么答案 [1,2,2'] 和 [1,2',2] 就其实是一样的，在保存结果的时候，我们只选择其一，但是这不是字符串，在保存结果的时候再去判断是否答案里已经保存了这一种情况会比较麻烦，那么我们能不能在生成答案的过程中就将其 剪枝（类比用过的数字就不考虑），这样根本就不会生成重复的答案了。

我们希望的是，如果发现数字重复了，当前的就不考虑了，比如 [1,2,2'] 存在之后，当遇到 [1] 遇到 2'，发现和 2 重复了，我就直接剪枝，不考虑之后的所有的情况，因为：

![image.png](https://pic.leetcode.cn/b99f92354583b0dbf289b180da5527ea5d71b26ca81f83229d7d96ab96c8b6ff-image.png)

> NOTE: 
>
> 上述红线圈出来的就是 `10` 和 `01` 模式，它的去重思路和 [LeetCode-90. 子集 II](https://leetcode.cn/problems/subsets-ii/) 中的思路是非常类似的:
>
> > 选择 `10` 模式，剪枝 `01` 模式(即当前元素和上一个元素相同，并且上一个元素没有被选中)
>
> 

两个相同数字，我可以：

1、两个都选 ( `11` )

2、两个都不选 ( `00` )

3、但是如果只选一个，那么选哪一个都可以，因为和选择另一个是相同情况，**所以只有这种情况我们需要剪枝**

### 又到了小 trick 时间：

**考虑重复元素一定要优先排序**，将重复的都放在一起，便于找到**重复元素**和**剪枝**！！！

推广至 --> **如果涉及考虑重复元素，或者大小比较的情况，对列表排序是一个不错的选择**

好了，我们知道要排序，重复元素要剪枝，那么该如何剪枝呢？

首先我们得使用**第一个元素**，因为这时候是第一次使用，还没有重复，并且所有情况都回溯搜索答案，除了用过的元素不再使用，其余不做剪枝，直到我们遇到第一个重复元素，我们才要考虑剪枝，但是考虑剪枝的时候还要考虑跟它重复的元素有没有被用过：

![image.png](https://pic.leetcode.cn/411c88e56c5538a787b4bd4c86d433f00a461d93c0af8ca3a74d7bed41055c34-image.png)

如果前一个重复元素没有使用过，那么在当前重复元素下一层的可选项中一定会存在，也就是绿色部分
那么一定会重复，即出现 2 X = X 2' 的情况（X为不选）
也就是2和2' 以及 2'和2一定会重复，则整体剪枝，且是提前剪枝，在红色选择处就剪枝

那么这部分剪枝的条件即为：**和前一个元素值相同（此处隐含这个元素的index>0），并且前一个元素还没有被使用过**



## 我的解题

```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
	vector<vector<int>> m_res; // 最终结果
	vector<int> m_vis; // 第 i 个元素是否放入到了排列中
	vector<int> m_track; //
public:
	vector<vector<int>> permuteUnique(vector<int> &nums)
	{
		m_vis.resize(nums.size(), 0);
		m_track.resize(nums.size());
		sort(nums.begin(), nums.end());
		backtrace(0, nums);
		return m_res;
	}
private:
	void backtrace(int index, vector<int> &nums)
	{
		int len = nums.size();
		if (index == len)
		{
			m_res.push_back(m_track);
		}
		else
		{
			for (int i = 0; i < len; ++i)
			{
				if ((i > 0) && (nums[i] == nums[i - 1]) && (!m_vis[i - 1]))
				{
					continue;
				}
				if (m_vis[i])
				{
					continue;
				}
				m_vis[i] = 1;
				m_track[index] = nums[i];
				backtrace(index + 1, nums);
				m_vis[i] = 0; // 回溯
			}
		}
	}
};

template<typename ...Args>
ostream& operator <<(ostream &stream, const vector<Args...> &v)
{
	for (auto &&i : v)
	{
		stream << i << endl;
	}
	return stream;
}

int main()
{
	Solution s;
	vector<int> nums { 1, 1, 2 };
	cout << s.permuteUnique(nums) << endl;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g


```

